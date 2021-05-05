#!/usr/bin/python3
""" 0. Count it! mandatory
Write a recursive function that queries the Reddit API,
parses the title of all hot articles, and prints a
sorted count of given keywords (case-insensitive,
delimited by spaces. Javascript should count as
javascript, but java should not).
Requirements:
    Prototype: def count_words(subreddit, word_list)
    Note: You may change the prototype, but it must be
    able to be called with just a subreddit supplied
    and a list of keywords. AKA you can add a counter
    or anything else, but the function must work without
    supplying a starting value in the main.
    If word_list contains the same word (case-insensitive),
    the final count should be the sum of each duplicate
    (example below with java)
    Results should be printed in descending order,
    by the count, and if the count is the same for
    separate keywords, they should then be sorted
    alphabetically (ascending, from A to Z). Words with
    no matches should be skipped and not printed.
    Words must be printed in lowercase.
    Results are based on the number of times a keyword
    appears, not titles it appears in. java java
    java counts as 3 separate occurrences of java.
    To make life easier, java. or
    java! or java_ should not count as java
    If no posts match or the subreddit is invalid,
    print a newline.
    NOTE: Invalid subreddits may return a redirect to
    search results. Ensure that you are NOT
    following redirects.
Your code will NOT pass if you are using a loop and not
recursively calling the function! This /can/ be done
with a loop but the point is to use a
recursive function. :)
Disclaimer: number presented in this example cannot
be accurate now - Reddit is hot
articles are always changing."""
import requests
import pprint
import re


def count_words(subreddit, word_list, hot=[], after=None):
    """
    recursive function that queries the Reddit API,
    https://www.reddit.com/dev/api
    """
    meta = {'User-agent': 'Unix:0-subs:v1'}
    query = {'limit': 100}

    if isinstance(after, str):
        if after != "STOP":
            query['after'] = after
        else:
            return show_results(word_list, hot)

    response = requests.get(
                            'http://reddit.com/r/{}/hot.json'.format(
                                subreddit),
                            headers=meta, params=query)
    if response.status_code != 200:
        return None
    data = response.json().get('data', {})
    after = data.get('after', 'STOP')
    if not after:
        after = "STOP"
    hot = hot + [post.get('data', {})
                 .get('title') for post in data.get('children', [])]
    return count_words(subreddit, word_list, hot, after)


def show_results(word_list, hot):
    """
    show results
    """
    i = {}
    for item in word_list:
        i[item] = 0
    for title in hot:
        for item in word_list:
            for tw in title.lower().split():
                if tw == item.lower():
                    i[item] += 1

    i = {k: v for k, v in i.items() if v > 0}
    items = list(i.keys())
    for item in sorted(items, reverse=True,
                       key=lambda k: i[k]):
        print("{}: {}".format(item, i[item]))

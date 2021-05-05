#!/usr/bin/python3
""" simple comment """
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

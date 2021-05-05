#!/usr/bin/python3

""" Recursive function that queries the Reddit API"""

import requests


def count_words(subreddit, word_list, after='', words_counting={}):
    """ Recursive function that queries the Reddit API"""
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    h = {'User-Agent': 'python3:holberton.task:v1.0'}
    payload = {'limit': '100', 'after': after}
    r = requests.get(url, headers=h, params=payload, allow_redirects=False)
    if r.status_code == 200:
        data = r.json().get('data')
        after = data.get('after')
        children = data.get('children')
        for child in children:
            title = child.get('data').get('title')
            for word in word_list:
                ocurrences = title.lower().split().count(word.lower())
                if ocurrences > 0:
                    if word in words_counting:
                        words_counting[word] += ocurrences
                    else:
                        words_counting[word] = ocurrences

        if after is not None:
            return count_words(subreddit, word_list, after, words_counting)
        else:
            if not len(words_counting) > 0:
                return
            datas = sorted(words_counting.items(),
                           key=lambda key_value: (-key_value[1], key_value[0]))
            for key, value in datas:
                print('{}: {}'.format(key.lower(), value))
    else:
        return

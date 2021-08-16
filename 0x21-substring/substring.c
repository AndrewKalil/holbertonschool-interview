#include "substring.h"
/**
 * comp_values - Function that compares two values
 * @a: pointer to the first value
 * @b: pointer to the second value
 * Return: comparison
 **/
int comp_values(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}
/**
 * check_words - Function that checks if all words are continous
 * @aux_indx: pointer to array with index for ever word
 * @wordlen: word size
 * @idx_len: aux_indx size
 * Return: index firt word or zero
 **/
int check_words(int *aux_indx, int wordlen, int idx_len)
{
	int i;

	for (i = 0; i < idx_len - 1; i++)
	{
		if (aux_indx[i + 1] - aux_indx[i] != wordlen)
			return (0);
	}
	return (1);
}
/**
 * search_word - Function that search words in string
 * @s: pointer to string base
 * @words: array of words to search in the string
 * @nb_words: number of words
 * Return: array with size of substring for every word, otherwise NULL
 **/
int *search_word(char const *s, char const **words, int nb_words)
{
	int *aux_indx, i, j;
	char *aux;
	int len;

	aux_indx = malloc((sizeof(int) * nb_words));
	if (!aux_indx)
		return (NULL);
	for (i = 0; i < nb_words; i++)
	{
		aux = strstr(s, words[i]);
		if (!aux)
		{
			free(aux_indx);
			return (NULL);
		}
		len = (int)strlen(aux);
		for (j = 0; j < i; j++)
		{
			if (len == aux_indx[j])
			{
				aux = strstr(s + (int)strlen(s) - len + 1, words[i]);
				if (!aux)
				{
					free(aux_indx);
					return (NULL);
				}
				len = (int)strlen(aux);
				aux_indx[i] = len;
				continue;
			}
		}
		aux_indx[i] = len;
	}
	return (aux_indx);
}
/**
 * find_substring - Function that finds all the possible substrings
 * containing a list of words, within a given string.
 * @s: is the string to scan
 * @words: is the array of words all substrings must be a
 * concatenation arrangement of
 * @nb_words: is the number of elements in the array words
 * @n: holds the address at which to store the
 * number of elements in the returned array.
 * Return: an allocated array, storing each index in s, at which a
 * substring was found. If no solution is found, NULL can be returned
 *
 **/
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *indx, *aux_indx, wordlen, j, diff, s_len, f_indx, tmp;

	*n = 0;
	wordlen = (int)strlen(words[0]);
	s_len = (int)strlen(s);
	for (j = 0; j < s_len; j++)
	{
		aux_indx = search_word(s, words, nb_words);
		if (!aux_indx)
			break;
		qsort(aux_indx, nb_words, sizeof(int), comp_values);
		f_indx = check_words(aux_indx, wordlen, nb_words);
		tmp = aux_indx[nb_words - 1];
		free(aux_indx);
		if (f_indx == 1)
		{
			diff = s_len - tmp;
			if (*n == 0 || diff != indx[*n - 1])
			{
				if (*n == 0)
				{
					indx = malloc((sizeof(int)));
					if (!indx)
						return (NULL);
				}
				else
					indx = realloc(indx, sizeof(int) * (*n + 1));
				indx[*n] = diff;
				*n += 1;
			}
		}
		s++;
	}
	if (*n == 0)
		return (NULL);
	return (indx);
}

#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a number is a palindrome.
 * @n: unsigned long number
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(unsigned long n)
{
	int A[99999], i = 0, j;

	if (n / 10 == 0)
		return (1);

	while (n != 0)
	{

		A[i] = n % 10;
		n = n / 10;
		i++;
	}
	i--;

	for (j = 0; j <= i; ++j)
	{
		if (A[i] != A[j])
		return (0);
		i--;
	}
	return (1);
}

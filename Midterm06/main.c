#include <stdio.h>
#include <ctype.h>
#include <string.h>

int x_to_the_n (int x, int n)
{
	long int result = x;
	int i;
	for (i = 1; i <= (n-1); ++i)
	{
		result *= x;
	}
	return (result);
} /* end function */

int main()
{
	long int exponent;
	int x = 5;
	int n = 2;
	char char_val;
	exponent = x_to_the_n (x, n);
	printf("The result of %i raised to %i is: %li", x, n, exponent);
	//printf ("%c \n", char_val = 'a' + 6);
	return 0;
}
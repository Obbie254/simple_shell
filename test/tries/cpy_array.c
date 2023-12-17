#include "main.h"

/**
 * cpy_array - copies memory area
 * @dest: output string
 * @src: input string
 *
 * Return: void
 */
void cpy_array(char **dest, char **src)
{
	unsigned int t, n;

	n = sizeof(src);
	for (t = 0; t < n; t++)
		*dest[t] = *src[t];
}

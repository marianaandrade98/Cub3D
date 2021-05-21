#include "cub3d.h"

void	*ft_calloc(int count, int size)
{
	unsigned char	*ptr;
	int				i;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < count * size)
		*(ptr + i++) = 0;
	return ((void *)ptr);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/*
** Convert char to int (n)
** Multiply the n by 10 to add a 0 and then sum the next digit
** example n(1) = 1 * 10 + 9; In the end returns the 19
*/

int	a2n(char *s)
{
	int	n;

	n = 0;
	while (*s <= ' ')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		n = n * 10 + *s - '0';
		s++;
	}
	return (n);
}

char	*rmempty(char *pline)
{
	int		i;
	int		nb_spaces;
	char	*new_pline;

	nb_spaces = 0;
	i = 0;
	while (pline[i])
	{
		if (pline[i] <= ' ')
			nb_spaces++;
		i++;
	}
	if (!(new_pline = malloc((ft_strlen(pline)
		- nb_spaces + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (*pline)
	{
		if (*pline > ' ')
			new_pline[i++] = *pline;
		pline++;
	}
	new_pline[i] = '\0';
	return (new_pline);
}

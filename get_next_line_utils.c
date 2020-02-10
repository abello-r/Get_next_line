/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abello-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 19:08:26 by abello-r          #+#    #+#             */
/*   Updated: 2020/02/09 19:08:39 by abello-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 ** La funcion FT_STRDUP, crea una nueva string y le asigna memoria con malloc
 ** (x), luego (x) recibe los valores de (s1), y se le agrega '\0' al final.
*/

char	*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		i;

	i = ft_strlen(s1);
	if (!(s2 = malloc(i + 1)))
		return (NULL);
	ft_memcpy(s2, s1, i);
	s2[i] = '\0';
	return (s2);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*
** la funcion FT_SUBSTR, crea una nueva string con malloc (x) y luego
** empieza a guardar los valores de (s) empezando desde s[start] hasta
** s[len] y al final de (x) se agrega '\0'.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*x;
	size_t		i;

	i = 0;
	if (!s)
		return (NULL);
	if (*s == '\0')
		return (ft_strdup(""));
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (!(x = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (i < len)
	{
		x[i] = s[start + i];
		i++;
	}
	x[i] = '\0';
	return (x);
}

/*
** la funcion FT_STRJOIN, crea una nueva string (x) como
** resultado de la concatenacion de la (s1) con la (s2) y
** agregando '\0' al final de (x).
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*x;
	size_t		c1;
	size_t		c2;
	size_t		i;

	i = 0;
	c2 = ft_strlen(s1);
	c1 = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(x = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (c1 != c2)
	{
		x[i] = s1[c1];
		++i && ++c1;
	}
	c2 = 0;
	c1 = ft_strlen(s2);
	while (c2 != c1)
		x[i++] = s2[c2++];
	x[i] = '\0';
	return (x);
}

/*
** la funcion FT_MEMCPY, copia los caracteres de (src) en (dst)
** hasta llegar a (n).
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (n == 0 || dst == src)
		return (dst);
	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

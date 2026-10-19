/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalrofat <aalrofat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:38:33 by aalrofat          #+#    #+#             */
/*   Updated: 2025/12/02 12:38:57 by aalrofat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_strings(char const *s, char c)
{
	size_t	everystr;
	size_t	x;

	x = 0;
	everystr = 0;
	while (s[x] != '\0')
	{
		while (s[x] == c)
			x++;
		if (s[x] != '\0' && s[x] != c)
		{
			everystr++;
			while (s[x] != '\0' && s[x] != c)
				x++;
		}
	}
	return (everystr);
}

static char	*copy_string(char const *s, size_t sw, size_t y)
{
	char	*string;
	size_t	i;

	string = (char *)malloc(((y - sw) + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	i = 0;
	while (i < y - sw)
	{
		string[i] = s[sw + i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

static void	free_split(char **splitarray, size_t x)
{
	while (x > 0)
	{
		x--;
		free(splitarray[x]);
	}
	free(splitarray);
}

static char	**storage_string(char const *s, char c, char **splitarray)
{
	size_t	sw;
	size_t	y;
	size_t	x;

	y = 0;
	x = 0;
	while (s[y] != '\0')
	{
		while (s[y] == c)
			y++;
		if (s[y] != '\0' && s[y] != c)
		{
			sw = y;
			while (s[y] != '\0' && s[y] != c)
				y++;
			splitarray[x] = copy_string(s, sw, y);
			if (splitarray[x] == NULL)
			{
				return (free_split(splitarray, x), NULL);
			}
			x++;
		}
	}
	splitarray[x] = NULL;
	return (splitarray);
}

char	**ft_split(char const *s, char c)
{
	char	**splitarray;

	if (s == NULL)
		return (NULL);
	splitarray = (char **)malloc((count_strings(s, c) + 1) * sizeof(char *));
	if (splitarray == NULL)
		return (NULL);
	return (storage_string(s, c, splitarray));
}
/*int main()
{
    char    s1[] = "Hell oguyse veryone";
    char    c1 = ' ';
    char **splitstr1 = ft_split(s1, c1);
    for (int f = 0; splitstr1[f] != NULL; f++)
	{
		printf("%s\n", splitstr1[f]);
		free (splitstr1[f]);
	}
	free (splitstr1);
}*/

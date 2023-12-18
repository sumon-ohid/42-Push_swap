/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 07:40:56 by sumon             #+#    #+#             */
/*   Updated: 2023/12/18 21:21:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_counter(char const *s, char c)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			x++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (x);
}

char	**ft_split(char const *s, char c)
{
	char	**s_split;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	s_split = (char **)malloc(sizeof(char *) * (ft_counter(s, c) + 1));
	if (s_split == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			k = i;
			while (s[k] && s[k] != c)
				k++;
			s_split[j] = (char *)malloc(sizeof(char) * (k - i + 1));
			if (s_split[j] == NULL)
			{
				free(s_split);
				return (NULL);
			}
			k = 0;
			while (s[i] && s[i] != c)
				s_split[j][k++] = s[i++];
			s_split[j][k] = '\0';
			j++;
		}
		else
			i++;
	}
	s_split[j] = NULL;
	return (s_split);
}

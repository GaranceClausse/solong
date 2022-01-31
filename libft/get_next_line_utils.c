/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gclausse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:52:57 by gclausse          #+#    #+#             */
/*   Updated: 2022/01/21 13:18:00 by gclausse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*cpy;

	i = -1;
	j = 0;
	if (!s2)
		return (NULL);
	if (s1 == NULL)
	{
		cpy = ft_strdup(s2);
		return (cpy);
	}
	cpy = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!cpy)
		return (NULL);
	while (s1[++i])
		cpy[i] = s1[i];
	while (s2[j])
		cpy[i++] = s2[j++];
	cpy[i] = '\0';
	free (s1);
	return (cpy);
}

char	*ft_strdup(char *s1)
{
	int		i;
	int		len;
	char	*cpy;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	cpy = malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

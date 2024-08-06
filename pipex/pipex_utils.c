/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpouille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:04:40 by lpouille          #+#    #+#             */
/*   Updated: 2023/09/12 15:04:42 by lpouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	s3 = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s3 == NULL)
		return (NULL);
	while (s1 != NULL && s1[++j] != '\0')
		s3[++i] = s1[j];
	j = -1;
	while (s2 != NULL && s2[++j] != '\0')
		s3[++i] = s2[j];
	s3[++i] = '\0';
	return (s3);
}

int	find_path(char **env)
{
	int	count;
	int	count2;

	count = 0;
	while (env[count])
	{
		count2 = 0;
		while (env[count][count2])
		{
			if (env[count][count2] == 'P' && env[count][count2 + 1] == 'A'
				&& env[count][count2 + 2] == 'T')
				return (count);
			count2++;
		}
		count++;
	}
	return (0);
}

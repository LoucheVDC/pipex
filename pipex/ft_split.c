/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpouille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:16:28 by lpouille          #+#    #+#             */
/*   Updated: 2023/09/12 15:16:28 by lpouille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*i1;
	unsigned int	i;

	i = 0;
	i1 = dest;
	while (*i1 != '\0')
		i1++;
	while (i < nb && src[i] != '\0')
	{
		i1[i] = src[i];
		i++;
	}
	i1[i] = '\0';
	return (dest);
}

int	ft_is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *charset, int *len)
{
	char	*it;
	int		i;
	int		j;

	it = str;
	i = 0;
	j = 1;
	*len = 0;
	while (*it)
	{
		if (!ft_is_sep(*it, charset))
		{
			*len = *len + 1;
			j = 0;
		}
		else
			if (j == 0)
				break ;
		it++;
	}
	return (it - *len);
}

int	count_w(char *str, char *charset)
{
	int		i;
	int		j;
	char	*it;

	it = str;
	i = 0;
	j = 1;
	while (*it)
	{
		if (!ft_is_sep(*it, charset))
		{
			i = i + j;
			j = 0;
		}
		else
			j = 1;
		it++;
	}
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		len;
	char	**splited;
	char	*it;

	i = count_w(str, charset);
	j = 0;
	splited = malloc(sizeof(char *) * (i + 1));
	while (j < i)
	{
		it = ft_strstr(str, charset, &len);
		splited[j] = malloc(sizeof(char) * (len + 1));
		ft_strncat(splited[j], it, len);
		str = it + len;
		j++;
	}
	splited[j] = NULL;
	return (splited);
}

/*
int main(int argc, char **argv,char **envp)
{
	char **chemin;
	int a = 0;
	chemin = ft_split(argv[1] , " ");
	while (a != 2)
	{
		printf("%s\n",chemin[a]);
		a++;
	}
	return 0;
}
*/
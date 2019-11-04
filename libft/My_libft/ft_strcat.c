/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 11:33:19 by rdiederi          #+#    #+#             */
/*   Updated: 2018/06/15 12:12:50 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	index;
	size_t	dest_len;
	size_t	src_len;

	index = 0;
	dest_len = ft_strlen(s1);
	src_len = ft_strlen(s2);
	while (index <= src_len || index <= dest_len)
	{
		s1[dest_len + index] = s2[index];
		++index;
	}
	return (s1);
}

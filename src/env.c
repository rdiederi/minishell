/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <rdiederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:41:42 by rdiederi          #+#    #+#             */
/*   Updated: 2018/09/18 16:01:38 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_d_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		ft_printf("%s\n", arr[i]);
		i++;
	}
}

int		arr_len(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char		**init_env(char **old_env, char **new_env)
{
	int		len_1;
	int		i;

	i = 0;
	len_1 = arr_len(old_env);
	if (!(new_env = (char **)malloc(sizeof(char *) * (len_1))))
		return (0);
	while (old_env[i])
	{
		new_env[i] = ft_strdup(old_env[i]);
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}

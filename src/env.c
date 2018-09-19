/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <rdiederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:41:42 by rdiederi          #+#    #+#             */
/*   Updated: 2018/09/19 15:48:23 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_d_arr()
{
	int i;

	i = 0;
	while (g_env[i])
	{
		ft_printf("%s\n", g_env[i]);
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

void	init_env(char **old_env)
{
	int		len_1;
	int		i;

	i = 0;
	len_1 = arr_len(old_env) + 1;
	g_env = (char **)malloc(sizeof(char *) * (len_1));
	while (old_env[i])
	{
		g_env[i] = ft_strdup(old_env[i]);
		i++;
	}
	g_env[i] = NULL;
}

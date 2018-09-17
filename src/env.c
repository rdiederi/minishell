/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <rdiederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:41:42 by rdiederi          #+#    #+#             */
/*   Updated: 2018/09/17 16:53:25 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_d_arr(char **arr)
{
	int i = 0;
	while (arr[i])
	{
		ft_printf("******************************************************\n");
		ft_printf("%s\n", arr[i]);
		ft_printf("******************************************************\n");
		i++;
	}
}

int	arr_len(char **arr)
{
	int i = 0;

	ft_printf("******************************************************\n");
	ft_printf("Main Second Error\n");
	ft_printf("******************************************************\n");
	while (arr[i] != NULL)
		i++;
	return (i);
}

int init_env(char **old_emv)
{
	char	**new_env;
	int		len_1;
	int		i;

	i = 0;
	print_d_arr(old_emv);
	len_1 = arr_len(new_env);
	if (!(new_env = (char **)malloc(sizeof(char *) * (len_1))))
		return (0);
	while (old_emv[i])
	{
		new_env[i] = ft_strdup(old_emv[i]);
		i++;
	}
	new_env[i] = NULL;
	return (1);
}

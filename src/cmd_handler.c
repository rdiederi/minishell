/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <rdiederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:46:42 by rdiederi          #+#    #+#             */
/*   Updated: 2018/09/19 18:13:36 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int		while_u_len(char *str)
{
	int i;

	i = 0;
	while (ft_isupper(str[i]))
		i++;
	return (i);
}

static int		new_env(char **parsed)
{
	int		len_1;
	int		i;
	char	**new_env;

	i = 0;
	len_1 = arr_len(g_env) + 2;
	if (!(new_env = (char **)malloc(sizeof(char *) * (len_1))))
		return (0);
	while (g_env[i])
	{
		new_env[i] = ft_strdup(g_env[i]);
		i++;
	}
	new_env[i] = ft_strdup(parsed[1]);
	i++;
	new_env[i] = NULL;
	i = 0;
	while (g_env[i])
	{
		free(g_env[i]);
		i++;
	}
	free(g_env);
	g_env = new_env;
	return (1);
}

int		unset_env(char **parsed)
{
	int		i;
	char	**new_env;
	int		len;

	len = while_u_len(parsed[1]);
	i = 0;
	if (!(new_env = (char **)malloc(sizeof(char *) * arr_len(g_env) - 2)))
		return (0);
	while (g_env[i])
	{
		if (ft_strncmp(g_env[i], parsed[1], len) == 0)
			i++;
		new_env[i] = ft_strdup(g_env[i]);
		i++;
	}
	new_env[i] = NULL;
	i = 0;
	while (g_env[i])
	{
		free(g_env[i]);
		i++;
	}
	free(g_env);
	g_env = new_env;
	return (1);
}

static int		set_env(char **parsed)
{
	int		i;
	int		len;

	i = 0;
	len = while_u_len(parsed[1]);
	while (g_env[i])
	{
		if (ft_strncmp(parsed[1], g_env[i], len) == 0)
		{
			if (parsed[1][len] == '=')
			{
				free(g_env[i]);
				g_env[i] = ft_strdup(parsed[1]);
				return (1);
			}
			else
				return (0);
		}
		i++;
	}
	new_env(parsed);
	return (1);
}

static int		get_env(char **parsed, int switch_own_arg)
{
	if (switch_own_arg == 5)
	{
		print_d_arr(g_env);
		return (3);
	}
	else if (switch_own_arg == 6)
	{
		if (set_env(parsed))
			return (3);
		return (0);
	}
	else if (switch_own_arg == 7)
	{
		if (unset_env(parsed))
			return (3);
		return (0);
	}
	return (0);
}

static int		own_cmd_handler_3(int switch_own_arg, char **parsed)
{
	if (switch_own_arg == 1)
	{
		CLEAR();
		exit(0);
	}
	else if (switch_own_arg == 2)
	{
		chdir(parsed[1]);
		return (1);
	}
	else if (switch_own_arg == 3)
	{
		open_help();
		return (1);
	}
	else if (switch_own_arg == 4)
	{
		ft_printf("\nHello.\nMind that this is "
			"not a place to play around."
			"\nUse help to know more..\n");
		return (1);
	}
	else if (switch_own_arg > 4)
		return (get_env(parsed, switch_own_arg));
	return (0);
}

static int		own_cmd_handler_2(int switch_own_arg, char **parsed,
									char **list_of_own_cmds)
{
	int i;

	i = 0;
	while (i < 7)
	{
		if (ft_strcmp(parsed[0], list_of_own_cmds[i]) == 0)
		{
			switch_own_arg = i + 1;
			break ;
		}
		i++;
	}
	return (own_cmd_handler_3(switch_own_arg, parsed));
}

int		own_cmd_handler(char **parsed)
{
	int		switch_own_arg;
	char	*list_of_own_cmds[7];
	char	*username;

	username = NULL;
	switch_own_arg = 0;
	list_of_own_cmds[0] = "exit";
	list_of_own_cmds[1] = "cd";
	list_of_own_cmds[2] = "help";
	list_of_own_cmds[3] = "hello";
	list_of_own_cmds[4] = "env";
	list_of_own_cmds[5] = "setenv";
	list_of_own_cmds[6] = "unsetenv";
	return (own_cmd_handler_2(switch_own_arg, parsed,
						list_of_own_cmds));
}

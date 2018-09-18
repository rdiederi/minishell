/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <rdiederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:46:42 by rdiederi          #+#    #+#             */
/*   Updated: 2018/09/18 19:01:28 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int		set_env(char **parsed, char **env)
{
	int		i;
	int		len;
	int		c_len;
	char	*str;

	i = 0;
	c_len = 0;
	len = ft_strlen(parsed[1]);
	while (env[i])
	{
		if (ft_strncmp(parsed[1], env[i], len) == 0)
		{
			c_len = ft_strlen(parsed[2]) + len + 1;
			str = (char *)malloc(sizeof(char) * c_len);
			str = ft_strjoin(parsed[1], "=");
			str = ft_strjoin(str, parsed[2]);
			ft_strcpy(env[i], str);
			free(str);
		}
		i++;
	}
	// if (!(c_len))
	// 	new
	return (1);
}

static int		get_env(char **parsed, int switch_own_arg, char **env)
{
	if (switch_own_arg == 5)
	{
		print_d_arr(env);
		return (3);
	}
	else if (switch_own_arg == 6)
	{
		set_env(parsed, env);
		return (3);
	}
	// else if (switch_own_arg == 7)
	// {
	// 	unsetenv(parsed, env);
	// 	return (3);
	// }
	return (0);
}

static int		own_cmd_handler_3(int switch_own_arg, char **parsed, char **env)
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
		return (get_env(parsed, switch_own_arg, env));
	return (0);
}

static int		own_cmd_handler_2(int switch_own_arg, char **parsed,
									char **env, char **list_of_own_cmds)
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
	return (own_cmd_handler_3(switch_own_arg, parsed, env));
}

int		own_cmd_handler(char **parsed, char **env)
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
						env, list_of_own_cmds));
}

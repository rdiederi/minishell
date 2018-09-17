/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <rdiederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:46:42 by rdiederi          #+#    #+#             */
/*   Updated: 2018/09/17 15:01:23 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int		own_cmd_handler_2(int switch_own_arg, char **parsed, char *username)
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
		username = getenv("USER");
		ft_printf("\nHello %s.\nMind that this is "
			"not a place to play around."
			"\nUse help to know more..\n",
			username);
		return (1);
	}
	return (0);
}

int		own_cmd_handler(char **parsed)
{
	int		no_of_own_cmds;
	int		i;
	int		switch_own_arg;
	char	*list_of_own_cmds[4];
	char	*username;

	username = NULL;
	switch_own_arg = 0;
	no_of_own_cmds = 4;
	i = 0;
	list_of_own_cmds[0] = "exit";
	list_of_own_cmds[1] = "cd";
	list_of_own_cmds[2] = "help";
	list_of_own_cmds[3] = "hello";
	while (i < no_of_own_cmds)
	{
		if (ft_strcmp(parsed[0], list_of_own_cmds[i]) == 0)
		{
			switch_own_arg = i + 1;
			break ;
		}
		i++;
	}
	return (own_cmd_handler_2(switch_own_arg, parsed, username));
}

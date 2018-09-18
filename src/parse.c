/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <rdiederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:52:13 by rdiederi          #+#    #+#             */
/*   Updated: 2018/09/18 15:22:45 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	parse_space(char *str, char **parsed)
{
	int i;

	i = 0;
	while (i < MAXLIST)
	{
		parsed[i] = strsep(&str, " ");
		if (parsed[i] == NULL)
			break ;
		if (strlen(parsed[i]) == 0)
			i--;
		i++;
	}
}

int		process_string(char *str, char **parsed, char **parsed_pipe,
						char **env)
{
	char	*strpiped[2];
	int		piped;

	piped = 0;
	if (piped)
		parse_space(strpiped[0], parsed);
	else
		parse_space(str, parsed);
	if (own_cmd_handler(parsed, env))
		return (0);
	else
		return (1 + piped);
}

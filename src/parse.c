/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <rdiederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:52:13 by rdiederi          #+#    #+#             */
/*   Updated: 2018/09/17 14:54:22 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int		parse_pipe(char *str, char **strpiped)
{
	int i;

	i = 0;
	while (i < 2)
	{
		strpiped[i] = strsep(&str, "|");
		if (strpiped[i] == NULL)
			break ;
		i++;
	}
	if (strpiped[1] == NULL)
		return (0);
	else
		return (1);
}

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

int		process_string(char *str, char **parsed, char **parsed_pipe)
{
	char	*strpiped[2];
	int		piped;

	piped = 0;
	piped = parse_pipe(str, strpiped);
	if (piped)
	{
		parse_space(strpiped[0], parsed);
		parse_space(strpiped[1], parsed_pipe);
	}
	else
		parse_space(str, parsed);
	if (own_cmd_handler(parsed))
		return (0);
	else
		return (1 + piped);
}
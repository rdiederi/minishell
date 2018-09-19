/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <rdiederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:52:13 by rdiederi          #+#    #+#             */
/*   Updated: 2018/09/19 19:07:03 by rdiederi         ###   ########.fr       */
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

int		process_string(char *str, char **parsed)
{
	char	*strpiped[2];
	int		piped;

	piped = 0;
	if (piped)
		parse_space(strpiped[0], parsed);
	else
		parse_space(str, parsed);
	if (own_cmd_handler(parsed))
		return (0);
	// else if (ft_strcmp(parsed[0], "echo"))
	// 	echo_check();
	else
		return (1 + piped);
}

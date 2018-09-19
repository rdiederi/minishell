/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <rdiederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:04:04 by rdiederi          #+#    #+#             */
/*   Updated: 2018/09/19 16:59:30 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	init_shell(void)
{
	CLEAR();
	ft_printf("\n\n\n\n\t\t***************************************");
	ft_printf("\n\n\n\t\t*************  MINISHELL  *************");
	ft_printf("\n\n\n\t\t***************************************");
	sleep(1);
	CLEAR();
}

void		print_dir(void)
{
	char cwd[1024];

	getcwd(cwd, sizeof(cwd));
	ft_printf("\nDir: %s\n", cwd);
}

void		open_help(void)
{
	ft_printf("******************"
		"****************************\n");
	ft_printf("\t***WELCOME TO MINISHELL HELP***\n"
		"\n-Use the shell at your own risk...\n"
		"\nList of Commands support         ed:"
		"\n>cd"
		"\n>ls"
		"\n>echo"
		"\n>pwd"
		"\n>env"
		"\n>setenv"
		"\n>unsetenv"
		"\n>exit"
		"\n>improper space handling");
	ft_printf("\n******************"
		"****************************\n");
	return ;
}

int			main(int argc, char **argv, char **env)
{
	char	*input_string;
	char	*parsed_args[MAXLIST];
	int		exec_flag;

	exec_flag = 0;
	if (argv && argc > 1)
		return (0);
	init_env(env);
	init_shell();
	while (1)
	{
		ft_printf("$>");
		if (!(get_next_line(0, &input_string)))
			continue;
		exec_flag = process_string(input_string,
		parsed_args);
		if (exec_flag == 1)
			exec_args(parsed_args);
	}
	return (0);
}

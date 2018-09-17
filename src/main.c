/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <rdiederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:04:04 by rdiederi          #+#    #+#             */
/*   Updated: 2018/09/17 16:49:26 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	init_shell(void)
{
	CLEAR();
	ft_printf("\n\n\n\n\t\t***************************************");
	ft_printf("\n\n\n\t\t*************  MINISHELL  *************");
	ft_printf("\n\n\n\t\t***************************************");
	ft_printf("\n\n\n\n\n\n\n\n\n");
	sleep(1);
	CLEAR();
}

void	print_dir(void)
{
	char cwd[1024];

	getcwd(cwd, sizeof(cwd));
	ft_printf("\nDir: %s\n", cwd);
}

void	open_help(void)
{
	ft_printf("******************"
		"****************************\n");
	ft_printf("\t***WELCOME TO MINISHELL HELP***\n"
		"\n-Use the shell at your own risk...\n"
		"\nList of Commands supported:"
		"\n>cd"
		"\n>ls"
		"\n>echo"
		"\n>pwd"
		"\n>exit"
		"\n>improper space handling");
	ft_printf("\n******************"
		"****************************\n");
	return ;
}

int		main(int argc, char **argv, char **env)
{
	char	*input_string;
	char	*parsed_args[MAXLIST];
	char	*parsed_args_piped[MAXLIST];
	int		exec_flag;

	env = NULL;
	exec_flag = 0;
	if (argv && argc > 1)
		return (0);
	print_d_arr(env);
	// if (!(init_env(env)))
	// 	return (0);
	init_shell();
	while (1)
	{
		ft_printf("$>");
		if (!(get_next_line(0, &input_string)))
			continue;
		exec_flag = process_string(input_string,
		parsed_args, parsed_args_piped);
		if (exec_flag == 1)
			exec_args(parsed_args);
		// print_d_arr(parsed_args);
		if (exec_flag == 2)
			exec_args_piped(parsed_args, parsed_args_piped);
	}
    return 0;
}

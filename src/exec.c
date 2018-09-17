/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <rdiederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:50:05 by rdiederi          #+#    #+#             */
/*   Updated: 2018/09/17 15:02:07 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	exec_args(char **parsed)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		ft_printf("\nFailed forking child..\n");
		return ;
	}
	else if (pid == 0)
	{
		if (execvp(parsed[0], parsed) < 0)
			ft_printf("Could not execute command..\n");
		exit(0);
	}
	else
	{
		wait(NULL);
		return ;
	}
}

static void	exec_args_piped_3(char **parsed, int *pipefd)
{
	close(pipefd[0]);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	if (execvp(parsed[0], parsed) < 0)
	{
		ft_printf("\nCould not execute command 1..\n");
		exit(0);
	}
}

static void	exec_args_piped_2(char **parsed, char **parsed_pipe, int *pipefd)
{
	pid_t	p2;

	parsed = NULL;
	p2 = fork();
	if (p2 < 0)
	{
		ft_printf("\nCould not fork\n");
		return ;
	}
	if (p2 == 0)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		if (execvp(parsed_pipe[0], parsed_pipe) < 0)
		{
			ft_printf("\nCould not execute command 2..\n");
			exit(0);
		}
	}
	else
	{
		wait(NULL);
		wait(NULL);
	}
}

void	exec_args_piped(char **parsed, char **parsed_pipe)
{
	int		pipefd[2];
	pid_t	p1;

	if (pipe(pipefd) < 0)
	{
		ft_printf("\nPipe could not be initialized\n");
		return ;
	}
	p1 = fork();
	if (p1 < 0)
	{
		ft_printf("\nCould not fork\n");
		return ;
	}
	if (p1 == 0)
	{
		exec_args_piped_3(parsed, pipefd);
	}
	else
	{
		exec_args_piped_2(parsed, parsed_pipe, pipefd);
	}
}
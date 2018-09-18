/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdiederi <rdiederi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 15:57:12 by rdiederi          #+#    #+#             */
/*   Updated: 2018/09/18 19:01:59 by rdiederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdio.h>
# include <string.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"

# define MAXCOM 1000
# define MAXLIST 100
# define CLEAR() ft_printf("\033[H\033[J")

typedef struct	s_mini_flags
{
	int	n_cmd;
}				t_mini_flags;

int				main(int argc, char **argv, char **env);
int				own_cmd_handler(char **parsed, char **env);
void			exec_args_piped(char **parsed, char **parsed_pipe);
void			exec_args(char **parsed);
int				process_string(char *str, char **parsed, char **parsed_pipe,
								char **env);
void			open_help(void);
void			print_dir(void);
void			print_d_arr(char **arr);
char			**init_env(char **old_env, char	**new_env);
// int				set_env(char **parsed, char **env);

#endif

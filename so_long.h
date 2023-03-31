/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:06:55 by kaboussi          #+#    #+#             */
/*   Updated: 2023/03/30 16:46:52 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include "get_next_line/get_next_line.h"

typedef struct s_var
{
	int		fd;
	int		i;
	int		j;
	int		c;
	int		p;
	int		e;
	int		m;
	int		k;
	int		lines;
	int		pos_i;
	int		pos_j;
	char	*a;
	char	*str;
	char	*file;
	char	**map;
	char	**maap;
	int		len;
	void	*mlx;
	void	*mlx_w;
	void	*img_w;
	void	*img_e;
	void	*img_p;
	void	*img_c;
	void	*img_0;
	void	*img_m;
	int		w;
	int		h;
	int		save_i;
	int		save_j;
	int		count_move;
}	t_var;

//UTILS_FUNCTIONS

void	ft_putstr(char *s);
char	*ft_strchr(const char *str, int ch);
int		ft_str_line(const char *str);
char	*ft_strdup(const char *str);
char	*ft_itoa(int n);
int		ft_putnbr(int n);

//PARSING_MANDATORY

void	printerror_message(char *str);
int		check_opning(char *file);
void	check_extension(char *str);
void	check_rectangle(char *file, t_var *var);
void	check_walls(t_var	*var);
void	check_char(t_var	*var);
void	check_not_char(t_var *var);

//MLX_FUNCTIONS

int		render(t_var *var);
int		ex_it(t_var *var);
int		key_prs(int code, t_var *var);
int		check_wall(t_var *var, int code);

#endif
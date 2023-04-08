/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:06:55 by kaboussi          #+#    #+#             */
/*   Updated: 2023/04/07 20:16:26 by kaboussi         ###   ########.fr       */
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

# define SZ 50

typedef struct s_var
{
	int		fd;
	int		i;
	int		j;
	int		c;
	int		p;
	int		e;
	int		n;
	int		k;
	int		o;
	int		lines;
	int		pos_i;
	int		pos_j;
	char	*a;
	char	*file;
	char	**map;
	char	**copie;
	int		len;
	void	*mlx;
	void	*mlx_w;
	void	*img_w;
	void	*img_e;
	void	*img_p;
	void	*img_c;
	void	*img_0;
	void	*m;
	int		w;
	int		h;
	int		save_i;
	int		save_j;
	int		count_move;
}	t_var;

typedef struct s_data
{
	int		x;
	int		y;
}	t_data;

//UTILS_FUNCTIONS

void	ft_putstr(char *s);
char	*ft_strchr(const char *str, int ch);
int		ft_str_line(const char *str);
char	*ft_strdup(const char *str);
char	*ft_itoa(int n);
int		ft_putnbr(int n);
char	**ft_free(char **p);
void	free_max(t_var *var);

//PARSING_MANDATORY

void	printerror_message(char *str);
int		check_opning(char *file);
void	check_extension(char *str);
void	check_rectangle(char *file, t_var *var);
void	check_walls(t_var	*var);
void	check_char(t_var	*var);
void	check_not_char(t_var *var);
int		charge(t_var *var, t_data p);
char	**ft_copie(t_var *var);
void	check_validation(t_var *var);

//MLX_FUNCTIONS

int		render(t_var *var);
int		ex_it(t_var *var);
int		key_prs(int code, t_var *var);
int		check_wall(t_var *var, int code);

#endif
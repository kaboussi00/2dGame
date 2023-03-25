/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:06:55 by kaboussi          #+#    #+#             */
/*   Updated: 2023/03/22 17:08:05 by kaboussi         ###   ########.fr       */
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
	int		k;
	int		lines;
	char	*a;
	char	*file;
	char	**map;
	char	**maap;
	int		len;
}	t_var;
void	ft_putstr(char *s);
void	printerror_message(char *str);
int		check_opning(char *file);
void	check_extension(char *str);
void	check_rectangle(char *file, t_var *var);
void	check_walls(t_var	*var);
void	check_char(t_var	*var);
int		ft_str_line(const char *str);
char	*ft_strdup(const char *str);

#endif
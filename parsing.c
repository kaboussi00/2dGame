/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:23:20 by kaboussi          #+#    #+#             */
/*   Updated: 2023/04/03 17:08:14 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_not_char(t_var *var)
{
	var->i = 0;
	while (var->i < var->lines)
	{
		var->j = 0;
		while (var->j < var->len)
		{
			if (!ft_strchr("10CPE", var->map[var->i][var->j]))
				printerror_message("invalid character\n");
			var->j++;
		}
		var->i++;
	}
}

void	check_extension(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	i--;
	if (str[i] != 'r')
		printerror_message("extension error\n");
	if (str[i - 1] != 'e')
		printerror_message("extension error\n");
	if (str[i -2] != 'b' )
		printerror_message("extension error\n");
	if (str[i - 3] != '.')
		printerror_message("extension error\n");
}

void	check_rectangle(char *file, t_var	*var)
{
	var->i = 0;
	var->lines = 0;
	var->file = ft_strdup(file);
	var->fd = open(file, O_RDWR);
	if (var->fd == -1)
		printerror_message("can't open file\n");
	var->a = get_next_line(var->fd);
	if (var->a == NULL)
		printerror_message("empty file\n");
	var->len = ft_str_line(var->a);
	while (var->a)
	{
		free (var->a);
		var->a = NULL;
		var->a = get_next_line(var->fd);
		if (!var->a)
			break ;
		if (var->len != ft_str_line(var->a))
			printerror_message("map isn't rectangle\n");
		var->lines += 1;
	}
	var->lines++;
}

void	char2(t_var	*var)
{
	if (var->e != 1)
		printerror_message("more or less than one exit\n");
	if (var->p != 1)
		printerror_message("more or less than one player\n");
	if (var->c < 1)
		printerror_message("no item\n");
}

void	check_char(t_var	*var)
{
	var->i = 0;
	var->c = 0;
	var->e = 0;
	var->p = 0;
	while (var->i++ < var->lines - 1)
	{
		var->j = 0;
		while (var->j++ < var->len - 1)
		{
			if (var->map[var->i][var->j] == 'C')
				var->c += 1;
			if (var->map[var->i][var->j] == 'E')
				var->e += 1;
			if (var->map[var->i][var->j] == 'P')
			{
				var->p += 1;
				var->pos_i = var->i;
				var->pos_j = var->j;
			}
		}
	}
	char2(var);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:06:04 by kaboussi          #+#    #+#             */
/*   Updated: 2023/03/30 16:28:26 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	char2bonus(t_var *var)
{
	if (var->e != 1)
		printerror_message("more or less than one exit\n");
	if (var->p != 1)
		printerror_message("more or less than one player\n");
	if (var->c < 1)
		printerror_message("no item\n");
	if (var->m < 1)
		printerror_message("no enemies\n");
}

void	check_char(t_var	*var)
{
	var->i = 0;
	var->c = 0;
	var->e = 0;
	var->p = 0;
	var->m = 0;
	while (var->i++ < var->lines - 1)
	{
		var->j = 0;
		while (var->j++ < var->len - 1)
		{
			if (var->map[var->i][var->j] == 'C')
				var->c += 1;
			if (var->map[var->i][var->j] == 'E')
				var->e += 1;
			if (var->map[var->i][var->j] == 'M')
				var->m += 1;
			if (var->map[var->i][var->j] == 'P')
			{
				var->p += 1;
				var->pos_i = var->i;
				var->pos_j = var->j;
			}
		}
	}
	char2bonus(var);
}


void	wallsbonus2(t_var *var)
{
	var->i = 0;
	while (var->i < var->lines)
	{
		if (var->map[var->i][0] != '1' || var->map[var->i][var->len - 1] != '1')
			printerror_message("walls problem2\n");
		var->i++;
	}
}

void	check_walls_bonus(t_var	*var)
{
	var->i = 0;
	close(var->fd);
	var->fd = open(var->file, O_RDWR);
	var->map = malloc(sizeof(char *) * (var->lines + 1));
	var->a = get_next_line(var->fd);
	while (var->a != NULL)
	{
		var->map[var->i++] = var->a;
		var->a = get_next_line(var->fd);
	}
	var->map[var->i] = NULL;
	var->i = 0;
	while (var->map[0][var->i] && var->map[0][var->i] != '\n')
	{
		if (var->map[0][var->i] != '1' || \
		var->map[var->lines - 1][var->i] != '1')
			printerror_message("walls problem1\n");
		var->i++;
	}
	wallsbonus2(var);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:31:25 by kaboussi          #+#    #+#             */
/*   Updated: 2023/03/30 16:29:11 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_opning(char *file)
{
	int	fd;

	fd = open(file, O_RDWR);
	if (fd == -1)
	{
		printerror_message("can't open file\n");
	}
	return (fd);
}

void	walls2(t_var *var)
{
	var->i = 0;
	while (var->i < var->lines)
	{
		if (var->map[var->i][0] != '1' || var->map[var->i][var->len - 1] != '1')
			printerror_message("walls problem2\n");
		var->i++;
	}
}

void	check_walls(t_var	*var)
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
	walls2(var);
}

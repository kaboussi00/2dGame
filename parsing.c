/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:23:20 by kaboussi          #+#    #+#             */
/*   Updated: 2023/03/24 16:06:14 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_opning(char *file)
{
	int	fd;

	fd = open(file, O_RDWR);
	if (fd == -1)
		printerror_message("can't open file\n");
	return (fd);
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

void	check_walls(t_var	*var)
{
	var->i = 0;
	close(var->fd);
	var->fd = open(var->file, O_RDWR);
	printf("var->lines ; %d\nvar->fd : %d\n", var->lines, var->fd);
	var->map = malloc(sizeof(char *) * (var->lines + 1));
	var->a = get_next_line(var->fd);
	printf("line : %s\n", var->a);
	puts("a");
	while (var->a != NULL)
	{
		// puts("e");
		var->map[var->i++] = var->a;
		var->a = get_next_line(var->fd);
	}
	var->map[var->i] = NULL;
	var->i = 0;
	puts("b");
	while (var->map[0][var->i] && var->map[0][var->i] != '\n')
	{
		// puts("d");
		// printf("var->map[0][var->i] ; %c\n", var->map[0][var->i]);
		// printf("var->map[var->lines - 1][var->i] ; %c\n", var->map[var->lines - 1][var->i]);
		if (var->map[0][var->i] != '1' || var->map[var->lines - 1][var->i] != '1')
			printerror_message("walls problem1\n");
		var->i++;
	}
	var->i = 0;
	puts("c");
	while (var->i < var->lines)
	{
		if (var->map[var->i][0] != '1' || var->map[var->i][var->len - 1] != '1')
			printerror_message("walls problem2\n");
		var->i++;
		// puts("f");
	}
}

void	check_char(t_var	*var)
{
	var->i = 0;
	var->c = 0;
	var->e = 0;
	var->p = 0;
	while (var->i++ < var->lines)
	{
		var->j = 0;
		while (var->j++ < var->len - 1)
		{
			if (var->map[var->i][var->j] == 'C')
				var->c += 1;
			if (var->map[var->i][var->j] == 'E')
				var->e += 1;
			if (var->map[var->i][var->j] == 'P')
				var->p += 1;
		}
	}
	if (var->e != 1)
		printerror_message("more or less than one exit\n");
	if (var->p != 1)
		printerror_message("more or less than one player\n");
	if (var->e < 1)
		printerror_message("no item\n");
}


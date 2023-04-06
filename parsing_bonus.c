/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:26:41 by kaboussi          #+#    #+#             */
/*   Updated: 2023/04/03 17:02:51 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	check_not_char(t_var *var)
{
	var->i = 0;
	while (var->i < var->lines)
	{
		var->j = 0;
		while (var->j < var->len)
		{
			if (!ft_strchr("10CPEM", var->map[var->i][var->j]))
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
	var->len = 0;
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

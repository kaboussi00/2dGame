/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:03:52 by kaboussi          #+#    #+#             */
/*   Updated: 2023/04/07 20:11:40 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	charge(t_var *var, t_data p)
{
	t_data	l;

	if (var->copie[p.y][p.x] == 'E')
	{
		var->o++;
		var->copie[p.y][p.x] = '1';
		return (0);
	}
	if (p.y < 0 || p.y >= var->lines || p.x < 0 || p.x >= var->len
		|| var->copie[p.y][p.x] == '1')
		return (0);
	var->copie[p.y][p.x] = '1';
	l.x = p.x;
	l.y = p.y + 1;
	charge(var, l);
	l.x = p.x;
	l.y = p.y - 1;
	charge(var, l);
	l.x = p.x - 1;
	l.y = p.y;
	charge(var, l);
	l.x = p.x + 1;
	l.y = p.y;
	charge(var, l);
	return (1);
}

char	**ft_copie(t_var *var)
{
	var->i = 0;
	var->copie = malloc(sizeof(char *) * (var->lines + 1));
	while (var->i < var->lines)
	{
		var->copie[var->i] = malloc(sizeof(char) * (var->len + 1));
		var->i++;
	}
	var->copie[var->i] = NULL;
	var->i = -1;
	while (++var->i < var->lines)
	{
		var->j = -1;
		while (++var->j < var->len)
		{
			var->copie[var->i][var->j] = var->map[var->i][var->j];
		}
	}
	return (var->copie);
}

void	check_validation(t_var *var)
{
	t_data	p;

	var->o = 0;
	p.y = var->pos_i;
	p.x = var->pos_j;
	var->copie = ft_copie(var);
	charge(var, p);
	var->i = -1;
	while (++var->i < var->lines)
	{
		var->j = -1;
		while (++var->j < var->len)
		{
			if (var->copie[var->i][var->j] == 'C' || var->o == 0)
				printerror_message("invalid map !\n");
		}
	}
	ft_free(var->copie);
}

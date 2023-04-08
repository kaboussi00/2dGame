/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:59:13 by kaboussi          #+#    #+#             */
/*   Updated: 2023/04/06 20:14:30 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	animation(t_var *v, int x)
{
	v->l = 0;
	while (v->l < 10000)
		v->l++;
	if (x % 4 == 0)
		mlx_put_image_to_window(v->mlx, v->mlx_w, v->m1, v->j * SZ, v->i * SZ);
	else if (x % 4 == 1)
		mlx_put_image_to_window(v->mlx, v->mlx_w, v->m2, v->j * SZ, v->i * SZ);
	else if (x % 4 == 2)
		mlx_put_image_to_window(v->mlx, v->mlx_w, v->m3, v->j * SZ, v->i * SZ);
	else if (x % 4 == 3)
		mlx_put_image_to_window(v->mlx, v->mlx_w, v->m4, v->j * SZ, v->i * SZ);
}

void	put_image(t_var *var, int x)
{
	if (var->map[var->i][var->j] == '1')
		mlx_put_image_to_window (var->mlx, \
		var->mlx_w, var->img_w, var->j * SZ, var->i * SZ);
	if (var->map[var->i][var->j] == '0')
		mlx_put_image_to_window(var->mlx, \
		var->mlx_w, var->img_0, var->j * SZ, var->i * SZ);
	if (var->map[var->i][var->j] == 'C')
		mlx_put_image_to_window(var->mlx, \
		var->mlx_w, var->img_c, var->j * SZ, var->i * SZ);
	if (var->map[var->i][var->j] == 'E')
		mlx_put_image_to_window(var->mlx, \
		var->mlx_w, var->img_e, var->j * SZ, var->i * SZ);
	if (var->map[var->i][var->j] == 'P')
		mlx_put_image_to_window(var->mlx, \
		var->mlx_w, var->img_p, var->j * SZ, var->i * SZ);
	if (var->map[var->i][var->j] == 'M')
		animation(var, x);
}

void	print_moves(t_var	*var)
{
	var->str = ft_itoa(var->count_move);
	mlx_string_put(var->mlx, var->mlx_w, 20, 20, 0x2d2926, var->str);
	free(var->str);
	var->str = NULL;
}

int	render(t_var *var)
{
	static int	x;

	var->i = -1;
	while (++var->i < var->lines)
	{
		var->j = -1;
		while (++var->j < var->len)
		{
			put_image(var, x);
		}
	}
	print_moves(var);
	x++;
	return (0);
}

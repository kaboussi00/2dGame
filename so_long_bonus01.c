/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:59:13 by kaboussi          #+#    #+#             */
/*   Updated: 2023/03/30 16:41:26 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_image(t_var *var)
{
	if (var->map[var->i][var->j] == '1')
		mlx_put_image_to_window (var->mlx, \
		var->mlx_w, var->img_w, var->j * 50, var->i * 50);
	if (var->map[var->i][var->j] == '0')
		mlx_put_image_to_window(var->mlx, \
		var->mlx_w, var->img_0, var->j * 50, var->i * 50);
	if (var->map[var->i][var->j] == 'C')
		mlx_put_image_to_window(var->mlx, \
		var->mlx_w, var->img_c, var->j * 50, var->i * 50);
	if (var->map[var->i][var->j] == 'E')
		mlx_put_image_to_window(var->mlx, \
		var->mlx_w, var->img_e, var->j * 50, var->i * 50);
	if (var->map[var->i][var->j] == 'P')
		mlx_put_image_to_window(var->mlx, \
		var->mlx_w, var->img_p, var->j * 50, var->i * 50);
	if (var->map[var->i][var->j] == 'M')
		mlx_put_image_to_window(var->mlx, \
		var->mlx_w, var->img_m, var->j * 50, var->i * 50);
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
	var->i = -1;
	while (++var->i < var->lines)
	{
		var->j = -1;
		while (++var->j < var->len)
		{
			put_image(var);
		}
	}
	print_moves(var);
	return (0);
}

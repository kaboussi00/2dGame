/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:26:27 by kaboussi          #+#    #+#             */
/*   Updated: 2023/03/30 16:41:04 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_wall(t_var *var, int code)
{
	var->i = var->pos_i;
	var->j = var->pos_j;
	if (code == 13)
		var->i--;
	if (code == 0)
		var->j--;
	if (code == 1)
		var->i++;
	if (code == 2)
		var->j++;
	if (var->map[var->i][var->j] == '1' || (var->map[var->i][var->j] == 'E'\
	&& var->c != 0))
		return (1);
	var->count_move += 1;
	return (0);
}

void	check_exit(t_var	*var)
{
	if (var->c == 0 && var->map[var->pos_i][var->pos_j] == 'E')
	{
		write(1, "you win !\n", 10);
		exit(0);
	}
	if (var->map[var->pos_i][var->pos_j] == 'M')
	{
		write(1, "you lose !\n", 11);
		exit(0);
	}
}

int	key_prs(int code, t_var *var)
{
	var->save_i = var->pos_i;
	var->save_j = var->pos_j;

	if (code == 53)
		exit(0);
	if (code == 13 && !check_wall(var, code))
		var->pos_i--;
	if (code == 0 && !check_wall(var, code))
		var->pos_j--;
	if (code == 1 && !check_wall(var, code))
		var->pos_i++;
	if (code == 2 && !check_wall(var, code))
		var->pos_j++;
	var->map[var->save_i][var->save_j] = '0';
	if (var->map[var->pos_i][var->pos_j] == 'C')
		var->c = var->c - 1;
	check_exit(var);
	var->map[var->pos_i][var->pos_j] = 'P';
	render(var);
	return (0);
}

int	main(int ac, char **av)
{
	t_var	*var;

	if (ac != 2)
		printerror_message("arg prb\n");
	var = malloc(sizeof(t_var));
	var->count_move = 0;
	var->i = 0;
	var->fd = check_opning(av[1]);
	check_extension(av[1]);
	check_rectangle(av[1], var);
	check_walls_bonus(var);
	check_char(var);
	check_not_char(var);
	var->mlx = mlx_init();
	var->mlx_w = mlx_new_window(var->mlx, 50 * var->len, 50 * var->lines, "k");
	var->img_w = mlx_xpm_file_to_image(var->mlx, "wl.xpm", &var->w, &var->h);
	var->img_p = mlx_xpm_file_to_image(var->mlx, "ll.xpm", &var->w, &var->h);
	var->img_e = mlx_xpm_file_to_image(var->mlx, "ll.xpm", &var->w, &var->h);
	var->img_c = mlx_xpm_file_to_image(var->mlx, "EEE.xpm", &var->w, &var->h);
	var->img_0 = mlx_xpm_file_to_image(var->mlx, "walll.xpm", &var->w, &var->h);
	var->img_m = mlx_xpm_file_to_image(var->mlx, "enemy.xpm", &var->w, &var->h);
	render(var);
	mlx_hook(var->mlx_w, 02, 0L, key_prs, var);
	mlx_hook(var->mlx_w, 17, 0L, ex_it, var);
	mlx_loop(var->mlx);
}

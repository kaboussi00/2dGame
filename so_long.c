/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:06:30 by kaboussi          #+#    #+#             */
/*   Updated: 2023/03/22 17:15:23 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// # include <stdio.h>
// # include <stdlib.h>
// # include <math.h>
// # include <mlx.h>
// # include <fcntl.h>
// # include <string.h>
// # include <unistd.h>

int	main(int ac, char **av)
{
	t_var	var;

	if (ac != 2)
		printerror_message("arg prb\n");
	var.i = 0;
	puts("-1");
	var.fd = check_opning(av[1]);
	check_extension(av[1]);
	puts("1");
	check_rectangle(av[1], &var);
	puts("2");
	check_walls(&var);
	puts("3");
	check_char(&var);
	puts("4");
}

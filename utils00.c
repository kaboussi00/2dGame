/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:24:43 by kaboussi          #+#    #+#             */
/*   Updated: 2023/04/07 20:16:17 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	printerror_message(char *str)
{
	write (1, "Error\n", 6);
	ft_putstr(str);
	exit(0);
}

void	ft_putstr(char *s)
{
	int		i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	ft_str_line(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*p;
	int		i;

	len = ft_str_len(str);
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (str[i])
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

void	free_max(t_var *var)
{
	mlx_destroy_image(var->mlx, var->img_w);
	mlx_destroy_image(var->mlx, var->img_e);
	mlx_destroy_image(var->mlx, var->img_p);
	mlx_destroy_image(var->mlx, var->img_c);
	mlx_destroy_image(var->mlx, var->img_0);
	ft_free(var->map);
	free(var->file);
	free(var);
}

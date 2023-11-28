/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:44:07 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/26 02:09:26 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

int	image_create(t_data *data)
{
	data->image.img = mlx_new_image(data->mlx_ptr,
			data->image.width, data->image.height);
	if (!data->image.img)
		return (1);
	data->image.addr = mlx_get_data_addr(data->image.img,
			&data->image.bpp, &data->image.line_length, &data->image.endian);
	if (!data->image.addr)
		return (1);
	return (0);
}

int	image_update(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->image.img, 0, 0);
	return (0);
}

int	my_mlx_pixel_put(t_image img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.line_length + x * (img.bpp / 8));
	if (!dst)
		return (1);
	*(unsigned int *)dst = color;
	return (0);
}

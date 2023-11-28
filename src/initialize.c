/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:33:54 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/27 20:06:06 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

void	ft_bzero(void *ptr, const size_t size)
{
	size_t	i;
	char	*str;

	if (!ptr)
		return ;
	i = 0;
	str = (char *)ptr;
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
}

int	init_data (t_data *data)
{
	ft_bzero(&data->image, sizeof(t_image));
	data->win_width = 1920;
	data->win_height = 1080;
	data->samples_per_pixel = 500;
	return (0);
}

int	init_sph(t_sphere *sph, const t_point3 *center, double r)
{
	sph->center = *center;
	sph->radius = r;
	return 0;
}

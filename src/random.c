/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 02:32:41 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/27 20:05:15 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

t_vec3	get_random_dev(const t_data *data)
{
	t_vec3	dev;

	dev.x = data->pixel_delta_u.x * ((10.0 * (double)rand() / (double)(RAND_MAX)) - 0.5);
	dev.y = data->pixel_delta_v.y * ((10.0 * (double)rand() / (double)(RAND_MAX)) - 0.5);
	dev.z = 0;
	return (dev);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_compute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 09:56:22 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/27 19:34:51 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

//fonction dest computes the pos_at (t_point3) on the ray path starting from origin in the direction dir
t_point3	pos_at(const t_ray *r, double t)
{
	t_vec3		vec;
	t_point3	end;

	vec = vec_number_prod(t, &r->dir);
	end = point_vec_add(&r->orig, &vec);
	return (end);
}

t_ray	ray_assign(const t_point3 *orig, const t_vec3 *dir)
{
	t_ray	r;

	r.orig = *orig;
	r.dir = *dir;
	return (r);
}

t_color	ray_color_grad_blue(const t_ray *r)
{
	t_color	color1;
	t_color	color2;
	t_color	pixel_color;

	//Intialization of pixel_color
	ft_bzero(&color1, sizeof(t_color));
	ft_bzero(&color2, sizeof(t_color));
	ft_bzero(&pixel_color, sizeof(t_color));
	t_vec3 unit_direction = vec_unit(&r->dir);
    double a = 0.5*(unit_direction.y + 1.0);
	edit_vec3(&color1.vec, 1.0, 1.0, 1.0);
	edit_vec3(&color2.vec, 0.5, 0.7, 1.0);
	t_vec3	temp1 = vec_number_prod(1.0 - a, &color1.vec);
	t_vec3	temp2 = vec_number_prod(a, &color2.vec);
	pixel_color.vec = vec_add(&temp1, &temp2);
	return (pixel_color);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_compute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 09:56:22 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/03 04:26:29 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

//fonction dest computes the pos_at (t_vec3) on the ray path starting from origin in the direction dir
t_vec3	hit_point(const t_ray r, double t)
{
	return (vec3_add2(r.orig, vec3_scale(t, r.dir)));
}

t_ray	new_ray(const t_vec3 orig, const t_vec3 dir)
{
	t_ray	r;

	r.orig = orig;
	r.dir = dir;
	return (r);
}

t_vec3	reflect(const t_vec3 v, const t_vec3 n)
{
    return (vec3_add2(v, vec3_scale(-2.0 * vec3_dot(v, n), n)));
}

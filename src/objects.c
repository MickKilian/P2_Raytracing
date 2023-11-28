/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 02:50:35 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/27 03:50:03 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

double	hit_sphere(const t_sphere *sph, const t_ray *r)
{
	//to determine where the ray r hits the sphere surface we use
	//oc: radius from center of sphere to camera	
	//center: center of the sphere
	//radius: radius of the sphere
	//We simply the quadratic equation noticing that we can devide
	// everything by a factor 2 and that a dot product of a vector
	// with itself is the length squared of that vector
	t_vec3 oc = vec_orig_end(&sph->center, &r->orig);
	double	a = vec_length_squared(&r->dir);
	double	half_b = vec_dot(&oc, &r->dir);
	double	c = vec_length_squared(&oc) - (sph->radius * sph->radius);
	double	discriminant = half_b*half_b - a*c;
	if (discriminant < 0)
		return -1.0;
	else
		return (-half_b - sqrt(discriminant)) / a;
}

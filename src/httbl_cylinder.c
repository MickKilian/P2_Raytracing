/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   httbl_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:08:45 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/04 06:32:40 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

t_cylinder	cylinder(const t_vec3 base_center, t_vec3 generator, double radius, double height)
{
	t_cylinder	cyl;

	cyl.base_center = base_center;
	cyl.generator = generator;
	cyl.radius = radius;
	cyl.height = height;
	return (cyl);
}

bool	hit_cylinder(const t_rt *rt, const t_ray r, const t_interval tray, t_hit_rec *rec)
{
	(void)rt;
	(void)r;
	(void)tray;
	(void)rec;
	return 1;
}

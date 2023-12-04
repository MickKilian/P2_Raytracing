/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometries.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 05:39:27 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/04 06:02:24 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

t_geometry	geom_plane(t_plane pln)
{
	t_geometry	geom;

	geom.type = PLANE;
	geom.pln = pln;
	return (geom);
}

t_geometry	geom_sphere(t_sphere sph)
{
	t_geometry	geom;

	geom.type = SPHERE;
	geom.sph = sph;
	return (geom);
}

t_geometry	geom_cylinder(t_cylinder cyl)
{
	t_geometry	geom;

	geom.type = CYLINDER;
	geom.cyl = cyl;
	return (geom);
}

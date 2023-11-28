/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geom_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 09:42:04 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/27 19:35:42 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

int	edit_point3(t_point3 *p, double x, double y, double z)
{
	p->x = x;
	p->y = y;
	p->z = z;
	return 0;
}

//add a point to a vec
t_point3	point_vec_add(const t_point3 *orig, const t_vec3 *vec)
{
	t_point3	end;

	end.x = orig->x + vec->x;
	end.y = orig->y + vec->y;
	end.z = orig->z + vec->z;
	return (end);
}

//substract a vec from a point
t_point3	point_vec_substract(const t_point3 *orig, const t_vec3 *vec)
{
	t_point3	end;

	end.x = orig->x - vec->x;
	end.y = orig->y - vec->y;
	end.z = orig->z - vec->z;
	return (end);
}

//compute a vec from 2 points
t_vec3	vec_orig_end(const t_point3 *orig, const t_point3 *end)
{
	t_vec3	vec;

	vec.x = end->x - orig->x;
	vec.y = end->y - orig->y;
	vec.z = end->z - orig->z;
	return (vec);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   httbl_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 20:08:45 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/02 05:37:07 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

t_plane	new_plane(const t_vec3 point, t_vec3 vec1, t_vec3 vec2)
{
	t_plane	pln;

	pln.point = point;
	pln.vec1 = vec1;
	pln.vec2 = vec2;
	return (pln);
}

bool	hit_plane(const t_rt *rt, const t_ray r, const t_interval tray, t_hit_rec *rec)
{
	(void)rt;
	(void)r;
	(void)tray;
	(void)rec;
	return 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   httbl_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:21:16 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/03 06:31:36 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

t_httbl	*new_httbl_plane(t_plane pln, t_mat_types mat, t_vec3 color)
{
	t_httbl	*new_httbl;

	new_httbl = ft_calloc(1, sizeof(t_httbl));
	if (!new_httbl)
		return (NULL);
	new_httbl->type = PLANE;
	new_httbl->mat = mat;
	new_httbl->color = color;
	new_httbl->next = NULL;
	new_httbl->pln = pln;
	return (new_httbl);
}

t_httbl	*new_httbl_sphere(t_sphere sph, t_mat_types mat, t_vec3 color)
{
	t_httbl	*new_httbl;

	new_httbl = ft_calloc(1, sizeof(t_httbl));
	if (!new_httbl)
		return (NULL);
	new_httbl->type = SPHERE;
	new_httbl->mat = mat;
	new_httbl->color = color;
	new_httbl->next = NULL;
	new_httbl->sph = sph;
	return (new_httbl);
}

t_httbl	*new_httbl_cylinder(t_cylinder cyl, t_mat_types mat, t_vec3 color)
{
	t_httbl	*new_httbl;

	new_httbl = ft_calloc(1, sizeof(t_httbl));
	if (!new_httbl)
		return (NULL);
	new_httbl->type = CYLINDER;
	new_httbl->mat = mat;
	new_httbl->color = color;
	new_httbl->next = NULL;
	new_httbl->cyl = cyl;
	return (new_httbl);
}


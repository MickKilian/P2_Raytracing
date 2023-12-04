/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   materials.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 05:34:23 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/04 06:02:50 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

t_material	mat_lamber(t_lamber lamber)
{
	t_material	mat;

	mat.type = LAMBERTIAN;
	mat.lamber = lamber;
	return (mat);
}

t_material	mat_metal(t_metal metal)
{
	t_material	mat;

	mat.type = METAL;
	mat.metal = metal;
	return (mat);
}

t_material	mat_dielec(t_dielec dielec)
{
	t_material	mat;

	mat.type = DIELECTRIC;
	mat.dielec = dielec;
	return (mat);
}

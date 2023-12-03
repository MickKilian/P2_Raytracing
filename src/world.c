/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:23:39 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/03 07:54:44 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

int	world_initialize(t_world *world)
{
	//ft_bzero(world, sizeof(t_world));
	// Initialisation of world
	//// Populate world with sphere for ground
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(-0.0, -100.5, -1.0), 100.0), METAL, new_vec3(0.13333, 0.25, 0.36)));
	//// Populate world with central sphere
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(0.0, 0.0, -1.0), 0.5), METAL, new_vec3(0.5, 0.5, 0.5)));
	//// Populate with many little spheres
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(-0.6, -0.3, -0.7), 0.15), METAL, new_vec3(0.0, 0.5, 0.0)));
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(1.0, 1.0, -0.5), 0.8), LAMBERTIAN, new_vec3(0.8, 0.3, 0.05)));
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(-0.3, 0.0, -0.5), 0.05), LAMBERTIAN, new_vec3(0.5, 0.0, 0.0)));
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(0.3, 0.3, -0.5), 0.05), LAMBERTIAN, new_vec3(0.0, 0.0, 0.5)));
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(0.5, 0.2, -0.5), 0.02), LAMBERTIAN, new_vec3(0.0, 0.5, 0.5)));
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(-0.6, 0.3, -0.5), 0.03), LAMBERTIAN, new_vec3(0.5, 0.0, 0.5)));
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(-0.03, 0.19, -0.3), 0.05), LAMBERTIAN, new_vec3(1.0, 1.0, 0.0)));
	//OTHER SET OF SPHERES
	httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(-0.0, -100.5, -1.0), 100.0), LAMBERTIAN, new_vec3(0.8, 0.8, 0.0)));
	httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(0.0, 0.0, -1.0), 0.5), LAMBERTIAN, new_vec3(0.8, 0.15, 0.05)));
	httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(-1.0, 0.0, -1.0), 0.5), METAL, new_vec3(0.9, 0.9, 0.9)));
	httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(1.0, 0.0, -1.0), 0.5), LAMBERTIAN, new_vec3(0.02, 0.0, 0.1)));
	return 0;
}

bool	world_hit(t_rt *rt, const t_ray r, t_interval tray, t_hit_rec *rec)
{
	t_hit_rec	temp_rec;
	bool		hit_anything;
	double		closest_so_far;

	hit_anything = false;
	closest_so_far = tray.max;
	while (rt->world.httbl)
	{
		if ((rt->world.httbl->type == PLANE && hit_plane(rt, r, interval(tray.min, closest_so_far), &temp_rec)) ||
					(rt->world.httbl->type == SPHERE && hit_sphere(rt, r, interval(tray.min, closest_so_far), &temp_rec)) ||
					(rt->world.httbl->type == CYLINDER && hit_cylinder(rt, r, interval(tray.min, closest_so_far), &temp_rec)))
		{
			hit_anything = true;
			closest_so_far = temp_rec.t;
			*rec = temp_rec;
		}
		rt->world.httbl = rt->world.httbl->next;
	}
	rt->world.httbl = rt->world.httbl_head;
	return hit_anything;
}

void	httbl_addback(t_world *world, t_httbl *new_httbl)
{
	if (!new_httbl)
		return ;
	if (!world->httbl)
	{
		world->httbl_head = new_httbl;
	}
	else
	{
		while (world->httbl->next)
			world->httbl = world->httbl->next;
		world->httbl->next = new_httbl;
	}
	world->size += 1;
	//Assign (if first) or go back to first element
	world->httbl = world->httbl_head;
	return ;
}

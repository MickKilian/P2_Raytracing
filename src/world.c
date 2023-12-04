/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:23:39 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/04 07:39:23 by mbourgeo         ###   ########.fr       */
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
	//// Ground
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(-0.0, -100.5, -1.0), 100.0), LAMBERTIAN, new_vec3(0.8, 0.8, 0.0)));
	//// Center sphere
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(0.0, 0.0, -1.0), 0.5), LAMBERTIAN, new_vec3(0.1, 0.2, 0.5)));
	//// Left sphere
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(-1.0, 0.0, -1.0), 0.5), DIELECTRIC, new_vec3(0.9, 0.9, 0.9)));
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(-1.0, 0.0, -1.0), -0.4), DIELECTRIC, new_vec3(0.9, 0.9, 0.9)));
	//// Right sphere
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(1.0, 0.0, -1.0), 0.5), LAMBERTIAN, new_vec3(0.02, 0.0, 0.1)));
	//// Left sphere
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(-r, 0.0, -1.0), r), LAMBERTIAN, new_vec3(0.0, 0.0, 1.0)));
	//// Right spehere
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(r, 0.0, -1.0), r), LAMBERTIAN, new_vec3(1.0, 0.0, 0.0)));

//	//// Populate world with sphere for ground
//	httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(-0.0, -100.5, -1.0), 100.0), LAMBERTIAN, new_vec3(0.8, 0.8, 0.0)));
//	// Center sphere
//	httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(0.0, 0.0, -1.0), 0.5), LAMBERTIAN, new_vec3(0.1, 0.2, 0.5)));
//	// Left sphere
//	httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(-1.0, 0.0, -1.0), 0.5), DIELECTRIC, new_vec3(0.9, 0.9, 0.9)));
//	httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(-1.0, 0.0, -1.0), -0.4), DIELECTRIC, new_vec3(0.9, 0.9, 0.9)));
//	// Right sphere
//	httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(1.0, 0.0, -1.0), 0.5), METAL, new_vec3(0.8, 0.6, 0.2)));
//
	// Center sphere
	//httbl_addback(world, new_httbl_sphere(new_sphere(new_vec3(0.0, 0.0, -1.0), 0.5), LAMBERTIAN, new_vec3(0.1, 0.2, 0.5)));
	//httbl_addback(world, new_httbl(void(*p1), void(*p2)));

//	// Populate world with sphere for ground
//	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(0.0, -100.5, -1.0), 100.0)), mat_lamber(lamber(new_vec3(0.8, 0.8, 0.0)))));
//	// Center sphere
//	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(0.0, 0.0, -1.0), 0.5)), mat_lamber(lamber(new_vec3(0.1, 0.2, 0.5)))));
//	// Left sphere
//	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(-1.0, 0.0, -1.0), 0.5)), mat_dielec(dielec(new_vec3(0.9, 0.9, 0.9), 1.5))));
//	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(-1.0, 0.0, -1.0), -0.4)), mat_dielec(dielec(new_vec3(0.9, 0.9, 0.9), 1.5))));
//	// Right sphere
//	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(1.0, 0.0, -1.0), 0.5)), mat_metal(metal(new_vec3(0.8, 0.6, 0.2), 0.0))));

	// Populate world with sphere for ground
	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(0.0, -1000.0, 0.0), 1000)), mat_lamber(lamber(new_vec3(0.5, 0.5, 0.5)))));


	for (int a = -11; a < 11; a++) {
		for (int b = -11; b < 11; b++) {
			double	choose_mat = random_double();
			t_vec3	center = new_vec3(a + 0.9 * random_double(), 0.2, b + 0.9 * random_double());

			if (vec3_length(vec3_substract2(center, new_vec3(4, 0.2, 0))) > 0.9)
			{
				t_material	sphere_material;
				if (choose_mat < 0.8) {
					// diffuse
					t_vec3	albedo = vec3_prod_comp_by_comp(new_vec3(random_double(), random_double(), random_double()),
							new_vec3(random_double(), random_double(), random_double()));
					sphere_material = mat_lamber(lamber(albedo));
					httbl_addback(world, new_httbl(geom_sphere(sphere(center, 0.2)), sphere_material));
				} 
				else if (choose_mat < 0.95)
				{
					// metal
					t_vec3	albedo = new_vec3(random_double_interval(0.5, 1), random_double_interval(0.5, 1.0), random_double_interval(0.5, 1.0));
					double	fuzz = random_double(0, 0.5);
					sphere_material = mat_metal(metal(albedo, fuzz));
					httbl_addback(world, new_httbl(geom_sphere(sphere(center, 0.2)), sphere_material));
				}
				else
				{
					// glass
					t_vec3	albedo = new_vec3(0.5, 0.5, 0.5);
					sphere_material = mat_dielec(dielec(albedo, 1.5));
					httbl_addback(world, new_httbl(geom_sphere(sphere(center, 0.2)), sphere_material));
				}
			}
		}
	}

	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(0.0, 1.0, 0.0), 1.0)), mat_dielec(dielec(new_vec3(0.9, 0.9, 0.9), 1.5))));

	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(-4.0, 1.0, 0.0), 1.0)), mat_lamber(lamber(new_vec3(0.4, 0.2, 0.1)))));

	httbl_addback(world, new_httbl(geom_sphere(sphere(new_vec3(4.0, 1.0, 0.0), 1.0)), mat_metal(metal(new_vec3(0.7, 0.6, 0.5), 0.0))));
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
		if ((rt->world.httbl->geom.type == PLANE && hit_plane(rt, r, interval(tray.min, closest_so_far), &temp_rec)) ||
					(rt->world.httbl->geom.type == SPHERE && hit_sphere(rt, r, interval(tray.min, closest_so_far), &temp_rec)) ||
					(rt->world.httbl->geom.type == CYLINDER && hit_cylinder(rt, r, interval(tray.min, closest_so_far), &temp_rec)))
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

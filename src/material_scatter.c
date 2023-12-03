/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_scatter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 02:25:58 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/03 07:36:20 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

// Lambertian : We model here Light Scatter and Reflectance
// Lambertian ditribution (in a manner proportional to cos(phi))
// We have 3 different options to model scatter of Lambertian diffuse materials we choose model with attenuation and always scattering
bool	lambertian_scatter(const t_ray r_in, const t_hit_rec rec, t_vec3 *attenuation, t_ray *scattered)
{
	t_vec3	scatter_direction;
	t_vec3	albedo;

	albedo = rec.color;
	// Different steps to refine scattering model for diffuse material
	//// ray_color is mapped with the coordinates of the normal to the surface at hit point
	//return (vec3_scale(0.5, vec3_add2(rec.normal, new_vec3(1.0, 1.0, 1.0))));
	//// We use here reflection evenly in all directions
	//bouncing_dir = random_in_same_hemisphere(rec.normal);
	scatter_direction = vec3_add2(rec.normal, random_unit_vector());
	// Catch degenerate scatter direction
	if (near_zero(scatter_direction))
		scatter_direction = rec.normal;
	*scattered = new_ray(rec.p, scatter_direction);
    *attenuation = albedo;
	(void)r_in;
    return 1;
}

// Metal : Perfect reflection
// We use function reflect
bool	metal_scatter(const t_ray r_in, const t_hit_rec rec, t_vec3 *attenuation, t_ray *scattered)
{
	t_vec3	reflected;
	t_vec3	albedo;
	double	fuzz;

	fuzz = 0.6;
	albedo = rec.color;
	reflected = reflect(vec3_unit(r_in.dir), rec.normal);
	*scattered = new_ray(rec.p, vec3_add2(reflected, vec3_scale(fuzz, random_unit_vector())));
    *attenuation = albedo;
    return 1;
}

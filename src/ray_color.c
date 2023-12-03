/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 02:50:35 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/03 07:09:47 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

t_vec3	ray_color(t_rt *rt, int depth, const t_ray r)
{
	t_hit_rec	rec;
	t_ray		scattered;
	t_vec3		attenuation;

	if (depth <= 0)
		return (new_vec3(0.0, 0.0, 0.0));
	// 0.001 prevents bugs from offset calculation of the usrface hit point due to float precision
	if (world_hit(rt, r, interval(0.001, INFINITY), &rec))
	{

		if (rec.mat == LAMBERTIAN)
			lambertian_scatter(r, rec, &attenuation, &scattered);
		else if (rec.mat == METAL)
			metal_scatter(r, rec, &attenuation, &scattered);
		//scattered_direction = vec3_add2(rec.normal, random_unit_vector());
		//// Catch degenerate scatter direction
		//if (near_zero(scattered_direction))
		//	scattered_direction = rec.normal;
		return (vec3_prod_comp_by_comp(attenuation, ray_color(rt, depth - 1, scattered)));
		//return (vec3_scale(attenuation, ray_color(rt, depth - 1, scattered)));
	}
	else
		return (ray_color_grad_blue(r));
}

t_vec3	ray_color_grad_blue(const t_ray r)
{
	t_vec3	pixel_color;

	//printf("r_dir : %f\n", r.dir.z);
	//Intialization of pixel_color
	ft_bzero(&pixel_color, sizeof(t_vec3));
    double a = 0.5 * (vec3_unit(r.dir).y + 1.0);
	pixel_color = vec3_add2(vec3_scale(1.0 - a, new_vec3(1.0, 1.0, 1.0)),
			vec3_scale(a, new_vec3(0.5, 0.7, 1.0)));
	return (pixel_color);
}

t_vec3	ray_color_grad_red(const t_ray r)
{
	t_vec3	pixel_color;

	//printf("r_dir : %f\n", r.dir.z);
	//Intialization of pixel_color
	ft_bzero(&pixel_color, sizeof(t_vec3));
    double a = 0.5 * (vec3_unit(r.dir).y + 1.0);
	pixel_color = vec3_add2(vec3_scale(1.0 - a, new_vec3(1.0, 1.0, 1.0)),
			vec3_scale(a, new_vec3(1.0, 0.5, 0.5)));
	return (pixel_color);
}

t_vec3	ray_color_grad_violet(const t_ray r)
{
	t_vec3	pixel_color;

	//printf("r_dir : %f\n", r.dir.z);
	//Intialization of pixel_color
	ft_bzero(&pixel_color, sizeof(t_vec3));
    double a = 0.5 * (vec3_unit(r.dir).y + 1.0);
	pixel_color = vec3_add2(vec3_scale(1.0 - a, new_vec3(1.0, 1.0, 1.0)),
			vec3_scale(a, new_vec3(0.5, 0.0, 1.0)));
	return (pixel_color);
}

t_vec3	ray_color_grad_yellow(const t_ray r)
{
	t_vec3	pixel_color;

	//printf("r_dir : %f\n", r.dir.z);
	//Intialization of pixel_color
	ft_bzero(&pixel_color, sizeof(t_vec3));
    double a = 0.5 * (vec3_unit(r.dir).y + 1.0);
	pixel_color = vec3_add2(vec3_scale(1.0 - a, new_vec3(1.0, 1.0, 1.0)),
			vec3_scale(a, new_vec3(1.0, 1.0, 0.18)));
	return (pixel_color);
}

t_vec3	ray_color_grad_sunset(const t_ray r)
{
	t_vec3	pixel_color;

	//printf("r_dir : %f\n", r.dir.z);
	//Intialization of pixel_color
	ft_bzero(&pixel_color, sizeof(t_vec3));
    double a = 0.5 * (vec3_unit(r.dir).y + 1.0);
	pixel_color = vec3_add2(vec3_scale(1.0 - a, new_vec3(1.0, 1.0, 1.0)),
			vec3_scale(a, new_vec3(0.38, 0.29, 0.14)));
	return (pixel_color);
}

t_vec3	ray_color_red()
{
	t_vec3	pixel_color;

	//Intialization of pixel_color
	ft_bzero(&pixel_color, sizeof(t_vec3));
	pixel_color = new_vec3(1.0, 0.0, 0.0);
	return (pixel_color);
}

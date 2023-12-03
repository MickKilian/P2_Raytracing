/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:54:17 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/03 07:28:46 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

void	cam_initialize(t_camera *cam, int img_width, int img_height)
{
	double	viewport_height;
	double	viewport_width;
	t_vec3	viewport_u;
	t_vec3	viewport_v;
	t_vec3	viewport_upper_left;

	cam->samples_per_pixel = 100;
	cam->max_depth = 50;

	// Camera position
	cam->center = new_vec3(0.0, 0.0, 0.0);

	// Viewport dimensions
	// Viewport widths less than one are ok since they are real valued.
	// We want viewport proportions to exactly match our image proportions
	cam->focal_length = 1.0;
	viewport_height = 2.0;
	viewport_width = viewport_height * ((double)img_width / (double)img_height);

	// Calculate the vectors across the horizontal and down the vertical viewport edges.
	viewport_u = new_vec3(viewport_width, 0, 0);
	viewport_v = new_vec3(0, -viewport_height, 0);

	// Calculate the horizontal and vertical delta vectors from pixel to pixel.
	cam->pixel_delta_u = vec3_scale(1.0 / img_width, viewport_u);
	cam->pixel_delta_v = vec3_scale(1.0 / img_height, viewport_v);

	// Calculate the location of the upper left pixel.
	viewport_upper_left = vec3_add3(
			vec3_add2(cam->center, vec3_scale(-1.0, new_vec3(0, 0, cam->focal_length))),
			vec3_scale(-0.5, viewport_u),
			vec3_scale(-0.5, viewport_v));
	cam->pixel00_loc = vec3_add3(
			viewport_upper_left,
			vec3_scale(0.5, cam->pixel_delta_u),
			vec3_scale(0.5, cam->pixel_delta_v));
}

int	render(t_rt *rt)
{
	t_vec3	pixel_color;
	t_vec3	pixel_center;
	t_vec3	ray_direction;

	// Intialization of pixel_color
	ft_bzero(&pixel_color, sizeof(t_vec3));

	// Render
	printf("P3\n%d %d\n255\n", rt->img_width, rt->img_height);

	for (int j = 0; j < rt->img_height; ++j)
	{
		printf("\rScanlines remaining: %d ", rt->img_height - j);
		for (int i = 0; i < rt->img_width; ++i)
		{
			pixel_color = new_vec3(0, 0, 0);
			for (int k = 0; k < rt->cam.samples_per_pixel; ++k)
			{
				// We add a small deviation for sampling
				pixel_center = vec3_add2(
								rt->cam.pixel00_loc,
								vec3_add2(
									vec3_add2(	vec3_scale(1.0 * i, rt->cam.pixel_delta_u),
												vec3_scale(1.0 * j, rt->cam.pixel_delta_v)),
									get_random_dev(&rt->cam)));
				ray_direction = vec3_substract2(pixel_center, rt->cam.center);
				pixel_color = vec3_add2(pixel_color,
						ray_color(rt, rt->cam.max_depth, new_ray(rt->cam.center, ray_direction)));
			}
			pixel_color = vec3_scale(1.0 / (double)rt->cam.samples_per_pixel, pixel_color);
			// We apply the gamme correction to the image
			my_mlx_pixel_put(rt->mlx.image, i, j, trgb2val(vec2trgb(lin2gam_vec(pixel_color))));
		}
	}
	printf("\rDone.                   \n");
	return 0;
}

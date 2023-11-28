/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm_example.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 23:02:19 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/27 19:56:10 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

int	ppm_example(t_data *data)
{
	t_color		pixel_color;
	t_color		pixel_color_cumul;
	t_vec3		temp1;
	t_vec3		temp2;
	t_point3	temp_point1;
	t_sphere	sph1;
	t_sphere	sph2;
	t_point3	center;
	t_vec3		dev;
	t_ray		r;
	double		t1;
	double		t2;

	//Intialization of pixel_color
	ft_bzero(&pixel_color, sizeof(t_color));
	ft_bzero(&pixel_color_cumul, sizeof(t_color));

	// Render
	printf("P3\n%d %d\n255\n", data->image.width, data->image.height);

	for (int j = 0; j < data->image.height; ++j)
	{
		printf("\rScanlines remaining: %d ", data->image.height - j);
		for (int i = 0; i < data->image.width; ++i)
		{
			//first example with two colors bleding in the diagonal
			//edit_vec3(&pixel_color.vec, (double)i / (data->image.width - 1), (double)j / (data->image.height - 1), 0);
			//vec2trgb(&pixel_color);
			//trgb2val(&pixel_color);
			//my_mlx_pixel_put(data->image, i, j, pixel_color.val);

			//blue_gradient exampl
			//we use sampling to reduce aliasing
			pixel_color_cumul.vec = new_vec3(0, 0, 0);
			for (int k = 0; k < data->samples_per_pixel; ++k)
			{
				temp1 = vec_number_prod(i, &data->pixel_delta_u);
				temp2 = vec_number_prod(j, &data->pixel_delta_v);
				temp1 = vec_add(&temp1, &temp2);
				//add a small deviation for sampling
				dev = get_random_dev(data);
				//(void)dev;
				temp1 = vec_add(&temp1, &dev);
				t_point3	pixel_center = point_vec_add(&data->pixel00_loc, &temp1);
				t_vec3		ray_direction = vec_orig_end(&data->camera_center, &pixel_center);
				r = ray_assign(&data->camera_center, &ray_direction);

				//red sphere in the middle
				//Initialization sphere center(0, 0, -1) and radius 0.5
				edit_point3(&center, 0.0, 0.0, -1.0);
				init_sph(&sph1, &center, 0.5);
				t1 = hit_sphere(&sph1, &r);
				//Initialization sphere2 center(0, -100.5, -1) and radius 100
				edit_point3(&center, -1.0, -0.2, -1.0);
				init_sph(&sph2, &center, 0.15);
				t2 = hit_sphere(&sph2, &r);
				if (t1 > 0)
				{
					temp_point1 = pos_at(&r, t1);
					temp1 = vec_orig_end(&sph1.center, &temp_point1);
					t_vec3	norm = vec_unit(&temp1);
					edit_vec3(&pixel_color.vec, 0.5 * (norm.x + 1.0), 0.5 * (norm.y + 1.0), 0.5 * (norm.z + 1.0));
				}
				else if (t2 > 0)
				{
					temp_point1 = pos_at(&r, t2);
					temp1 = vec_orig_end(&sph2.center, &temp_point1);
					t_vec3	norm = vec_unit(&temp1);
					edit_vec3(&pixel_color.vec, 0.5 * (norm.x + 1.0), 0.5 * (norm.y + 1.0), 0.5 * (norm.z + 1.0));
				}
				else
					pixel_color = ray_color_grad_blue(&r);
				pixel_color_cumul.vec = vec_add(&pixel_color_cumul.vec, &pixel_color.vec);
			}
			pixel_color.vec = vec_div_number(&pixel_color_cumul.vec, (double)data->samples_per_pixel);
			//pixel_color.vec = pixel_color_cumul.vec;
			//write_color(std::cout, pixel_color);
			vec2trgb(&pixel_color);
			//write_color(pixel_color);
			//convert color from rgb to val
			trgb2val(&pixel_color);
			my_mlx_pixel_put(data->image, i, j, pixel_color.val);
		}
	}
	printf("\rDone.                   \n");
	return 0;
}

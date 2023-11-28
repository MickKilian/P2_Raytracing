/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:39:34 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/27 19:36:21 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//****************************************************************************//
// I learned ray tracing using the following resources                        //
// Tuto rayTracing                                                            //
// https://raytracing.github.io/books/RayTracingInOneWeekend.html             //
//****************************************************************************//

#include "../inc/ray_tracing.h"

int	ray_tracing(int argc, char **argv) {

	//data is the structure containing all data in the program
	t_data		data;
	double		aspect_ratio = 16.0 / 9.0;
	t_vec3		temp_vec1;
	t_vec3		temp_vec2;
	t_point3	temp_point1;

	(void)argc;
	(void)argv;

	//tests of vec_operations
	//test_vec_operations();
	//return 0;

	//Initialization for random generator
	srand(time(0));
	//Initialization of structure data
	ft_bzero(&data, sizeof(t_data));
	init_data(&data);

	//Calculate the image height, and ensure that it's at least 1.
	data.image.width = 1000;
	data.image.height = (int)(data.image.width / aspect_ratio);
	if (data.image.height < 1)
		data.image.height = 1;

	//Viewport widths less than one are ok since they are real valued.
	//We want viewport proportions to exactly match our image proportions
	data.camera_focal_length = 1.0;
	data.viewport_height = 2.0;
	data.viewport_width = data.viewport_height * ((double)data.image.width / (double)data.image.height);

	//Camera position
	edit_point3(&data.camera_center, 0.0, 0.0, 0.0);

	//Calculate the vectors across the horizontal and down the vertical viewport edges.
	edit_vec3(&data.viewport_u, data.viewport_width, 0, 0);
	edit_vec3(&data.viewport_v, 0, -data.viewport_height, 0);

	//Calculate the horizontal and vertical delta vectors from pixel to pixel.
	data.pixel_delta_u = vec_div_number(&data.viewport_u, data.image.width);
	data.pixel_delta_v = vec_div_number(&data.viewport_v, data.image.height);

	//Calculate the location of the upper left pixel.
	temp_vec1 = new_vec3(0, 0, data.camera_focal_length);
	temp_point1 = point_vec_substract(&data.camera_center, &temp_vec1);
	temp_vec1 = vec_div_number(&data.viewport_u, 2);
	temp_point1 = point_vec_substract(&temp_point1, &temp_vec1);
	temp_vec1 = vec_div_number(&data.viewport_v, 2);
	data.viewport_upper_left = point_vec_substract(&temp_point1, &temp_vec1);
	temp_vec1 = data.pixel_delta_u;
	temp_vec2 = data.pixel_delta_v;
	temp_vec1 = vec_add(&temp_vec1, &temp_vec2);
	temp_vec1 = vec_div_number(&temp_vec1, 2);
	data.pixel00_loc = point_vec_add(&data.viewport_upper_left, &temp_vec1);

	//Initialisation of mlx and image
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.win_width, data.win_height, "Hello world!");
	data.image.img = mlx_new_image(data.mlx_ptr, data.image.width,data.image.height);
	data.image.addr = mlx_get_data_addr(data.image.img, &data.image.bpp, &data.image.line_length,
								&data.image.endian);

	//Prepare image in ppm format (tutorial)
	ppm_example(&data);

	// Show image
	image_update(&data);
	mlx_loop(data.mlx_ptr);

	return 0;
}

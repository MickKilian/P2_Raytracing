/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:08:04 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/27 19:36:05 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TRACING_H
# define RAY_TRACING_H

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <stdbool.h>
# include <time.h>

typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct	s_point3
{
	double	x;
	double	y;
	double	z;

}	t_point3;

typedef struct	s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct	s_ray
{
	t_point3	orig;
	t_vec3		dir;
}	t_ray;

typedef struct	s_color
{
	double	val;
	t_vec3	vec;
	double	trgb[4];
	double	thsv[4];
}	t_color;

typedef struct	s_sphere
{
	t_point3	center;
	double		radius;
}	t_sphere;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_width;
	int			win_height;
	t_point3	camera_center;
	double		camera_focal_length;
	double		viewport_width;
	double		viewport_height;
	t_vec3		viewport_u;
	t_vec3		viewport_v;
	t_point3	viewport_upper_left;
	t_point3	pixel00_loc;
	t_vec3		pixel_delta_u;
	t_vec3		pixel_delta_v;
	t_image		image;
	int			samples_per_pixel;
}	t_data;

//All functions prototypes
//ray_tracing.c
int			ray_tracing(int argc, char **argv);

//ppm_example.c
int			ppm_example(t_data *data);

//initialize.c
void		ft_bzero(void *ptr, const size_t size);
int			init_data(t_data *data);
int			init_sph(t_sphere *sph, const t_point3 *center, double r);

//color_convert.c
int			vec2trgb(t_color *color);
int			trgb2val(t_color *color);

//operate_mlx.c
int			image_create(t_data *data);
int			image_update(t_data *data);
int			my_mlx_pixel_put(t_image img, int x, int y, int color);

//vec_operations.c
t_vec3		new_vec3(double x, double y, double z);
int			edit_vec3(t_vec3 *v, double x, double y, double z);
t_vec3		vec_add(const t_vec3 *v1, const t_vec3 *v2);
int			vec_add_in(t_vec3 *v3, const t_vec3 *v1, const t_vec3 *v2);
t_vec3		vec_substract(const t_vec3 *v1, const t_vec3 *v2);
int			vec_substract_in(t_vec3 *v3, const t_vec3 *v1, const t_vec3 *v2);
t_vec3		vec_prod_2vec_comp_by_comp(const t_vec3 *v1, const t_vec3 *v2);
int			vec_prod_2vec_comp_by_comp_in(t_vec3 *v3, const t_vec3 *v1, const t_vec3 *v2);
t_vec3		vec_identity_number(double t);
int			vec_identity_number_in(t_vec3 *v, double t);
t_vec3		vec_prod_number(const t_vec3 *v, double t);
int			vec_prod_number_in(t_vec3 *v, double t);
t_vec3		vec_number_prod(double t, const t_vec3 *v);
int			vec_number_prod_in(double t, t_vec3 *v);
t_vec3		vec_div_number(const t_vec3 *v, double t);
int			vec_div_number_in(t_vec3 *v, double t);
double		vec_dot(const t_vec3 *v1, const t_vec3 *v2);
t_vec3		vec_cross(const t_vec3 *v1, const t_vec3 *v2);
int			vec_cross_in(t_vec3 *v3, const t_vec3 *v1, const t_vec3 *v2);
t_vec3		vec_unit(const t_vec3 *v);
int			vec_unit_in(t_vec3 *v);
double		vec_length(const t_vec3 *v);
double		vec_length_squared(const t_vec3 *v);
double		vec_index(const t_vec3 *v, int i);
int			display_vec(const t_vec3 *v);

//utils.c
void		*ft_calloc(size_t nmemb, size_t size);

//test.c
int			test_vec_operations(void);

//color_display.c
void		write_color(t_color pixel_color);

//geom_operations.c
int			edit_point3(t_point3 *p, double x, double y, double z);
t_point3	point_vec_add(const t_point3 *orig, const t_vec3 *vec);
t_point3	point_vec_substract(const t_point3 *orig, const t_vec3 *vec);
t_vec3		vec_orig_end(const t_point3 *orig, const t_point3 *end);

//ray_compute.c
t_point3	pos_at(const t_ray *ray, double t);
t_ray		ray_assign(const t_point3 *orig, const t_vec3 *dir);
t_color		ray_color_grad_blue(const t_ray *r);

//objects.c
double		hit_sphere(const t_sphere *sph, const t_ray *r);

//random.c
t_vec3		get_random_dev(const t_data *data);

#endif // RAY_TRACING

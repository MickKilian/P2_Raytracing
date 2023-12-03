/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:08:04 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/03 07:38:42 by mbourgeo         ###   ########.fr       */
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

# define	PI	3.1415926535897932385
// Aspect ratio : 16/9
# define	ASPECT_RATIO 1.777777778
# define	IMAGE_WIDTH 1920

typedef	struct s_httbl	t_httbl;

typedef enum	e_httbl_types {
	PLANE,
	SPHERE,
	CYLINDER,
	LEN_HTTBL_TYPES
}	t_httbl_types;

typedef enum	e_mat_types {
	LAMBERTIAN,
	METAL,
	LEN_MAT_TAYPES
}	t_mat_types;

typedef struct	s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct	s_interval
{
	double	min;
	double	max;
}	t_interval;

typedef struct	s_half_poly
{
	double	a;
	double	half_b;
	double	c;
	double	root_1;
	double	root_2;
}	t_half_poly;

typedef struct	s_ray
{
	t_vec3	orig;
	t_vec3	dir;
}	t_ray;

//typedef struct	s_color
//{
//	double	val;
//	t_vec3	vec;
//	double	trgb[4];
//	double	thsv[4];
//}	t_color;

typedef struct	s_trgb
{
	double	t;
	double	r;
	double	g;
	double	b;
}	t_trgb;

typedef struct	s_plane
{
	t_vec3	point;
	t_vec3	vec1;
	t_vec3	vec2;
}	t_plane;

typedef struct	s_sphere
{
	t_vec3	center;
	double	radius;
}	t_sphere;

typedef struct	s_cylinder
{
	t_vec3	base_center;
	t_vec3	generator;
	double	radius;
	double	height;
}	t_cylinder;

typedef struct	s_httbl {
	t_httbl_types	type;
	t_mat_types		mat;
	t_vec3			color;
	t_httbl			*next;
	union
	{
		t_plane		pln;
		t_sphere	sph;
		t_cylinder	cyl;
	};
}	t_httbl;

typedef struct	s_hit_rec {
	t_vec3		p;
	t_vec3		normal;
	double		t;
	bool		front_face;
	t_mat_types	mat;
	t_vec3		color;
}	t_hit_rec;

typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_image;

typedef struct	s_camera {
	t_vec3	center;
	double	focal_length;
	t_vec3	pixel00_loc;
	t_vec3	pixel_delta_u;
	t_vec3	pixel_delta_v;
	double	max_depth;
	int		samples_per_pixel;
}	t_camera;

typedef struct	s_world
{
	t_httbl		*httbl_head;
	t_httbl		*httbl;
	size_t		size;
}	t_world;

typedef struct	s_mlx
{
	void	*ptr;
	void	*win_ptr;
	t_image	image;
}	t_mlx;

typedef struct	s_rt
{
	double		aspect_ratio;
	int			img_width;
	int			img_height;
	t_mlx		mlx;
	t_camera	cam;
	t_world		world;
}	t_rt;

//All functions prototypes
//ray_tracing.c
int			ray_tracing(int argc, char **argv);

//rt_initialize.c
void		rt_initialize(t_rt *rt);

//camera.c
int			render(t_rt *rt);
void		cam_initialize(t_camera *cam, int img_width, int img_height);

//mlx.c
int			mlx_initialize(t_mlx *mlx, int img_width, int img_height);
int			image_create(t_mlx *mlx, int img_width, int img_height);
int			image_update(t_mlx *mlx);
int			my_mlx_pixel_put(t_image img, int x, int y, int color);

//color_convert.c
t_trgb		vec2trgb(const t_vec3 color);
t_vec3		lin2gam_vec(const t_vec3 lin);
double		trgb2val(const t_trgb color);

//vec_operations.c
t_vec3		new_vec3(double x, double y, double z);
//int			edit_vec3(t_vec3 *v, double x, double y, double z);
t_vec3		vec3_add2(const t_vec3 v1, const t_vec3 v2);
t_vec3		vec3_add3(const t_vec3 v1, const t_vec3 v2, const t_vec3 v3);
//int			vec_add_in(t_vec3 *v3, const t_vec3 *v1, const t_vec3 *v2);
t_vec3		vec3_substract2(const t_vec3 v1, const t_vec3 v2);
//int			vec_substract_in(t_vec3 *v3, const t_vec3 *v1, const t_vec3 *v2);
t_vec3		vec3_prod_comp_by_comp(const t_vec3 v1, const t_vec3 v2);
//int			vec_prod_2vec_comp_by_comp_in(t_vec3 *v3, const t_vec3 *v1, const t_vec3 *v2);
t_vec3		vec3_identity_number(double t);
//int			vec_identity_number_in(t_vec3 *v, double t);
//t_vec3		vec_prod_number(const t_vec3 *v, double t);
//nt			vec_prod_number_in(t_vec3 *v, double t);
t_vec3		vec3_scale(double t, t_vec3 v);
//int			vec_number_prod_in(double t, t_vec3 *v);
double		vec3_dot(const t_vec3 v1, const t_vec3 v2);
t_vec3		vec3_cross(const t_vec3 v1, const t_vec3 v2);
//int			vec_cross_in(t_vec3 *v3, const t_vec3 *v1, const t_vec3 *v2);
t_vec3		vec3_unit(const t_vec3 v);
//int			vec_unit_in(t_vec3 *v);
double		vec3_length(const t_vec3 v);
double		vec3_length_squared(const t_vec3 v);
double		vec3_index(const t_vec3 v, int i);
int			display_vec3(const t_vec3 v);
//t_vec3		vec3_2points(const t_vec3 orig, const t_vec3 end);
bool		near_zero(const t_vec3 vec);

//memory.c
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_bzero(void *ptr, const size_t size);
void		free_httbls(t_httbl *httbl);

//test.c
int			test_vec3_operations(void);

//color_display.c
void		write_color(t_vec3 pixel_color);

//geom_operations.c

//ray_color.c
t_vec3		ray_color(t_rt *rt, int depth, const t_ray r);
t_vec3		ray_color_grad_blue(const t_ray r);
t_vec3		ray_color_grad_red(const t_ray r);
t_vec3		ray_color_grad_violet(const t_ray r);
t_vec3		ray_color_grad_yellow(const t_ray r);
t_vec3		ray_color_grad_sunset(const t_ray r);
t_vec3		ray_color_red();

//ray_compute.c
t_vec3		hit_point(const t_ray r, double t);
t_ray		new_ray(const t_vec3 orig, const t_vec3 dir);
t_vec3		reflect(const t_vec3 v, const t_vec3 n);

//random.c
t_vec3		get_random_dev(const t_camera *cam);
double		random_double();
double		random_double_interval(double min, double max);
t_vec3		random_vec3_interval(double min, double max);
t_vec3		random_in_unit_sphere(void);
t_vec3		random_unit_vector(void);
t_vec3		random_in_same_hemisphere(const t_vec3 normal);

//world.c
int			world_initialize(t_world *world);
bool		world_hit(t_rt *rt, const t_ray r, t_interval tray, t_hit_rec *rec);
void		httbl_addback(t_world *world, t_httbl *new_httbl);

//httbl_create.c
t_httbl		*new_httbl_plane(t_plane pln, t_mat_types mat, t_vec3 color);
t_httbl		*new_httbl_sphere(t_sphere sph, t_mat_types mat, t_vec3 color);
t_httbl		*new_httbl_cylinder(t_cylinder cyl, t_mat_types mat, t_vec3 color);

//httbl_plane.c
t_plane		new_plane(const t_vec3 point, t_vec3 vec1, t_vec3 vec2);
bool		hit_plane(const t_rt *rt, const t_ray r, const t_interval tray, t_hit_rec *rec);

//httbl_sphere.c
t_sphere	new_sphere(const t_vec3 center, double r);
bool		hit_sphere(const t_rt *rt, const t_ray r, const t_interval tray, t_hit_rec *rec);

//httbl_cylinder.c
t_cylinder	new_cylinder(const t_vec3 base_center, t_vec3 generator, double radius, double height);
bool		hit_cylinder(const t_rt *rt, const t_ray r, const t_interval tray, t_hit_rec *rec);

//utils.c
double		ft_min(const double n1, const double n2);
double		deg_to_rad(double deg);
double		lin2gam_double(double linear);

//interval.c
t_interval	interval(double min, double max);
bool		contains(t_interval intrvl, double x);
bool		surrounds(t_interval intrvl, double x);
double		clamp(t_interval intrvl, double x);

//search_poly_root.c
bool		search_poly_root(t_half_poly *half_poly, const t_interval tray, double *root);
bool		solve_half_poly(t_half_poly *half_poly);

//hit_record.c
void		set_face_normal(const t_ray r, const t_vec3 outward_normal, t_hit_rec *rec);

//material_scatter.c
bool		lambertian_scatter(const t_ray r_in, const t_hit_rec rec, t_vec3 *attenuation, t_ray *scattered);
bool		metal_scatter(const t_ray r_in, const t_hit_rec rec, t_vec3 *attenuation, t_ray *scattered);

#endif // RAY_TRACING

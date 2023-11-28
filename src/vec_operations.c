/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 03:03:50 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/27 19:33:03 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

t_vec3	new_vec3(double x, double y, double z)
{
	t_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

int	edit_vec3(t_vec3 *v, double x, double y, double z)
{
	v->x = x;
	v->y = y;
	v->z = z;
	return 0;
}

t_vec3	vec_add(const t_vec3 *v1, const t_vec3 *v2)
{
	t_vec3	v3;

	v3.x = v1->x + v2->x;
	v3.y = v1->y + v2->y;
	v3.z = v1->z + v2->z;
	return (v3);
}

int	vec_add_in(t_vec3 *v3, const t_vec3 *v1, const t_vec3 *v2)
{
	v3->x = v1->x + v2->x;
	v3->y = v1->y + v2->y;
	v3->z = v1->z + v2->z;
	return 0;
}

t_vec3	vec_substract(const t_vec3 *v1, const t_vec3 *v2)
{
	t_vec3	v3;

	v3.x = v1->x - v2->x;
	v3.y = v1->y - v2->y;
	v3.z = v1->z - v2->z;
	return (v3);
}

int	vec_substract_in(t_vec3 *v3, const t_vec3 *v1, const t_vec3 *v2)
{
	v3->x = v1->x - v2->x;
	v3->y = v1->y - v2->y;
	v3->z = v1->z - v2->z;
	return 0;
}

t_vec3	vec_prod_2vec_comp_by_comp(const t_vec3 *v1, const t_vec3 *v2)
{
	t_vec3	v3;

	v3.x = v1->x * v2->x;
	v3.y = v1->y * v2->y;
	v3.z = v1->z * v2->z;
	return (v3);
}

int	vec_prod_2vec_comp_by_comp_in(t_vec3 *v3, const t_vec3 *v1, const t_vec3 *v2)
{
	v3->x = v1->x * v2->x;
	v3->y = v1->y * v2->y;
	v3->z = v1->z * v2->z;
	return 0;
}

t_vec3	vec_identity_number(double t)
{
	t_vec3	v;

	v.x = t;
	v.y = t;
	v.z = t;
	return (v);
}

int	vec_identity_number_in(t_vec3 *v, double t)
{
	v->x = t;
	v->y = t;
	v->z = t;
	return 0;
}

t_vec3	vec_prod_number(const t_vec3 *v, double t)
{
	t_vec3	v_res;

	v_res.x = v->x * t;
	v_res.y = v->y * t;
	v_res.z = v->z * t;
	return (v_res);
}

int	vec_prod_number_in(t_vec3 *v, double t)
{
	v->x *= t;
	v->y *= t;
	v->z *= t;
	return 0;
}

t_vec3	vec_number_prod(double t, const t_vec3 *v)
{
	t_vec3	v_res;
	
	v_res = vec_prod_number(v, t);
	return (v_res);
}

int	vec_number_prod_in(double t, t_vec3 *v)
{
	vec_prod_number_in(v, t);
	return 0;
}

t_vec3	vec_div_number(const t_vec3 *v, double t)
{
	t_vec3	v_res;

	v_res.x = v->x / t;
	v_res.y = v->y / t;
	v_res.z = v->z / t;
	return (v_res);
}

int	vec_div_number_in(t_vec3 *v, double t)
{
	v->x /= t;
	v->y /= t;
	v->z /= t;
	return 0;
}

double	vec_dot(const t_vec3 *v1, const t_vec3 *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_vec3	vec_cross(const t_vec3 *v1, const t_vec3 *v2)
{
	t_vec3	v3;

	v3.x = v1->y * v2->z - v1->z * v2->y;
	v3.y = v1->z * v2->x - v1->x * v2->z;
	v3.z = v1->x * v2->y - v1->y * v2->x;
	return (v3);
}

int	vec_cross_in(t_vec3 *v3, const t_vec3 *v1, const t_vec3 *v2)
{
	v3->x = v1->y * v2->z - v1->z * v2->y;
	v3->y = v1->z * v2->x - v1->x * v2->z;
	v3->z = v1->x * v2->y - v1->y * v2->x;
	return 0;
}

t_vec3	vec_unit(const t_vec3 *v)
{
	t_vec3	v_unit;

	if (vec_length(v))
		v_unit = vec_div_number(v, vec_length(v));
	else
		v_unit = new_vec3(0, 0, 0);
	return (v_unit);
}

int	vec_unit_in(t_vec3 *v)
{
	if (vec_length(v))
		vec_div_number_in(v, vec_length(v));
	return 0;
}

double	vec_length(const t_vec3 *v)
{
	return (sqrt(vec_length_squared(v)));
}

double	vec_length_squared(const t_vec3 *v)
{
	return (v->x * v->x + v->y * v->y + v->z * v->z);
}

double	vec_index(const t_vec3 *v, int i)
{
	return *((double *)v + (i % 3));
}

int	display_vec(const t_vec3 *v)
{
	printf("(%f, %f, %f)", v->x, v->y, v->z);
	return 0;
}

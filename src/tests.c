/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:39:34 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/27 19:34:15 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//****************************************************************************//
// I learned ray tracing using the following resources                        //
// Tuto rayTracing                                                            //
// https://raytracing.github.io/books/RayTracingInOneWeekend.html             //
//****************************************************************************//

#include "../inc/ray_tracing.h"

int	test_vec_operations(void) {

	//test type vec3
	printf("Tests operations on t_vec3, considering 3 vectors v1, v2, v3\n");
	t_vec3	v1;
	t_vec3	v2;
	t_vec3	v3;
	
	printf("  * initialization v1, v2:\n");
	edit_vec3(&v1, 1, 2, 3);
	display_vec(&v1);
	printf("\n");
	edit_vec3(&v2, 4, 5, 6);
	display_vec(&v2);
	printf("\n");

	printf("  * addition v3 = v1 + v2:\n");
	v3 = vec_add(&v1, &v2);
	display_vec(&v3);
	printf("\n");
	vec_add_in(&v3, &v1, &v2);
	display_vec(&v3);
	printf("\n");

	printf("  * substraction v3 = v1 + v2:\n");
	v3 = vec_substract(&v1, &v2);
	display_vec(&v3);
	printf("\n");
	vec_substract_in(&v3, &v1, &v2);
	display_vec(&v3);
	printf("\n");

	printf("  * product comp by comp v3 = v1 * v2:\n");
	v3 = vec_prod_2vec_comp_by_comp(&v1, &v2);
	display_vec(&v3);
	printf("\n");
	vec_prod_2vec_comp_by_comp_in(&v3, &v1, &v2);
	display_vec(&v3);
	printf("\n");

	printf("  * addition v1 = v1 + v2, followed by substraction v1 = v1 - v2:\n");
	vec_add_in(&v1, &v1, &v2);
	display_vec(&v1);
	printf("\n");
	vec_substract_in(&v1, &v1, &v2);
	display_vec(&v1);
	printf("\n");

	printf("  * identity v = number:\n");
	v3 = vec_identity_number(55);
	display_vec(&v3);
	printf("\n");
	vec_identity_number_in(&v3, 55);
	display_vec(&v3);
	printf("\n");

	printf("  * product by a number after v1 = v1 * 2:\n");
	v3 = vec_prod_number(&v1, 2);
	display_vec(&v3);
	printf("\n");
	vec_prod_number_in(&v1, 2);
	display_vec(&v1);
	printf("\n");
	printf("  * product by a number before v1 = 2 * v1:\n");
	v3 = vec_number_prod(2, &v1);
	display_vec(&v3);
	printf("\n");
	vec_number_prod_in(2, &v1);
	display_vec(&v1);
	printf("\n");
	printf("  * division by a number v1 = v1 / 3:\n");
	v3 = vec_div_number(&v1, 3);
	display_vec(&v3);
	printf("\n");
	vec_div_number_in(&v1, 3);
	display_vec(&v1);
	printf("\n");
	printf("  * reinitialization v1(1, 2, 3):\n");
	v1 = new_vec3(1, 2, 3);
	display_vec(&v1);
	printf("\n");

	printf("  * dot product v1.v2:\n");
	printf("%f\n", vec_dot(&v1, &v2));
	printf("  * cross product v1 x v2:\n");
	v3 = vec_cross(&v1, &v2);
	display_vec(&v3);
	printf("\n");
	vec_cross_in(&v3, &v1, &v2);
	display_vec(&v3);
	printf("\n");

	printf("  * unit vec v1:\n");
	v3 = vec_unit(&v1);
	display_vec(&v3);
	printf("\n");
	vec_unit_in(&v1);
	display_vec(&v1);
	printf("\n");
	printf("  * reinitialization v1(1, 2, 3):\n");
	v1 = new_vec3(1, 2, 3);
	display_vec(&v1);
	printf("\n");

	printf("  * length_squared v1:\n");
	printf("%f\n", vec_length_squared(&v1));
	printf("  * length v1:\n");
	printf("%f\n", vec_length(&v1));

	printf("  * index v1[0]; v2[1]:\n");
	printf("v1[x] = %f\n", vec_index(&v1, 0));
	printf("v2[y] = %f\n", vec_index(&v2, 1));
	return 0;
}

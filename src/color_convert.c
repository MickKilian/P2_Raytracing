/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:51:59 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/02 07:53:05 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

t_trgb	vec2trgb(const t_vec3 color)
{
	t_trgb	color_trgb;

	color_trgb.t = 0;
	color_trgb.r = (int)(255.999 * color.x);
	color_trgb.g = (int)(255.999 * color.y);
	color_trgb.b = (int)(255.999 * color.z);
	return (color_trgb);
}

t_vec3	lin2gam_vec(const t_vec3 lin)
{
	t_vec3	gamma;

	gamma.x = lin2gam_double(lin.x);
	gamma.y = lin2gam_double(lin.y);
	gamma.z = lin2gam_double(lin.z);
	return (gamma);
}

double	trgb2val(const t_trgb color)
{
	double	val;

	val = (int)color.t << 24 | (int)color.r << 16
		| (int)color.g << 8 | (int)color.b;
	return (val);
}

/*
int	val2trgb(t_vec3 *color)
{
	color->trgb[0] = ((color->val >> 24) & 0xFF);
	color->trgb[1] = ((color->val >> 16) & 0xFF);
	color->trgb[2] = ((color->val >> 8) & 0xFF);
	color->trgb[3] = ((color->val) & 0xFF);
	return (0);
}

int	thsv2trgb(t_vec3 *c)
{
	double	m;
	double	n;
	double	z;
	int		k;

	m = 255 * c->thsv[3];
	n = m * (1 - c->thsv[2]);
	z = (m - n) * (1 - ft_abs(ft_modulo((c->thsv[1] / 60), 2) - 1));
	z += n;
	k = c->thsv[1] / 60 + 1;
	c->trgb[0] = c->thsv[0];
	c->trgb[1] = (k == 1 || k == 6) * m + (k == 3 || k == 4) * n
		+ (k == 2 || k == 5) * z;
	c->trgb[2] = (k == 2 || k == 3) * m + (k == 5 || k == 6) * n
		+ (k == 1 || k == 4) * z;
	c->trgb[3] = (k == 4 || k == 5) * m + (k == 1 || k == 2) * n
		+ (k == 3 || k == 6) * z;
	trgb2val(c);
	return (0);
}
*/

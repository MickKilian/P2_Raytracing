/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:51:59 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/26 07:56:09 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

int	vec2trgb(t_color *color)
{
	color->trgb[0] = 0;
	color->trgb[1] = (int)(255.999 * color->vec.x);
	color->trgb[2] = (int)(255.999 * color->vec.y);
	color->trgb[3] = (int)(255.999 * color->vec.z);
	return (0);
}

int	trgb2val(t_color *color)
{
	color->val = (int)color->trgb[0] << 24 | (int)color->trgb[1] << 16
		| (int)color->trgb[2] << 8 | (int)color->trgb[3];
	return (0);
}

/*
int	val2trgb(t_color *color)
{
	color->trgb[0] = ((color->val >> 24) & 0xFF);
	color->trgb[1] = ((color->val >> 16) & 0xFF);
	color->trgb[2] = ((color->val >> 8) & 0xFF);
	color->trgb[3] = ((color->val) & 0xFF);
	return (0);
}

int	thsv2trgb(t_color *c)
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

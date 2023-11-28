/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 07:26:39 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/26 07:51:13 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

void	write_color(t_color pixel_color)
{
    // Write the translated [0,255] value of each color component.
    printf("%d %d %d\n", (int)(255.999 * pixel_color.vec.x), (int)(255.999 * pixel_color.vec.y), (int)(255.999 * pixel_color.vec.z));
}

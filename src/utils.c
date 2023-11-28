/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 03:58:51 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/11/26 04:05:25 by mbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray_tracing.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*temp;

	temp = malloc(nmemb * size);
	if (!temp)
		return (NULL);
	ft_bzero(temp, nmemb * size);
	return (temp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourgeo <mbourgeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:24:57 by mbourgeo          #+#    #+#             */
/*   Updated: 2023/12/02 22:00:14 by mbourgeo         ###   ########.fr       */
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

//int	allocator(void *ptr, size_t size)
//{
//	*(void **)ptr = malloc(size);
//	if (!*(void **)ptr)
//		return (1);
//	ft_bzero(*(void **)ptr, size);
//	return (0);
//}

void	ft_bzero(void *ptr, const size_t size)
{
	size_t	i;
	char	*str;

	if (!ptr)
		return ;
	i = 0;
	str = (char *)ptr;
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
}

void	free_httbls(t_httbl *httbl)
{
	t_httbl	*temp;

	temp = httbl;
	while (httbl)
	{
		httbl = httbl->next;
		free(temp);
		temp = httbl;
	}
}

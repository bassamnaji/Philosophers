/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locks_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:32:49 by bnaji             #+#    #+#             */
/*   Updated: 2022/03/01 17:57:29 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	locks_allocater(t_info *info)
{
	int	i;

	info->locks = (pthread_mutex_t **)malloc(sizeof(pthread_mutex_t *)
			* (info->n_of_philos));
	if (!info->locks)
		error(6, info);
	i = 0;
	while (i < info->n_of_philos)
		info->locks[i++] = NULL;
	i = 0;
	while (i < info->n_of_philos)
	{
		info->locks[i] = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
				* (info->n_of_philos));
		if (!info->locks[i++])
			error(6, info);
	}
	info->is_dead = (int *)malloc(sizeof(int));
	if (!info->is_dead)
		error(6, info);
	*info->is_dead = 0;
	info->useless_time = (unsigned long *)malloc(sizeof(unsigned long));
	if (!info->useless_time)
		error(6, info);
	*info->useless_time = 0;
	// info->death_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
	// 		* (info->n_of_philos));
	// if (info->death_lock)
	// 	error(6, info);
}

void	locks_creater(t_info *info)
{
	int	i;

	locks_allocater(info);
	i = 0;
	while (i < info->n_of_philos)
	{
		pthread_mutex_init(info->locks[i], NULL);
		info->philo[i].l_lock = info->locks[i];
		if (i == info->n_of_philos - 1)
			info->philo[i].r_lock = info->locks[0];
		else
			info->philo[i].r_lock = info->locks[i + 1];
		i++;
	}
	// pthread_mutex_init(info->death_lock, NULL);
}

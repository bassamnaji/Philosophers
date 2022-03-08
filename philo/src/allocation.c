/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 09:12:27 by bnaji             #+#    #+#             */
/*   Updated: 2022/03/08 09:27:42 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	locks_allocation(t_info *info)
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
		info->locks[i] = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (!info->locks[i++])
			error(6, info);
	}
}

static void	forks_allocation(t_info *info)
{
	int	i;

	info->forks = (int **)malloc(sizeof(int *)
			* (info->n_of_philos));
	if (!info->forks)
		error(6, info);
	i = 0;
	while (i < info->n_of_philos)
		info->forks[i++] = NULL;
	i = 0;
	while (i < info->n_of_philos)
	{
		info->forks[i] = (int *)malloc(sizeof(int)
				* (info->n_of_philos));
		if (!info->forks[i++])
			error(6, info);
	}
}

void	main_allocation(t_info *info)
{
	locks_allocation(info);
	forks_allocation(info);
	info->is_dead = (int *)malloc(sizeof(int));
	if (!info->is_dead)
		error(6, info);
	*info->is_dead = 0;
	info->useless_time = (unsigned long *)malloc(sizeof(unsigned long));
	if (!info->useless_time)
		error(6, info);
	*info->useless_time = 0;
	info->death_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!info->death_lock)
		error(6, info);
}

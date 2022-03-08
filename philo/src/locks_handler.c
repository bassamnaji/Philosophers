/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locks_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:32:49 by bnaji             #+#    #+#             */
/*   Updated: 2022/03/08 09:31:00 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	locks_n_forks_assigner(t_info *info, int i)
{
	*info->forks[i] = 1;
	info->philo[i].l_fork = info->forks[i];
	info->philo[i].l_lock = info->locks[i];
	if (i == info->n_of_philos - 1)
	{
		info->philo[i].r_fork = info->forks[0];
		info->philo[i].r_lock = info->locks[0];
	}
	else
	{
		info->philo[i].r_fork = info->forks[i + 1];
		info->philo[i].r_lock = info->locks[i + 1];
	}
}

void	locks_creater(t_info *info)
{
	int	i;

	main_allocation(info);
	i = 0;
	while (i < info->n_of_philos)
	{
		pthread_mutex_init(info->locks[i], NULL);
		locks_n_forks_assigner(info, i);
		i++;
	}
	pthread_mutex_init(info->death_lock, NULL);
}

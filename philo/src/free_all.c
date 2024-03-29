/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 10:52:28 by bnaji             #+#    #+#             */
/*   Updated: 2022/03/08 10:12:56 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	free_big_data(t_info *info)
{
	int	i;

	if (info->locks)
	{
		i = 0;
		while (i < info->n_of_philos)
		{
			if (info->locks[i])
				free(info->locks[i++]);
		}
		free(info->locks);
	}
	if (info->forks)
	{
		i = 0;
		while (i < info->n_of_philos)
		{
			if (info->forks[i])
				free(info->forks[i++]);
		}
		free(info->forks);
	}
}

void	main_free(t_info *info)
{
	if (info->thread)
		free(info->thread);
	if (info->is_dead)
		free(info->is_dead);
	if (info->death_lock)
		free(info->death_lock);
	if (info->useless_time)
		free(info->useless_time);
	if (info->philo)
		free(info->philo);
	free_big_data(info);
}

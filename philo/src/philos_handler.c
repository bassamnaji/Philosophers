/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:34:02 by bnaji             #+#    #+#             */
/*   Updated: 2022/03/08 13:39:10 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	take_forks(t_philo *philo)
{
	philo->is_ready = 0;
	if (philo->n_of_philos == 1)
		return (0);
	philo->ref_time = updated_current_time(philo, 'r');
	if (ft_eat(philo))
		return (1);
	if (philo->n_times_of_eat > 0)
		philo->n_times_of_eat--;
	return (0);
}

// A normal C function that is executed as a thread 
// when its name is specified in pthread_create()
void	*philo_manager(void *vargp)
{
	t_philo	*philo;

	philo = (t_philo *)vargp;
	while (philo->n_times_of_eat)
	{
		if (is_dead_flag(philo))
			return (NULL);
		if (is_it_dead(philo))
			return (NULL);
		if (!(philo->philo_id % 2))
		{
			if (is_even(philo))
				return (NULL);
		}
		else if (philo->philo_id % 2)
		{
			if (is_odd(philo))
				return (NULL);
		}
		if (philo->is_ready)
			if (take_forks(philo))
				return (NULL);
	}
	return (NULL);
}

void	philos_creator(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_of_philos)
	{
		if (!i)
			*info->useless_time = updated_current_time(info->philo, 'r');
		philo_init(info, i);
		i++;
		usleep(100);
	}
	i = 0;
	while (i < info->n_of_philos)
	{
		pthread_join(info->thread[i], NULL);
		i++;
	}
	i = 0;
	while (i < info->n_of_philos)
		pthread_mutex_destroy(info->locks[i++]);
}

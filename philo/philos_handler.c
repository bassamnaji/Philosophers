/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:34:02 by bnaji             #+#    #+#             */
/*   Updated: 2022/03/06 20:04:25 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks(t_philo *philo)
{
	if (philo->n_of_philos == 1)
		return (0);
	pthread_mutex_lock(philo->l_lock);
	if (*philo->is_dead)
		return (1);
	pthread_mutex_lock(philo->death_lock);
	printer(philo, 'f');
	pthread_mutex_unlock(philo->death_lock);
	pthread_mutex_lock(philo->r_lock);
	if (*philo->is_dead)
		return (1);
	pthread_mutex_lock(philo->death_lock);
	printer(philo, 'f');
	pthread_mutex_unlock(philo->death_lock);
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
	philo->ref_time = *philo->useless_time;
	while (philo->n_times_of_eat && !*philo->is_dead)
	{
		if (updated_current_time(philo, 'r') - philo->ref_time
			> (unsigned long)philo->t_2_die)
		{
			if (*philo->is_dead)
				return (NULL);
			ft_die(philo);
			pthread_mutex_unlock(philo->l_lock);
			pthread_mutex_unlock(philo->r_lock);
			return (NULL);
		}
		if (take_forks(philo))
		{
			pthread_mutex_unlock(philo->l_lock);
			pthread_mutex_unlock(philo->r_lock);
			return (NULL);
		}
	}
	return (NULL);
}

void	philos_creator(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->n_of_philos)
	{
		if (!(i % 2))
			philo_init(info, i);
		if (!i)
			*info->useless_time = updated_current_time(info->philo, 'r');
		i++;
	}
	usleep(1000);
	i = 0;
	while (i < info->n_of_philos)
	{
		if (i % 2)
			philo_init(info, i);
		i++;
	}
	i = 0;
	while (i < info->n_of_philos)
	{
		pthread_join(info->thread[i], NULL);
		if (info->philo[i].just_died)
		{
			j = 0;
			while (j < info->n_of_philos)
				pthread_mutex_unlock(info->philo[j++].l_lock);
		}
		i++;
	}
	i = 0;
	while (i < info->n_of_philos)
		pthread_mutex_destroy(info->locks[i++]);
}

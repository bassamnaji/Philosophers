/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:34:02 by bnaji             #+#    #+#             */
/*   Updated: 2022/03/01 17:56:24 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks(t_philo *philo)
{
	if (philo->n_of_philos == 1)
		return (0);
	pthread_mutex_lock(philo->l_lock);
	if (*philo->is_dead)
	{
		return (1);
	}
	printf("%s%d %d has taken a fork%s\n", GREEN,
		updated_current_time(philo, 'c'), philo->philo_id + 1, NO_COLOR);
	pthread_mutex_lock(philo->r_lock);
	if (*philo->is_dead)
	{
		return (1);
	}
	printf("%s%d %d has taken a fork%s\n", GREEN,
		updated_current_time(philo, 'c'), philo->philo_id + 1, NO_COLOR);
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
		// printf("dead: %d\n", philo->is_dead);
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
		{
			info->philo[i].is_dead = info->is_dead;
			info->philo[i].is_dead = info->is_dead;
			info->philo[i].just_died = 0;
			info->philo[i].philo_id = i;
			info->philo[i].is_dead = info->is_dead;
			info->philo[i].n_of_philos = info->n_of_philos;
			info->philo[i].t_2_die = info->t_2_die;
			info->philo[i].t_2_eat = info->t_2_eat;
			info->philo[i].t_2_sleep = info->t_2_sleep;
			info->philo[i].n_times_of_eat = info->n_times_of_eat;
			pthread_create(&info->thread[i], NULL, &philo_manager, &info->philo[i]);
		}
		if (!i)
			*info->useless_time = updated_current_time(info->philo, 'r');
		i++;
	}
	usleep(1000);
	i = 0;
	while (i < info->n_of_philos)
	{
		if (i % 2)
		{
			info->philo[i].is_dead = info->is_dead;
			info->philo[i].just_died = 0;
			info->philo[i].philo_id = i;
			info->philo[i].is_dead = info->is_dead;
			info->philo[i].n_of_philos = info->n_of_philos;
			info->philo[i].t_2_die = info->t_2_die;
			info->philo[i].t_2_eat = info->t_2_eat;
			info->philo[i].t_2_sleep = info->t_2_sleep;
			info->philo[i].n_times_of_eat = info->n_times_of_eat;
			pthread_create(&info->thread[i], NULL, &philo_manager, &info->philo[i]);
		}
		i++;
	}
	// printf("P: %d\n", info->philo[0].is_dead);
	i = 0;
	while (i < info->n_of_philos)
	{
		pthread_join(info->thread[i], NULL);
		// printf("i: %d\n", i);
		if (info->philo[i].just_died)
		{
			// j = 0;
			printf("id: %d\n", info->philo[i].philo_id + 1);
			// while (j < info->n_of_philos)
			// 	info->philo[j++].is_dead = 1;
			j = 0;
			while (j < info->n_of_philos)
				pthread_mutex_unlock(info->philo[j++].l_lock);
			// pthread_mutex_unlock(info->philo[i + 1].l_lock);
			// pthread_mutex_unlock(info->philo[i + 1].r_lock);
		}
		i++;
	}
	i = 0;
	while (i < info->n_of_philos)
		pthread_mutex_destroy(info->locks[i++]);
	// pthread_mutex_destroy(info->death_lock);
}

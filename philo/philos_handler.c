/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:34:02 by bnaji             #+#    #+#             */
/*   Updated: 2022/02/26 14:34:29 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	if (philo->n_of_philos == 1)
		return ;
	pthread_mutex_lock(philo->l_lock);
	printf("%s%d %d has taken a fork%s\n", GREEN,
		updated_current_time(philo, 'c'), philo->philo_id + 1, NO_COLOR);
	pthread_mutex_lock(philo->r_lock);
	printf("%s%d %d has taken a fork%s\n", GREEN,
		updated_current_time(philo, 'c'), philo->philo_id + 1, NO_COLOR);
	philo->ref_time = updated_current_time(philo, 'r');
	ft_eat(philo);
	if (philo->n_times_of_eat > 0)
		philo->n_times_of_eat--;
}

// A normal C function that is executed as a thread 
// when its name is specified in pthread_create()
void	*philo_manager(void *vargp)
{
	t_philo	*philo;

	philo = (t_philo *)vargp;
	philo->useless_time = 0;
	philo->useless_time = updated_current_time(philo, 'r');
	philo->ref_time = philo->useless_time;
	while (philo->n_times_of_eat)
	{
		if (updated_current_time(philo, 'r') - philo->ref_time
			> (unsigned long)philo->t_2_die)
			ft_die(philo);
		take_forks(philo);
	}
	return (NULL);
}

void	philos_creator(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_of_philos)
	{
		info->philo[i].philo_id = i;
		info->philo[i].n_of_philos = info->n_of_philos;
		info->philo[i].t_2_die = info->t_2_die;
		info->philo[i].t_2_eat = info->t_2_eat;
		info->philo[i].t_2_sleep = info->t_2_sleep;
		info->philo[i].n_times_of_eat = info->n_times_of_eat;
		pthread_create(&info->thread[i], NULL, &philo_manager, &info->philo[i]);
		if (!(i % 2))
			usleep(10000);
		i++;
	}
	i = 0;
	while (i < info->n_of_philos)
		pthread_join(info->thread[i++], NULL);
	i = 0;
	while (i < info->n_of_philos)
		pthread_mutex_destroy(info->locks[i++]);
}

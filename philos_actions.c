/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:18:10 by bnaji             #+#    #+#             */
/*   Updated: 2022/02/20 21:25:31 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	printf("%d %d has taken a fork\n", philo->c_time, philo->philo_id);
	printf("%d %d is eating\n", philo->c_time, philo->philo_id);
	usleep(1000 * philo->t_2_eat);
	pthread_mutex_unlock(philo->l_lock);
	pthread_mutex_unlock(philo->r_lock);
	ft_sleep(philo);
}

void	ft_sleep(t_philo *philo)
{
	printf("%d %d is sleeping\n", philo->c_time, philo->philo_id);
	usleep(1000 * philo->t_2_sleep);
	ft_think(philo);
}

void	ft_think(t_philo *philo)
{
	printf("%d %d is thinking\n", philo->c_time, philo->philo_id);
	// if (philo->t_2_die < 2)
	// 	philo->t_2_die = 1;
}

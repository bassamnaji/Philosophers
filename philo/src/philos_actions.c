/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:18:10 by bnaji             #+#    #+#             */
/*   Updated: 2022/03/07 20:30:28 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_eat(t_philo *philo)
{
	if (*philo->is_dead)
		return (1);
	pthread_mutex_lock(philo->death_lock);
	printer(philo, 'e');
	pthread_mutex_unlock(philo->death_lock);
	if (ft_usleep(philo, 'e'))
	{
		return (1);
	}
	*philo->l_fork = 1;
	*philo->r_fork = 1;
	if (ft_sleep(philo))
		return (1);
	return (0);
}

int	ft_sleep(t_philo *philo)
{
	if (*philo->is_dead)
		return (1);
	pthread_mutex_lock(philo->death_lock);
	printer(philo, 's');
	pthread_mutex_unlock(philo->death_lock);
	if (ft_usleep(philo, 's'))
		return (1);
	if (ft_think(philo))
		return (1);
	return (0);
}

int	ft_think(t_philo *philo)
{
	if (*philo->is_dead)
		return (1);
	pthread_mutex_lock(philo->death_lock);
	printer(philo, 't');
	pthread_mutex_unlock(philo->death_lock);
	return (0);
}

void	ft_die(t_philo *philo)
{
	pthread_mutex_lock(philo->death_lock);
	printer(philo, 'd');
	*philo->is_dead = 1;
	*philo->l_fork = 1;
	*philo->r_fork = 1;
	pthread_mutex_unlock(philo->death_lock);
}

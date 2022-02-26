/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:18:10 by bnaji             #+#    #+#             */
/*   Updated: 2022/02/26 10:08:04 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_eat(t_philo *philo)
{
	printf("%s%d %d is eating%s\n", IYELLOW,
		updated_current_time(philo, 'c'), philo->philo_id + 1, NO_COLOR);
	if (ft_usleep(philo, 'e'))
		;
	pthread_mutex_unlock(philo->l_lock);
	pthread_mutex_unlock(philo->r_lock);
	ft_sleep(philo);
	return (0);
}

int	ft_sleep(t_philo *philo)
{
	printf("%s%d %d is sleeping%s\n", LIGHT_BLUE,
		updated_current_time(philo, 'c'), philo->philo_id + 1, NO_COLOR);
	if (ft_usleep(philo, 's'))
		;
	ft_think(philo);
	return (0);
}

void	ft_think(t_philo *philo)
{
	printf("%s%d %d is thinking%s\n", PURPLE,
		updated_current_time(philo, 'c'), philo->philo_id + 1, NO_COLOR);
}

void	ft_die(t_philo *philo)
{
	printf("%s%d %d died%s\n", RED,
		updated_current_time(philo, 'c'), philo->philo_id + 1, NO_COLOR);
	exit (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:01:53 by bnaji             #+#    #+#             */
/*   Updated: 2022/02/14 10:59:11 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	reset(t_philo *philo)
{
	philo->n_of_philos = 0;
	philo->t_2_die = 0;
	philo->t_2_eat = 0;
	philo->t_2_sleep = 0;
	philo->philo_status = 0;
	philo->philo_id = 0;
	philo->n_times_of_eat = 0;
}

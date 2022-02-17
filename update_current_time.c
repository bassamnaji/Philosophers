/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_current_time.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:20:52 by bnaji             #+#    #+#             */
/*   Updated: 2022/02/14 10:58:04 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	updated_current_time(t_philo *philo)
{
	gettimeofday(&philo->current_time, NULL);
	philo->c_time = philo->current_time.tv_usec / 1000;
	// printf("time was %d\n", philo->current_time.tv_usec / 1000);
	// usleep(1000);
	// gettimeofday(&philo->current_time, NULL);
	// printf("time now %d\n", philo->current_time.tv_usec / 1000);
	// printf("difference %d\n", philo->current_time.tv_usec / 1000 - philo->c_time);
}

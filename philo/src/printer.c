/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 08:00:54 by bnaji             #+#    #+#             */
/*   Updated: 2022/03/08 08:55:49 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	printer(t_philo *philo, char c)
{
	int	tmp;

	if (*philo->is_dead)
		return ;
	tmp = updated_current_time(philo, 'c');
	if (c == 'f')
		printf("%s%d %d has taken a fork%s\n", GREEN,
			tmp, philo->philo_id + 1, NO_COLOR);
	else if (c == 'e')
		printf("%s%d %d is eating%s\n", IYELLOW,
			tmp, philo->philo_id + 1, NO_COLOR);
	else if (c == 's')
		printf("%s%d %d is sleeping%s\n", LIGHT_BLUE,
			tmp, philo->philo_id + 1, NO_COLOR);
	else if (c == 't')
		printf("%s%d %d is thinking%s\n", PURPLE,
			tmp, philo->philo_id + 1, NO_COLOR);
	else if (c == 'd')
		printf("%s%d %d died%s\n", RED,
			tmp, philo->philo_id + 1, NO_COLOR);
}

void	lock_n_print(t_philo *philo, char c)
{
	pthread_mutex_lock(philo->death_lock);
	printer(philo, c);
	pthread_mutex_unlock(philo->death_lock);
}

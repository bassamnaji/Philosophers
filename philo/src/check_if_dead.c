/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:58:22 by bnaji             #+#    #+#             */
/*   Updated: 2022/03/07 20:33:12 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	is_it_dead(t_philo *philo)
{
	if (updated_current_time(philo, 'r') - philo->ref_time
		> (unsigned long)philo->t_2_die)
	{
		if (*philo->is_dead)
		{
			*philo->l_fork = 1;
			*philo->r_fork = 1;
			return (1);
		}
		ft_die(philo);
		return (1);
	}
	return (0);
}

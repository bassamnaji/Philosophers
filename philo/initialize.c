/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:01:53 by bnaji             #+#    #+#             */
/*   Updated: 2022/02/26 11:00:16 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init(t_info *info)
{
	info->n_of_philos = 0;
	info->t_2_die = 0;
	info->t_2_eat = 0;
	info->t_2_sleep = 0;
	info->n_times_of_eat = -1;
	info->locks = NULL;
	info->thread = NULL;
	info->philo = NULL;
}

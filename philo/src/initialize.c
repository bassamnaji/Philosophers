/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 15:01:53 by bnaji             #+#    #+#             */
/*   Updated: 2022/03/07 20:30:19 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init(t_info *info)
{
	info->n_of_philos = 0;
	info->t_2_die = 0;
	info->t_2_eat = 0;
	info->t_2_sleep = 0;
	info->n_times_of_eat = -1;
	info->locks = NULL;
	info->cnt = NULL;
	info->is_dead = NULL;
	info->useless_time = NULL;
	info->thread = NULL;
	info->philo = NULL;
	info->forks = NULL;
}

void	philo_init(t_info *info, int i)
{
	info->philo[i].is_dead = info->is_dead;
	info->philo[i].death_lock = info->death_lock;
	info->philo[i].cnt_lock = info->cnt_lock;
	// info->philo[i].locks = info->locks[i];
	info->philo[i].useless_time = info->useless_time;
	info->philo[i].ref_time = *info->useless_time;
	info->philo[i].is_ready = 0;
	info->philo[i].philo_id = i;
	info->philo[i].is_dead = info->is_dead;
	info->philo[i].cnt = info->cnt;
	info->philo[i].n_of_philos = info->n_of_philos;
	info->philo[i].t_2_die = info->t_2_die;
	info->philo[i].t_2_eat = info->t_2_eat;
	info->philo[i].t_2_sleep = info->t_2_sleep;
	info->philo[i].n_times_of_eat = info->n_times_of_eat;
	pthread_create(&info->thread[i], NULL, &philo_manager, &info->philo[i]);
}

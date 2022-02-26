/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:31:52 by bnaji             #+#    #+#             */
/*   Updated: 2022/02/26 10:31:02 by bnaji            ###   ########.fr       */
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
	int		i;

	philo = (t_philo *)vargp;
	philo->useless_time = 0;
	philo->useless_time = updated_current_time(philo, 'r');
	philo->ref_time = philo->useless_time;
	while (philo->n_times_of_eat)
	{
		if (updated_current_time(philo, 'r') - philo->ref_time > philo->t_2_die)
			ft_die(philo);
		take_forks(philo);
	}
	return (NULL);
}

void	locks_creater(t_info *info)
{
	int	i;

	info->locks = (pthread_mutex_t **)malloc(sizeof(pthread_mutex_t *)
			* (info->n_of_philos));
	if (!info->locks)
		error(6);
	i = 0;
	while (i < info->n_of_philos)
	{
		info->locks[i] = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
				* (info->n_of_philos));
		if (!info->locks[i++])
			error(6);
	}
	i = 0;
	while (i < info->n_of_philos)
	{
		pthread_mutex_init(info->locks[i], NULL);
		info->philo[i].l_lock = info->locks[i];
		if (i == info->n_of_philos - 1)
			info->philo[i].r_lock = info->locks[0];
		else
			info->philo[i].r_lock = info->locks[i + 1];
		i++;
	}
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
			usleep(info->philo[i].t_2_eat / 1000);
		i++;
	}
	i = 0;
	while (i < info->n_of_philos)
		pthread_join(info->thread[i++], NULL);
	i = 0;
	while (i < info->n_of_philos)
		pthread_mutex_destroy(info->locks[i++]);
}

int	main(int ac, char **av)
{
	int			i;
	t_info		info;

	if (ac < 5 || ac > 6)
		error(1);
	i = 0;
	while (++i < ac)
		num_parser(i, av[i], &info);
	if (ac == 5)
		info.n_times_of_eat = -1;
	locks_creater(&info);
	philos_creator(&info);
	return (0);
}

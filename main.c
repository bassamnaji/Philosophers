/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:31:52 by bnaji             #+#    #+#             */
/*   Updated: 2022/02/20 21:26:36 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// A normal C function that is executed as a thread 
// when its name is specified in pthread_create()
void	*philo_manager(void *vargp)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)vargp;
	philo->useless_time = updated_current_time(philo);
	// i = 2;
	while (1)
	{
		pthread_mutex_lock(philo->l_lock);
		pthread_mutex_lock(philo->r_lock);
		// printf("%d %d has taken a fork\n", updated_current_time(philo), philo->philo_id + 1);
		// sleep(2);
		ft_eat(philo);
		// printf("p: %p\t pi: %p\n", philo->l_lock, philo->r_lock);
		// pthread_mutex_unlock(philo->l_lock);
		// pthread_mutex_unlock(philo->r_lock);
		// sleep(2);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	int			i;
	int			j;
	t_philo		*philo;
	t_info		info;
	int			nb;

	if (ac < 5 || ac > 6)
		error(1);
	i = 1;
	while (i < ac)
	{
		nb = num_parser(i, av[i]);
		if (i == 1)
		{
			// printf("nb: %d\n", nb);
			info.philo = (t_philo *)malloc(sizeof(t_philo) * (nb));
			info.thread = (pthread_t *)malloc(sizeof(pthread_t) * (nb));
			if (!info.philo || !info.thread)
				error(6);
			info.n_of_philos = nb;
		}
		if (i == 2)
			info.t_2_die = nb;
		else if (i == 3)
			info.t_2_eat = nb;
		else if (i == 4)
			info.t_2_sleep = nb;
		else if (i == 5)
			info.n_times_of_eat = nb;
		i++;
	}
	// updated_current_time(&philo);
	info.locks = (pthread_mutex_t **)malloc(sizeof(pthread_mutex_t *) * (info.n_of_philos));
	if (!info.locks)
		error(6);
	i = 0;
	while (i < info.n_of_philos)
	{
		info.locks[i]= (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (info.n_of_philos));
		if (!info.locks)
			error(6);
		i++;
	}
	i = 0;
	while (i < info.n_of_philos)
	{
		// printf("i= %d\n", i);
		pthread_mutex_init(info.locks[i], NULL);
		info.philo[i].l_lock = info.locks[i];
		if (i == info.n_of_philos - 1)
			info.philo[i].r_lock = info.locks[0];
		else
			info.philo[i].r_lock = info.locks[i + 1];
		// printf("p: %p\t pi: %p\n", info.philo[i].l_lock, info.philo[i].r_lock);
		i++;
	}
	i = 0;
	while (i < info.n_of_philos)
	{
		info.philo[i].philo_id = i;
		info.philo[i].n_of_philos = info.n_of_philos;
		info.philo[i].t_2_die = info.t_2_die;
		info.philo[i].t_2_eat = info.t_2_eat;
		info.philo[i].t_2_sleep = info.t_2_sleep;
		info.philo[i].n_times_of_eat = info.n_times_of_eat;
		pthread_create(&info.thread[i], NULL, &philo_manager, &info.philo[i]);
		i++;
	}
	i = 0;
	while (i < info.n_of_philos)
		pthread_join(info.thread[i++], NULL);
	i = 0;
	while (i < info.n_of_philos)
		pthread_mutex_destroy(info.locks[i++]);
	printf("After Threads\n");
	return (0);
}

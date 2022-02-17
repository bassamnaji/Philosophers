/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:29:48 by bnaji             #+#    #+#             */
/*   Updated: 2022/02/16 16:53:23 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				philo_id;
	int				n_of_philos;
	int				t_2_die;
	int				t_2_eat;
	int				t_2_sleep;
	int				n_times_of_eat;
	struct timeval	current_time;
	int				c_time;
	char			philo_status;
	int				time_diff_from_last_eat;
	pthread_mutex_t	*r_lock;
	pthread_mutex_t	*l_lock;
}				t_philo;

typedef struct s_info
{
	int				n_of_philos;
	int				t_2_die;
	int				t_2_eat;
	int				t_2_sleep;
	int				n_times_of_eat;
	pthread_mutex_t	**locks;
	pthread_t		*thread;
	t_philo			*philo;
}				t_info;

void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
int		num_parser(int arg_num, char *str);
void	error(int n);
void	updated_current_time(t_philo *philo);

#endif
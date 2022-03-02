/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:29:48 by bnaji             #+#    #+#             */
/*   Updated: 2022/03/02 08:31:18 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define PURPLE "\033[1;35m"
# define BLUE "\033[1;34m"
# define WHITE "\033[1;37m"
# define LIGHT_BLUE "\033[1;36m"
# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define BYELLOW  "\033[1;33m"
# define IYELLOW  "\033[3;33m"
# define NO_COLOR "\033[m"

typedef struct s_philo
{
	int				switch_flag;
	int				philo_id;
	int				n_of_philos;
	int				t_2_die;
	int				t_2_eat;
	int				t_2_sleep;
	int				*is_dead;
	int				just_died;
	int				n_times_of_eat;
	struct timeval	current_time;
	unsigned long	c_time;
	unsigned long	*useless_time;
	int				cnt;
	int				tmp;
	unsigned long	ref_time;
	char			philo_status;
	int				time_diff_from_last_eat;
	pthread_mutex_t	*r_lock;
	pthread_mutex_t	*l_lock;
	pthread_mutex_t	*death_lock;
}				t_philo;

typedef struct s_info
{
	int				n_of_philos;
	int				t_2_die;
	int				t_2_eat;
	int				t_2_sleep;
	int				n_times_of_eat;
	int				*is_dead;
	unsigned long	*useless_time;
	pthread_mutex_t	*death_lock;
	pthread_mutex_t	**locks;
	pthread_t		*thread;
	t_philo			*philo;
}				t_info;

void	init(t_info *info);
int		ft_eat(t_philo *philo);
void	ft_die(t_philo *philo);
void	main_free(t_info *info);
int		ft_think(t_philo *philo);
int		ft_sleep(t_philo *philo);
void	error(int n, t_info *info);
size_t	ft_strlen(const char *str);
void	locks_creater(t_info *info);
void	philos_creator(t_info *info);
void	ft_putstr_fd(char *s, int fd);
int		ft_usleep(t_philo *philo, char c);
int		updated_current_time(t_philo *philo, char c);
void	num_parser(int arg_num, char *str, t_info *info);
void	*philo_manager(void *vargp);
void	philo_init(t_info *info, int i);
void	printer(t_philo *philo, char c);

#endif
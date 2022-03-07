/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:57:45 by bnaji             #+#    #+#             */
/*   Updated: 2022/03/07 20:22:09 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	check_n_store(int arg_num, unsigned long long nb, t_info *info)
{
	if (!nb)
		error(5, info);
	if (arg_num == 1)
	{
		info->philo = (t_philo *)malloc(sizeof(t_philo) * (nb));
		if (!info->philo)
			error(6, info);
		info->thread = (pthread_t *)malloc(sizeof(pthread_t) * (nb));
		if (!info->thread)
			error(6, info);
		info->n_of_philos = nb;
	}
	if (arg_num == 2)
		info->t_2_die = nb;
	else if (arg_num == 3)
		info->t_2_eat = nb;
	else if (arg_num == 4)
		info->t_2_sleep = nb;
	else if (arg_num == 5)
		info->n_times_of_eat = nb;
}

void	num_parser(int arg_num, char *str, t_info *info)
{
	int						i;
	unsigned long long		nb;
	int						number_exist_flag;

	nb = 0;
	i = 0;
	number_exist_flag = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
		error(2, info);
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		if (nb > 2147483647)
			error(4, info);
		i++;
		number_exist_flag = 1;
	}
	if (str[i] || !number_exist_flag)
		error(3, info);
	check_n_store(arg_num, nb, info);
}

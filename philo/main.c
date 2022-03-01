/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:31:52 by bnaji             #+#    #+#             */
/*   Updated: 2022/03/01 16:36:17 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	int			i;
	t_info		info;

	if (ac < 5 || ac > 6)
		error(1, &info);
	i = 0;
	init(&info);
	while (++i < ac)
		num_parser(i, av[i], &info);
	locks_creater(&info);
	philos_creator(&info);
	main_free(&info);
	return (0);
}

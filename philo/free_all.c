/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 10:52:28 by bnaji             #+#    #+#             */
/*   Updated: 2022/02/26 11:18:55 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	main_free(t_info *info)
{
	int	i;

	if (info->thread)
		free(info->thread);
	if (info->philo)
		free(info->philo);
	if (info->locks)
	{
		i = 0;
		while (i < info->n_of_philos)
		{
			if (info->locks[i])
				free(info->locks[i++]);
		}
		free(info->locks);
	}
}
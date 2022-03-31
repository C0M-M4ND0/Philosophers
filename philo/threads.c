/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 09:12:44 by oabdelha          #+#    #+#             */
/*   Updated: 2022/03/30 19:10:08 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_creat_thread(t_data *data, t_philo *philo)
{
	int	index;

	index = 0;
	data->beginning_time = get_time();
	while (index < data->nbrofphilo)
	{
		philo[index].check_die_time = get_time();
		if (pthread_create(&data->philo[index].thread_id,
				NULL, routine_fonction, (void *)&(philo[index])))
			return (write(2, "ERROR : Creating thread has failed !\n", 37), 1);
		index++;
	}
	ft_check_death(data, data->philo);
	ft_end_philo(data, data->philo);
	return (0);
}

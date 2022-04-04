/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:21:57 by oabdelha          #+#    #+#             */
/*   Updated: 2022/04/04 13:18:38 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	creat_process(t_data *data, t_philo *philo)
{
	int		index;

	index = 0;
	data->beginning_time = get_time();
	while (index < data->nbrofphilo)
	{
		data->child_pid[index] = fork();
		if (!data->child_pid[index])
			creat_thread(data, &philo[index]);
		if (data->child_pid[index] == -1)
		{
			kill_process(data);
			return (1);
		}
		index++;
	}
	waitpid(-1, NULL, 0);
	end(data);
	return (0);
}

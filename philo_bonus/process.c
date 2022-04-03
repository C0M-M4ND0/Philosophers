/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:21:57 by oabdelha          #+#    #+#             */
/*   Updated: 2022/04/03 22:11:00 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_creat_process(t_data *data, t_philo *philo)
{
	int		index;
	int		status;

	index = 0;
	data->beginning_time = get_time();
	while (index < data->nbrofphilo)
	{
		data->child_pid[index] = fork();
		if (!data->child_pid[index])
			ft_creat_thread(data, &philo[index]);
		if (data->child_pid[index] == -1)
		{
			kill_process(data);
			return (1);
		}
		index++;
	}
	waitpid(-1, &status, 0);
	ft_end_philo(data);
	return (0);
}

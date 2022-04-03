/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:21:36 by oabdelha          #+#    #+#             */
/*   Updated: 2022/04/03 22:10:32 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	print_message(t_data *data, char *string, int philo_id)
{
	sem_wait(data->print);
	if (!(data->die))
	{
		printf("%lld ", get_time() - data->beginning_time);
		printf("%d ", philo_id + 1);
		printf("%s\n", string);
	}
	sem_post(data->print);
}

void	ft_check_eat(t_data *data, t_philo *philo)
{
	int	index;

	index = 0;
	while (data->time_each_philo_must_eat != 0 && index < data->nbrofphilo
		&& philo->eat > data->time_each_philo_must_eat)
		index++;
	if (index == data->nbrofphilo)
		data->check_eat = 1;
}

void	ft_check_death(t_data *data, t_philo *philo)
{
	int		index;

	while (!(data->check_eat))
	{
		index = 0;
		while ((index < data->nbrofphilo) && (!(data->die)))
		{
			sem_wait(data->eating);
			if ((get_time() - philo->check_die_time) > data->time_to_die)
			{
				sem_wait(data->sem_die);
				print_message(data, "died", index);
				data->die = 1;
			}
			sem_post(data->eating);
			index++;
		}
		if (data->die)
			break ;
		if (data->time_each_philo_must_eat > 0)
			ft_check_eat(data, data->philo);
		usleep(1000);
	}
}

void	kill_process(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbrofphilo)
		kill(data->child_pid[i++], SIGKILL);
}

void	ft_end_philo(t_data *data)
{
	kill_process(data);
	sem_close(data->forks);
	sem_close(data->print);
	sem_close(data->eating);
	sem_unlink("FORKS");
	sem_unlink("PRINT");
	sem_unlink("EATING");
	free(data->child_pid);
	free(data->philo);
}

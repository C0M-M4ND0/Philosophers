/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:21:36 by oabdelha          #+#    #+#             */
/*   Updated: 2022/04/04 13:14:48 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_data *data, char *string, int philo_id)
{
	pthread_mutex_lock(&(data->print));
	if (!(data->die))
	{
		printf("%lld ", get_time() - data->beginning_time);
		printf("%d ", philo_id + 1);
		printf("%s\n", string);
	}
	pthread_mutex_unlock(&(data->print));
}

void	check_eat(t_data *data, t_philo *philo)
{
	int	index;

	index = 0;
	while (data->time_each_philo_must_eat != 0 && index < data->nbrofphilo
		&& philo[index].eat > data->time_each_philo_must_eat)
		index++;
	if (index == data->nbrofphilo)
		data->check_eat = 1;
}

void	check_death(t_data *data, t_philo *philo)
{
	int		index;

	while (!(data->check_eat))
	{
		index = 0;
		while ((index < data->nbrofphilo) && (!(data->die)))
		{
			pthread_mutex_lock(&(data->eating));
			if ((get_time() - philo[index].check_die_time) > data->time_to_die)
			{
				print_message(data, "died", index);
				data->die = 1;
			}
			pthread_mutex_unlock(&(data->eating));
			index++;
		}
		if (data->die)
			break ;
		if (data->time_each_philo_must_eat > 0)
			check_eat(data, data->philo);
		usleep(1000);
	}
}

void	end(t_data *data, t_philo *philo)
{
	int	index;

	index = 0;
	while (index < data->nbrofphilo)
		pthread_join(philo[index++].thread_id, NULL);
	index = 0;
	while (index < data->nbrofphilo)
		pthread_mutex_destroy(&(data->forks[index++]));
	pthread_mutex_destroy(&(data->eating));
	pthread_mutex_destroy(&(data->print));
	free(data->philo);
	free(data->forks);
}

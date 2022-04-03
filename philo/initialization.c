/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:40:47 by oabdelha          #+#    #+#             */
/*   Updated: 2022/04/03 14:05:22 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_struct_philo(t_data *data)
{
	int	index;

	index = 0;
	data->philo = malloc(sizeof(t_data) * data->nbrofphilo);
	if (!data->philo)
		return (1);
	while (index < data->nbrofphilo)
	{
		data->philo[index].id = index;
		data->philo[index].l_f = index;
		data->philo[index].r_f = (index + 1) % data->nbrofphilo;
		data->philo[index].check_die_time = 0;
		data->philo[index].eat = 0;
		data->philo[index].data = data;
		index++;
	}
	return (0);
}

int	ft_init_mutex(t_data *data)
{
	int	index;

	index = 0;
	if (pthread_mutex_init(&(data->eating), NULL))
		return (1);
	if (pthread_mutex_init(&(data->print), NULL))
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nbrofphilo);
	if (!(data->forks))
		return (1);
	while (index < data->nbrofphilo)
	{
		if (pthread_mutex_init(&(data->forks[index]), NULL))
			return (1);
		index++;
	}
	return (0);
}

int	ft_initialization(t_data *data, int ac, char **av)
{
	data->nbrofphilo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->beginning_time = 0;
	data->die = 0;
	data->check_eat = 0;
	data->time_each_philo_must_eat = 0;
	if (ac == 6)
	{
		data->time_each_philo_must_eat = ft_atoi(av[5]);
		if (data->time_each_philo_must_eat <= 0)
			return (write(2, "ERROR : Number of times each \
			philosopher must eat can't be less than 1\n", 71), 1);
	}
	if (ft_init_mutex(data) || ft_init_struct_philo(data))
		return (write(2, "ERROR : Initialization has failed !\n", 42), 1);
	return (0);
}

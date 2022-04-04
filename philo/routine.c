/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:49:59 by oabdelha          #+#    #+#             */
/*   Updated: 2022/04/04 20:56:30 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(int time_limit, t_data *data)
{
	long long	time;

	time = get_time();
	if (!(data->die))
	{
		usleep((time_limit - (time_limit * 0.03)) * 1000);
		while ((get_time() - time) < time_limit)
			usleep(1);
	}
}

void	start_eat(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&(data->eating));
	print_message(data, "is eating", philo->id);
	philo->check_die_time = get_time();
	pthread_mutex_unlock(&(data->eating));
	(philo->eat)++;
	ft_usleep(data->time_to_eat, data);
}

int	taking_fork(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&(data->forks[philo->l_f]));
	print_message(data, "has taken a fork", philo->id);
	pthread_mutex_lock(&(data->forks[philo->r_f]));
	print_message(data, "has taken a fork", philo->id);
	start_eat(philo->data, philo);
	pthread_mutex_unlock(&(data->forks[philo->l_f]));
	pthread_mutex_unlock(&(data->forks[philo->r_f]));
	if (data->check_eat)
		return (1);
	return (0);
}

void	*routine_fonction(void *philo)
{
	t_philo	*copy_of_philo;
	t_data	*data;

	copy_of_philo = (t_philo *)philo;
	data = copy_of_philo->data;
	if (data->nbrofphilo == 1)
	{
		print_message(data, "has taken a fork", copy_of_philo->id);
		ft_usleep(data->time_to_die, data);
		return (NULL);
	}
	if (copy_of_philo->id % 2)
		usleep(10000);
	while (!(data->die))
	{
		if (taking_fork(data, copy_of_philo))
			break ;
		print_message(data, "is sleeping", copy_of_philo->id);
		ft_usleep(data->time_to_sleep, data);
		print_message(data, "is  thinking", copy_of_philo->id);
	}
	return (NULL);
}

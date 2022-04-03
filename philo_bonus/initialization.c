/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelha <oabdelha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:40:47 by oabdelha          #+#    #+#             */
/*   Updated: 2022/04/03 13:50:23 by oabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_init(t_data *data)
{
	int	index;

	index = 0;
	data->philo = malloc(sizeof(t_data) * data->nbrofphilo);
	data->child_pid = (pid_t *)malloc(sizeof(pid_t) * data->nbrofphilo);
	if (!data->philo || !data->child_pid)
		return (1);
	while (index < data->nbrofphilo)
	{
		data->philo[index].id = index;
		data->philo[index].check_die_time = 0;
		data->philo[index].eat = 0;
		data->philo[index].data = data;
		index++;
	}
	return (0);
}

int	ft_init_sem(t_data *data)
{
	mode_t	permission;

	sem_unlink("FORK");
	sem_unlink("PRINT");
	sem_unlink("EATING");
	permission = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
	data->forks = sem_open("FORK", O_CREAT , permission, data->nbrofphilo);
	data->print = sem_open("PRINT", O_CREAT, permission, 1);
	data->eating = sem_open("EATING", O_CREAT, permission, 1);
	if (data->forks  == SEM_FAILED || data->print == SEM_FAILED || data->eating == SEM_FAILED)
		return (1);
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
	if ((ft_init_sem(data)) || (ft_init(data)))
		return (write(2, "ERROR : Initialization has failed !\n", 42), 1);
	return (0);
}

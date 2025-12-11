/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:57:42 by ali-akouhar       #+#    #+#             */
/*   Updated: 2024/07/27 10:09:32 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_create_forks(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philo)
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (1);
	i = -1;
	while (++i < data->n_philo)
	{
		data->philo[i].left_fork = &data->forks[i];
		data->philo[i].right_fork = &data->forks[(i + 1) % data->n_philo];
	}
	return (0);
}

void	ft_init_philo(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_init(&data->status_lock, NULL);
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->finish_lock, NULL);
	pthread_mutex_init(&data->eat_lock, NULL);
	pthread_mutex_init(&data->time_lock, NULL);
	pthread_mutex_init(&data->dimo, NULL);
	set_finish(data, 0);
	set_value(data, 1);
	while (++i < data->n_philo)
	{
		data->philo[i].data = data;
		data->philo[i].id = i + 1;
		data->philo[i].meals_counter = 0;
		data->philo[i].status = NTHG;
		data->philo[i].last_meal = get_time();
	}
}

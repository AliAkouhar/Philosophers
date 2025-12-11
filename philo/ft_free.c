/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:28:20 by aakouhar          #+#    #+#             */
/*   Updated: 2024/09/02 10:26:55 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_all(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&data->status_lock);
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->dimo);
	pthread_mutex_destroy(&data->eat_lock);
	pthread_mutex_destroy(&data->time_lock);
	pthread_mutex_destroy(&data->finish_lock);
	while (++i < data->n_philo)
		pthread_mutex_destroy(&data->forks[i]);
}

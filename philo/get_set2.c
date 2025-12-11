/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:06:23 by aakouhar          #+#    #+#             */
/*   Updated: 2024/09/04 09:48:55 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_finish(t_data *data)
{
	int	t;

	pthread_mutex_lock(&data->finish_lock);
	t = data->finish;
	pthread_mutex_unlock(&data->finish_lock);
	return (t);
}

void	set_finish(t_data *data, int i)
{
	pthread_mutex_lock(&data->finish_lock);
	data->finish = i;
	pthread_mutex_unlock(&data->finish_lock);
}

int	get_meals(t_philo *philo)
{
	int	t;

	pthread_mutex_lock(&philo->data->eat_lock);
	t = philo->meals_counter;
	pthread_mutex_unlock(&philo->data->eat_lock);
	return (t);
}

void	set_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->eat_lock);
	philo->meals_counter++;
	pthread_mutex_unlock(&philo->data->eat_lock);
}

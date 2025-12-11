/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:09:18 by ali-akouhar       #+#    #+#             */
/*   Updated: 2024/09/02 10:28:48 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_value(t_data *data)
{
	int	o;

	pthread_mutex_lock(&data->dimo);
	o = data->death_flag;
	pthread_mutex_unlock(&data->dimo);
	return (o);
}

void	set_value(t_data *data, int i)
{
	pthread_mutex_lock(&data->dimo);
	data->death_flag = i;
	pthread_mutex_unlock(&data->dimo);
}

t_status	get_status(t_philo *philo)
{
	t_status	status;

	pthread_mutex_lock(&philo->data->status_lock);
	status = philo->status;
	pthread_mutex_unlock(&philo->data->status_lock);
	return (status);
}

void	set_status(t_philo *philo, t_status status)
{
	pthread_mutex_lock(&philo->data->status_lock);
	philo->status = status;
	pthread_mutex_unlock(&philo->data->status_lock);
}

void	ft_printf(char *str, t_philo *philo)
{
	if (get_finish(philo->data) == 1)
		return ;
	pthread_mutex_lock(&philo->data->write_lock);
	if (!get_finish(philo->data) && get_value(philo->data))
		printf("%llu   %i %s", (get_time() - philo->data->time), philo->id,
			str);
	pthread_mutex_unlock(&philo->data->write_lock);
}

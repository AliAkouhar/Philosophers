/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:43:58 by ali-akouhar       #+#    #+#             */
/*   Updated: 2024/09/04 09:47:22 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_death(t_philo *philo)
{
	if (get_status(philo) == DIED)
		return (1);
	pthread_mutex_lock(&philo->data->time_lock);
	if (get_status(philo) != EATING && (get_time()
			- philo->last_meal > philo->data->t_die))
	{
		set_status(philo, DIED);
		pthread_mutex_unlock(&philo->data->time_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->time_lock);
	return (0);
}

void	go_kill_all(t_data *data)
{
	int	i;

	i = -1;
	set_value(data, 0);
	while (++i < data->n_philo)
		set_status(&data->philo[i], DIED);
}

void	*check_death(void *p)
{
	t_data	*data;
	int		i;

	data = (t_data *)p;
	i = 0;
	while (i < data->n_philo && data->n_philo != 1)
	{
		if (is_death(&data->philo[i]))
		{
			ft_printf("died\n", &data->philo[i]);
			go_kill_all(data);
			break ;
		}
		i++;
		if (i == data->n_philo)
			i = 0;
		usleep(1000);
	}
	return (NULL);
}

void	*check_meals(void *p)
{
	t_data	*data;
	int		i;
	int		count;

	data = (t_data *)p;
	i = -1;
	count = 0;
	while (++i < data->n_philo && get_value(data))
	{
		if (get_meals(&data->philo[i]) >= (long)data->num_meals)
			count++;
		if (count == data->n_philo)
		{
			set_finish(data, 1);
			go_kill_all(data);
			break ;
		}
		if (i == data->n_philo - 1)
		{
			i = -1;
			count = 0;
		}
		usleep(1000);
	}
	return (NULL);
}

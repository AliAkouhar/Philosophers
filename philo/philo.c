/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:16:29 by ali-akouhar       #+#    #+#             */
/*   Updated: 2024/08/13 11:18:33 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_args(char **av, t_data *data)
{
	data->n_philo = (int)ft_atol(av[1]);
	data->t_die = (long long)ft_atol(av[2]);
	data->t_eat = (long long)ft_atol(av[3]);
	data->t_sleep = (long long)ft_atol(av[4]);
	if (data->n_philo < 0 || data->t_die < 0 || data->t_eat < 0
		|| data->t_sleep < 0)
		return (printf("Error\n"));
	if (av[5])
	{
		data->num_meals = (unsigned long long)ft_atol(av[5]);
		if (data->num_meals <= 0)
			return (printf("Error\n"));
	}
	else
		data->num_meals = -1;
	return (0);
}

int	ft_create_philos(t_data *data)
{
	int	i;

	i = -1;
	data->time = get_time();
	while (++i < data->n_philo)
		if (pthread_create(&data->philo[i].th, NULL, routine, &data->philo[i]))
			return (1);
	if (data->n_philo > 1)
	{
		if (pthread_create(&data->death_monitore, NULL, check_death, data))
			return (1);
		if (data->num_meals > 0)
			if (pthread_create(&data->meals_monitore, NULL, check_meals, data))
				return (1);
	}
	return (0);
}

int	ft_join(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philo)
	{
		if (pthread_join(data->philo[i].th, NULL))
			return (1);
	}
	if (data->n_philo > 1)
	{
		if (pthread_join(data->death_monitore, NULL))
			return (1);
		if (data->num_meals > 0)
			if (pthread_join(data->meals_monitore, NULL))
				return (1);
	}
	return (0);
}

int	ft_init(char **av, t_data *data)
{
	if (ft_init_args(av, data))
		return (1);
	if (ft_create_forks(data))
		return (1);
	ft_init_philo(data);
	if (ft_create_philos(data))
		return (1);
	if (ft_join(data))
		return (1);
	ft_free_all(data);
	return (0);
}

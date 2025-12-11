/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 17:05:58 by ali-akouhar       #+#    #+#             */
/*   Updated: 2024/09/04 10:55:33 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_a_fork(t_philo *philo)
{
	if (philo->data->n_philo == 1)
	{
		ft_printf("has taken a fork\n", philo);
		ft_usleep(philo->data->t_die);
		set_status(philo, DIED);
		ft_printf("is died\n", philo);
		return (1);
	}
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		ft_printf("has taken a fork\n", philo);
		pthread_mutex_lock(philo->left_fork);
		ft_printf("has taken a fork\n", philo);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		ft_printf("has taken a fork\n", philo);
		pthread_mutex_lock(philo->right_fork);
		ft_printf("has taken a fork\n", philo);
	}
	return (0);
}

int	ft_eating(t_philo *philo)
{
	if (take_a_fork(philo))
		return (1);
	set_status(philo, EATING);
	ft_printf("is eating\n", philo);
	pthread_mutex_lock(&philo->data->time_lock);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->data->time_lock);
	ft_usleep(philo->data->t_eat);
	set_meals(philo);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}

int	ft_sleeping(t_philo *philo)
{
	set_status(philo, SLEEPING);
	if (get_status(philo) == DIED)
		return (1);
	ft_printf("is sleeping\n", philo);
	ft_usleep(philo->data->t_sleep);
	return (0);
}

int	ft_thinking(t_philo *philo)
{
	set_status(philo, THINKING);
	usleep(700);
	if (get_status(philo) == DIED)
		return (1);
	ft_printf("is thinking\n", philo);
	return (0);
}

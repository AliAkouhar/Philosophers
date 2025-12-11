/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:10:56 by ali-akouhar       #+#    #+#             */
/*   Updated: 2024/06/30 15:17:27 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	if (philo->id % 2 == 0)
		ft_usleep((philo->data->t_eat - 20));
	while (get_value(philo->data) && get_status(philo) != DIED
		&& get_finish(philo->data) == 0)
	{
		if (get_status(philo) == DIED || get_finish(philo->data) == 1)
			break ;
		if (ft_eating(philo) || get_finish(philo->data) == 1)
			break ;
		if (get_status(philo) == DIED || get_finish(philo->data) == 1)
			break ;
		if (ft_sleeping(philo) || get_finish(philo->data) == 1)
			break ;
		if (get_status(philo) == DIED || get_finish(philo->data) == 1)
			break ;
		if (ft_thinking(philo) || get_finish(philo->data) == 1)
			break ;
	}
	return (NULL);
}

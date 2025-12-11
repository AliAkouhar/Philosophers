/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:46:41 by ali-akouhar       #+#    #+#             */
/*   Updated: 2024/09/04 10:41:06 by aakouhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include "utils/utils.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	DIED,
	NTHG
}					t_status;

typedef struct s_philo
{
	pthread_t		th;
	int				id;
	int				meals_counter;
	int				eat_flag;
	long long		start;
	long long		last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	message;
	struct s_data	*data;
	t_status		status;

}					t_philo;

typedef struct s_data
{
	t_philo			philo[201];
	pthread_mutex_t	eat_lock;
	pthread_mutex_t	dimo;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	status_lock;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	time_lock;
	pthread_mutex_t	finish_lock;
	pthread_mutex_t	fi_lock;
	pthread_mutex_t	forks[201];
	long long		t_eat;
	long long		t_die;
	long long		t_sleep;
	long long		time;
	int				death_flag;
	int				n_philo;
	int				finish;
	int				num_meals;
	pthread_t		meals_monitore;
	pthread_t		death_monitore;
}					t_data;

int					parcing(int ac, char **av);
void				*routine(void *d);
int					ft_init(char **av, t_data *data);
void				*death_func(void *p);
int					ft_create_forks(t_data *data);
int					ft_create_philos(t_data *data);
void				*death_func(void *p);
void				go_to_eat(t_philo *philo);
void				ft_printf(char *str, t_philo *philo);
void				ft_init_philo(t_data *data);
void				*check_death(void *p);
void				*check_meals(void *p);
int					take_a_fork(t_philo *philo);
int					is_death(t_philo *philo);
t_status			get_status(t_philo *philo);
int					ft_thinking(t_philo *philo);
int					ft_sleeping(t_philo *philo);
int					ft_eating(t_philo *philo);
int					take_a_fork(t_philo *philo);
void				ft_printf(char *str, t_philo *philo);
void				set_status(t_philo *philo, t_status status);
void				go_kill_all(t_data *data);
int					check_all(t_data *data);
void				ft_free_all(t_data *data);
int					get_value(t_data *data);
void				set_value(t_data *data, int i);
int					get_finish(t_data *data);
void				set_finish(t_data *data, int i);
int					get_meals(t_philo *philo);
void				set_meals(t_philo *philo);

#endif
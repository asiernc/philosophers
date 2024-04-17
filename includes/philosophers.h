/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:20:55 by anovio-c          #+#    #+#             */
/*   Updated: 2024/04/16 22:01:20 by asiercara        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h> // printf()
# include <stdlib.h> // malloc(), free()
# include <unistd.h> // write(), usleep()
# include <sys/time.h> // gettimeofday()
# include <pthread.h> // thread API

typedef struct	s_philo
{
	pthread_t			thread;
	int					num;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	int					num_times_to_eat;
	int					is_eating;
	size_t				start_time;
	size_t				last_eat;
	int					meals_eaten;
	int					*dead;
	struct s_data		*data;
	pthread_mutex_t		*fork_r;
	pthread_mutex_t		fork_l;
}						t_philo;

typedef struct	s_data
{
	int					num_of_philos;
	int					dead_flag;
	t_philo				*philo;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		eat_mutex;
	pthread_mutex_t		dead_mutex;
}						t_data;

// Init struct

void		structure_init(t_data *data, char **argv);
void		philos_init(t_data *data, char **argv);
void		fill_fixes_values(t_philo *philo, char **argv);
int			threads_init(t_data *data);

// Philo routine

void	*philo_routine(void *ptr);
int		routine_loop(t_philo *philo);
void	is_thinking(t_philo *philo);
void	is_sleeping(t_philo *philo);
void	is_eating(t_philo *philo);

// Controller

void	*controller(void *ptr);
int		check_philo(t_philo *philo, size_t time_to_die);
int		check_is_dead(t_philo *philo);
int		check_all_ate(t_philo *philo);

// Philosophers utils

int			check_input(char **args);
int			ft_error(char *str);
void		print_msg(char *str, int philo_num, t_philo *philo);
size_t		get_time(void);
int			ft_usleep(size_t miliseconds);
void		destroy_mutex(t_data *data);


// Libft utils

int			ft_atoi(char *str);
int			ft_isspace(int ch);
int			ft_isdigit(int ch);

#endif

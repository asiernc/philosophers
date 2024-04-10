/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:20:55 by anovio-c          #+#    #+#             */
/*   Updated: 2024/04/10 17:25:37 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <memory.h> // memset()
# include <stdio.h> // printf()
# include <stdlib.h> // malloc(), free()
# include <unistd.h> // write(), usleep()
# include <sys/time.h> // gettimeofday()
# include <pthread.h> // thread API
# include <stdbool.h> // boolean data type

# define MICROSEC 1000

typedef struct	s_philo
{
	int					num;
	int					is_eating;
	pthread_t			thread;
	long int			last_eat;
	int					moves_count;
	struct t_data		*data;
	pthread_mutex_t		*fork_r;
	pthread_mutex_t		fork_l;
}						t_philo;


typedef struct	s_data
{
	int					num_of_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_eat;
	int					philo_eat;
	int					stop;
	long int			time_start;
	t_philo				*philo;
	pthread_mutex_t		print_lock;
	pthread_mutex_t		stop_lock;
	pthread_mutex_t		eat_lock;
	pthread_mutex_t		dead_lock;
}						t_data;

// Init struct

int			data_init(t_data *data, char **argv);
int			philo_init(t_data *data);


// Philosophers utils

int			check_input(char **args);
int			ft_error(char *str, t_data *data);
long int	get_time(void);


// Libft utils

int			ft_atoi(char *str);
int			ft_isspace(int ch);
int			ft_isdigit(int ch);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:20:55 by anovio-c          #+#    #+#             */
/*   Updated: 2024/04/08 21:20:59 by asiercara        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <memory.h> // memset()
# include <stdio.h> // printf()
# include <stdlib.h> // malloc(), free()
# include <unistd.h> // write(), usleep()
# include <sys/time.h> // gettimeofday()
# include <pthread.h> // POSIX thread API
# include <stdbool.h> // boolean data type

# define MICROSEC 1000

typedef struct	s_philo
{
	int					num;
	bool				is_eating;
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
	long int			time_start;
	t_philo				*philo;
	pthread_mutex_t		print;
	pthread_mutex_t		m_stop;
	pthread_mutex_t		m_eat;
	pthread_mutex_t		dead;
}						t_data;

// Init struct

int			vars_init(t_data *data, char **argv);


// Philosophers utils

int			check_input(char **args);
int			ft_error(char *str, t_data *data);
long int	get_time(void);


// Libft utils

int			ft_atoi(char *str);
int			ft_isspace(int ch);
int			ft_isdigit(int ch);

#endif

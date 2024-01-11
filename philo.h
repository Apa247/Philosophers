/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:43:26 by daparici          #+#    #+#             */
/*   Updated: 2024/01/11 19:56:03 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct philo
{
	int					id;
	int					t_to_die;
	int					t_to_eat;
	int					t_sleeping;
	int					*stop;
	int					*lunchs_nb;
	int					last_lunch;
	long long			star_time;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*print_lock;
	pthread_mutex_t		*philo_action;
}	t_philo;

typedef struct data
{
	int					philos_nb;
	int					lunchs_nb;
	int					stop;
	long long			star_time;
	long long			last_time_eat;
	pthread_t			*philosophers;
	pthread_mutex_t		*forks;
	pthread_mutex_t		*print_lock;
	pthread_mutex_t		*philo_action;
	t_philo				*philo;
}	t_data;

int			check_args(int ac, char **av);
int			ft_atoi_p(char *str);
int			innit_data(t_data *data, char **av, int ac);
void		ft_free(t_data *data);
int			create_threads(t_data *data, char **av);
int			init_philo_params(t_data *data, char **av, int i);
long long	ft_get_time(void);
void		*rutine(void *arg);
void		ft_sleep(int time);
void		ft_print(t_philo *philo, char *str);
void		father_loop(t_data *data);
int			check_death(t_data *data, int i);
int			ft_strlen(char *str);

#endif
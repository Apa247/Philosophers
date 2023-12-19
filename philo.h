/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:43:26 by daparici          #+#    #+#             */
/*   Updated: 2023/12/19 21:39:57 by daparici         ###   ########.fr       */
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
	int					t_to_sleep;
	int					*stop;
	int					*lunchs_nb;
	int					time_fork;
	int					*dat;
	pthread_mutex_t		*print_lock;
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
	t_philo				*philo;
}	t_data;

int		check_args(int ac, char **av);
int		ft_atoi_p(char *str);
int		innit_data(t_data *data, char **av, int ac);
void	ft_free(t_data *data);
int		init_philo_params(t_data data, int ac, char **av, int i);

#endif
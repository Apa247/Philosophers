/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:43:26 by daparici          #+#    #+#             */
/*   Updated: 2023/12/18 20:54:01 by daparici         ###   ########.fr       */
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
	int					time_fork;
}	t_philo;

typedef struct dat
{
	int					philos_nb;
	int					t_to_die;
	int					t_to_eat;
	int					t_to_sleep;
	int					nb_of_lunchs;
	int					stop;
	pthread_t			*philosophers;
	pthread_mutex_t		*forks;
	t_philo				*philo;
}	t_data;

int		check_args(int ac, char **av);
int		ft_atoi_p(char *str);
int		innit_data(t_data *data, char **av, int ac);
void	ft_free(t_data *data);

#endif
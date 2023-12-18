/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:40:38 by daparici          #+#    #+#             */
/*   Updated: 2023/12/18 20:55:13 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"	

int	innit_data(t_data *data, char **av, int ac)
{
	data->philos_nb = ft_atoi_p(av[1]);
	data->forks = malloc(sizeof(pthread_mutex_t) * (data->philos_nb));
	if (!data->forks)
		return (0);
	data->philosophers = malloc(sizeof(pthread_t) * (data->philos_nb));
	if (!data->philosophers)
		return (free(data->forks), 0);
	data->philo = malloc(sizeof(t_philo) * (data->philos_nb));
	if (!data->philo)
		return (free(data->forks), free(data->philo), 0);
	data->stop = 1;
	data->t_to_die = ft_atoi_p(av[2]);
	data->t_to_eat = ft_atoi_p(av[3]);
	data->t_to_sleep = ft_atoi_p(av[4]);
	if (ac == 6)
		data->nb_of_lunchs = ft_atoi_p(av[5]) * data->philos_nb;
	return (1);
}

int	check_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac < 5 || ac > 6)
		return (0);
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
		}
	}
	if (!ft_atoi_p(av[1]) || !ft_atoi_p(av[2]) || !ft_atoi_p(av[3])
		|| !ft_atoi_p(av[4]))
		return (0);
	if (ac == 6)
	{
		if (!ft_atoi_p(av[5]))
			return (0);
	}
	return (1);
}

int	create_threads(t_data *data, int ac, char **av)
{
	int	i;

	i = 0;
	while ()
}

int	main(int ac, char **av)
{
	t_data	data;

	if (!check_args(ac, av))
		return (printf("Error\n"));
	if (!innit_data(&data, av, ac))
		return (printf("Malloc Error\n"));
	if (!create_threads(&data, ac, av))
		return (ft_free(&data), 0);
	return (0);
}

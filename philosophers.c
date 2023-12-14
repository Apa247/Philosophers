/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:40:38 by daparici          #+#    #+#             */
/*   Updated: 2023/12/14 23:10:05 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"	

int	innit_data(t_data *data, char **av)
{
	data->philos_nb = ft_atoi_p(av[1]);
	data->forks = malloc(sizeof(pthread_mutex_t) * (data->philos_nb));
	if (!data->forks)
		return (0);
	data->philosophers = malloc(sizeof(pthread_t) * (data->philos_nb));
	if (!data->philosophers)
		return (free(data->forks), 0);
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

int	main(int ac, char **av)
{
	t_data	data;

	if (!check_args(ac, av))
		return (printf("Error\n"));
	if (!innit_data(&data, av))
		return (printf("Malloc Error\n"));
}

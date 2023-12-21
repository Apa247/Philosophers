/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidaparicio <davidaparicio@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 22:22:11 by daparici          #+#    #+#             */
/*   Updated: 2023/12/21 13:36:08 by davidaparic      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_get_time(void)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL))
		return (-1);
	else
		return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
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
	if (ac == 6)
	{
		if (!ft_atoi_p(av[5]))
			return (0);
	}
	return (1);
}

int	ft_atoi_p(char *str)
{
	unsigned long long int		valor;
	int							signo;
	unsigned int				i;

	i = 0;
	signo = 1;
	valor = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signo = -signo;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		valor = valor * 10 + (str[i] - '0');
		if (valor >= 9223372036854775807 && signo == 1)
			return (-1);
		if (valor > 9223372036854775807 && signo == -1)
			return (0);
		i++;
	}
	return ((int)(valor * signo));
}

void	ft_free(t_data *data)
{
	free(data->forks);
	free(data->philosophers);
	free(data->philo);
	free(data->print_lock);
}

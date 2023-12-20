/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daparici <daparici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 22:22:11 by daparici          #+#    #+#             */
/*   Updated: 2023/12/20 20:40:11 by daparici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

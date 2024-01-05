/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davidaparicio <davidaparicio@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 21:41:31 by davidaparic       #+#    #+#             */
/*   Updated: 2024/01/05 22:15:23 by davidaparic      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->print_lock);
	if (*philo->stop == 0)
		printf("%lldms philosopher %i %s\n", ft_get_time() - philo->star_time, philo->id, str);
	pthread_mutex_unlock(philo->print_lock);
}

void	ft_sleep(int time)
{
	long long	star_time;
	long long	time_now;

	star_time = ft_get_time();
	time_now = star_time;
	while (star_time >= (time_now - time))
	{
		time_now = ft_get_time();
		usleep(100);
	}
}

void	*rutine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(philo->print_lock);
	pthread_mutex_unlock(philo->print_lock);
	if ((philo->id % 2) == 0)
		usleep(400);
	pthread_mutex_lock(philo->print_lock);
	while (*philo->stop == 0)
	{
		pthread_mutex_unlock(philo->print_lock);
		pthread_mutex_lock(philo->left_fork);
		ft_print(philo, "has taken left fork");
		pthread_mutex_lock(philo->right_fork);
		ft_print(philo, "has taken right fork");
		pthread_mutex_lock(philo->philo_action);
		philo->last_lunch = ft_get_time() - philo->star_time;
		ft_print(philo, "is eating");
		if (*philo->lunchs_nb > 0)
			*philo->lunchs_nb = *philo->lunchs_nb - 1;
		else
			break ;
		pthread_mutex_unlock(philo->philo_action);
		//printf("comidas: %i\n", *philo->lunchs_nb);
		ft_sleep(philo->t_to_eat);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		ft_print(philo, "is sleeping");
		ft_sleep(philo->t_sleeping);
		ft_print(philo, "is thinking");
		pthread_mutex_lock(philo->print_lock);
	}
	return (NULL);
}
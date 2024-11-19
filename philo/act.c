/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:16:06 by junsepar          #+#    #+#             */
/*   Updated: 2023/08/08 13:38:57 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*doing_thread(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	if (ph->no % 2 == 0)
		waaaait(ph->table->time_to_eat / 2);
	while (1)
	{
		get_fork(philo);
		if (ph->table->number_of_philosophers == 1)
			break ;
		if (ph->no % 2 == 0)
			waaaait(2);
		do_eat(philo);
		do_sleep(philo);
		do_think(philo);
	}
	return (NULL);
}

void	get_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->left]);
	philo_print(philo, "has taken a fork", 0);
	if (philo->table->number_of_philosophers == 1)
		return ;
	pthread_mutex_lock(&philo->table->forks[philo->right]);
	philo_print(philo, "has taken a fork", 0);
}

int	do_eat(t_philo *philo)
{
	philo_print(philo, "is eating", 0);
	pthread_mutex_lock(&philo->table->safe);
	philo->last_eat = ft_get_time();
	pthread_mutex_unlock(&philo->table->safe);
	waaaait(philo->table->time_to_eat);
	pthread_mutex_unlock(&philo->table->forks[philo->right]);
	pthread_mutex_unlock(&philo->table->forks[philo->left]);
	pthread_mutex_lock(&philo->table->safe);
	philo->eat_cnt--;
	if (philo->eat_cnt == 0)
	{
		philo->table->count++;
		pthread_mutex_unlock(&philo->table->safe);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->safe);
	return (0);
}

void	do_sleep(t_philo *philo)
{
	philo_print(philo, "is sleeping", 0);
	waaaait(philo->table->time_to_sleep);
}

void	do_think(t_philo *philo)
{
	philo_print(philo, "is thinking", 0);
	usleep(200);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 20:58:48 by junsepar          #+#    #+#             */
/*   Updated: 2023/08/10 00:11:37 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	thread_clear(t_philo *philo)
{
	int		i;

	i = 0;
	while (i < philo->table->number_of_philosophers)
	{
		pthread_detach(philo[i].thread);
		i++;
	}
}

void	waaaait(int num)
{
	long long	time;

	time = ft_get_time();
	while (ft_get_time() - time < num)
		usleep(500);
}

long long	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	print_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (1);
		s1++;
		s2++;
	}
	return (0);
}

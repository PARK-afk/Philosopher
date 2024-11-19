/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 22:10:06 by junsepar          #+#    #+#             */
/*   Updated: 2023/08/12 18:21:21 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	philo_print(t_philo *philo, char *mess, int flag)
{
	long long	time;

	time = ft_get_time();
	pthread_mutex_lock(&philo->table->print);
	printf("%lld %d %s\n", time - philo->table->start, philo->no, mess);
	if (flag == 0)
		pthread_mutex_unlock(&philo->table->print);
}

t_table	*table_init(char **argv)
{
	t_table	*table;

	table = (t_table *)malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->number_of_philosophers = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->start = ft_get_time();
	pthread_mutex_init(&table->safe, NULL);
	pthread_mutex_init(&table->print, NULL);
	if (init_check(table, argv) != 0)
	{
		free (table);
		return (NULL);
	}
	return (table);
}

t_philo	*philo_init(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)malloc(sizeof(t_philo) * table->number_of_philosophers);
	table->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
			table->number_of_philosophers);
	if (!philo && !table->forks)
		return (NULL);
	while (i < table->number_of_philosophers)
	{
		philo[i].table = table;
		philo[i].no = i + 1;
		philo[i].left = i;
		philo[i].right = (i + 1) % table->number_of_philosophers;
		philo[i].last_eat = ft_get_time();
		philo[i].eat_cnt = table->number_of_times_each_philosopher_must_eat;
		philo[i].thread = NULL;
		pthread_mutex_init(&philo->table->forks[i], NULL);
		i++;
	}
	return (philo);
}

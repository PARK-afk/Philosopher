/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 06:33:22 by junsepar          #+#    #+#             */
/*   Updated: 2023/08/12 19:17:37 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	monitor(t_table *table, t_philo *philo)
{
	int		i;

	while (1)
	{
		i = 0;
		while (i < table->number_of_philosophers)
		{
			pthread_mutex_lock(&philo[i].table->safe);
			if (ft_get_time() - philo[i].last_eat > philo->table->time_to_die)
			{
				philo_print(philo, "died", 1);
				thread_clear(philo);
				return ;
			}
			if (table->count == philo->table->number_of_philosophers)
			{
				philo_print(philo, "eat end", 1);
				thread_clear(philo);
				return ;
			}
			pthread_mutex_unlock(&philo[i].table->safe);
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	int					i;
	t_table				*table;
	t_philo				*philo;

	if (argc != 5 && argc != 6)
		return (print_error("Argument Error\n"));
	if (!check_argv(argc, argv))
		return (print_error("Argument Error\n"));
	table = table_init(argv);
	if (!table)
		return (print_error("Argument Error\n"));
	philo = philo_init(table);
	if (!philo)
		return (print_error("Argument Error\n"));
	i = -1;
	while (++i < table->number_of_philosophers)
		pthread_create(&philo[i].thread, NULL, doing_thread, (void *)&philo[i]);
	monitor(table, philo);
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(table->forks);
	pthread_mutex_destroy(&table->safe);
	free(table->forks);
	free(table);
	free(philo);
	return (0);
}

int	check_argv(int argc, char **argv)
{
	t_check	t;

	t.i = 0;
	t.argv_split = NULL;
	while (++t.i <= argc)
	{
		fre_all(t.argv_split);
		t.argv_split = ft_split(argv[t.i], ' ');
		if (!t.argv_split || !*t.argv_split)
			return (fre_all(t.argv_split));
		t.j = -1;
		while (t.argv_split[++t.j])
		{
			t.tmp = ft_atoi(t.argv_split[t.j]);
			t.itoa_set = ft_itoa(t.tmp);
			if (ft_strcmp(t.argv_split[t.j], t.itoa_set) == -1)
			{
				free (t.itoa_set);
				return (fre_all(t.argv_split));
			}
			free(t.itoa_set);
		}
	}
	fre_all(t.argv_split);
	return (0);
}

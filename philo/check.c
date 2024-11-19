/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:10:03 by junsepar          #+#    #+#             */
/*   Updated: 2023/08/12 18:21:12 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	fre_all(char **str)
{
	int	i;

	if (str)
	{
		i = 0;
		while (str[i])
			free(str[i++]);
		free(str);
	}
	return (1);
}

int	init_check(t_table *table, char **argv)
{
	if (table->number_of_philosophers <= 0 || table->time_to_die <= 0 \
		|| table->time_to_eat <= 0 || table->time_to_sleep <= 0)
		return (1);
	if (table->number_of_philosophers > 2147483647 || \
		table->time_to_die > 2147483647 || \
		table->time_to_eat > 2147483647 || \
		table->number_of_times_each_philosopher_must_eat > 2147483647)
		return (1);
	if (argv[5])
	{
		if (ft_atoi(argv[5]) <= 0 || 2147483647 < ft_atoi(argv[5]))
			return (1);
		table->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	}
	else
		table->number_of_times_each_philosopher_must_eat = -1;
	return (0);
}

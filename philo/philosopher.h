/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:33:12 by junsepar          #+#    #+#             */
/*   Updated: 2023/08/12 18:13:29 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_table
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	long long		start;
	int				count;
	struct s_philo	*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	safe;
	pthread_mutex_t	print;
}				t_table;

typedef struct s_philo
{
	struct s_table	*table;
	int				no;
	int				left;
	int				right;
	int				eat_cnt;
	long long		last_eat;
	pthread_t		thread;
}				t_philo;

typedef struct s_checkargument
{
	int				i;
	int				j;
	int				tmp;
	char			*itoa_set;
	char			**argv_split;
}				t_check;

int				fre_all(char **str);
int				ft_atoi(const char *str);
int				init_check(t_table *table, char **argv);
void			philo_print(t_philo *philo, char *mess, int flag);
t_philo			*philo_init(t_table *table);
t_table			*table_init(char **argv);
void			thread_clear(t_philo *philo);
void			monitor(t_table *table, t_philo *philo);
int				do_eat(t_philo *philo);
void			do_sleep(t_philo *philo);
void			do_think(t_philo *philo);
void			get_fork(t_philo *philo);
void			waaaait(int num);
void			*doing_thread(void *philo);
long long		ft_get_time(void);
int				print_error(char *str);
int				check_argv(int argc, char **argv);
int				ft_strcmp(char *s1, char *s2);
char			*ft_itoa(int n);
char			**ft_split(char const *s, char c);

#endif

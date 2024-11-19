/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 20:56:36 by junsepar          #+#    #+#             */
/*   Updated: 2023/08/12 17:55:29 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	sl(const char *str)
{
	int		i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

static int	ull_ch2(const char *str)
{
	int		i;
	char	*ull;

	ull = "18446744073709551615";
	i = 0;
	while (i < 20)
	{
		if (str[i] != ull[i])
		{
			if (str[i] > ull[i])
			{
				if (str[0] == '-')
					return (0);
				else
					return (-1);
			}
		}
		i++;
	}	
	return (1);
}

static int	ull_ch(const char *str, long long len)
{
	int		i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		len--;
		i++;
	}
	while (str[i] == '0')
	{
		len--;
		i++;
	}
	if (len > 20)
	{
		if (str[0] == '-')
			return (0);
		else
			return (-1);
	}
	if (len == 20)
		return (ull_ch2(&str[i]));
	return (1);
}

int	ft_atoi(const char *str)
{
	int					i;
	long long			ret;

	i = 0;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (ull_ch(str, sl(str)) <= 0)
		return (ull_ch(str, sl(&str[i])));
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return (0);
		i++;
	}
	ret = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		ret = ret * 10 + (str[i] - '0');
		i++;
		if (ret < 0)
			return (0);
	}
	return (ret);
}

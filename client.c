/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakman <fakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:46:00 by fakman            #+#    #+#             */
/*   Updated: 2023/02/15 13:53:35 by fakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	get_bit(int pid, char c)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(150);
	}
}

void	get_char(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		get_bit(pid, str[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc > 3)
	{
		ft_printf("Too argument error");
		return (0);
	}
	if (argc < 3)
	{
		ft_printf("Too low error");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	get_char(pid, argv[2]);
}

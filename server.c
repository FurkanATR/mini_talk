/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakman <fakman@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:46:05 by fakman            #+#    #+#             */
/*   Updated: 2023/02/15 14:38:00 by fakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	put_bin(char *array)
{
	int	i;
	int	res;
	int	base;

	i = 0;
	res = 0;
	base = 128;
	while (array[i])
	{
		if (array[i] == '1')
		{
			res = res + base;
			base = base / 2;
		}
		else
			base = base / 2;
		i++;
	}
	ft_printf("%c", res);
}

void	sig_handler(int signal)
{
	static char	*array;
	static int	bit;

	if (array == NULL)
		array = malloc(sizeof(char) * 9);
	if (signal == SIGUSR1)
		array[bit] = '0';
	else
		array[bit] = '1';
	bit++;
	if (bit == 8)
	{
		array[bit] = '\0';
		put_bin(array);
		free(array);
		array = NULL;
		bit = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("pid: %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		pause();
	}
}

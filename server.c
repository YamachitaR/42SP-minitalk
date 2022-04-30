/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:32:23 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/04/30 10:24:25 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"



void bit_to_char(int signal)
{
	static int base = 1;
	static char c = 0;


	if(signal == SIGUSR1)
		c += base;
	base *= 2;
	if(base == 256)
	{
		ft_putchar_fd(c, 1);
		base = 1;
		c = 0;	
	}	
}


int main (void)
{
	int pid;
	
	pid = getpid();
	ft_putstr_fd("The Serve PID:", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);

	signal(SIGUSR1, bit_to_char);
	signal(SIGUSR2, bit_to_char);
	
	while(1)
	{
		
	}
		
	return (0);
}
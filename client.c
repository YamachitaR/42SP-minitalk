/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:32:10 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/04/30 10:27:01 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"
static void char_to_bit(int pid, int c);
static void response(int signal);


int x = 1;
static void response(int signal)
{
	if(signal == SIGUSR2)
		x = 1;
}



static void char_to_bit(int pid, int c)
{
	int i = 0;
	int base = c;


	
	while (i<8)
	{
	
		if( x == 1)
		{
		if(base % 2 == 1)
			kill(pid, SIGUSR1);	
		else 
			kill(pid, SIGUSR2);
			
		base = base /2;
		i++;
		x = 0;
		}

	   signal(SIGUSR2, response);
		if(!x)
			pause();	
			
	}	
}

int main (int agrc, char **argv)
{
	int i;
	pid_t  pid;
	
	if(agrc != 3)
	{
		ft_putstr_fd("the argument is wrong!\n", 1);
		ft_putstr_fd("./client PID message\n", 1);
		return (0);
	}

	pid = ft_atoi(argv[1]);
	i = 0;

	while(argv[2][i])
	{
		char_to_bit(pid, argv[2][i]);
		i++;
	}
	char_to_bit(pid,'\n');
	return (0);
	
}
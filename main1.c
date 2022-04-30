

int main (int agrc, char **argv[])
{
	int i;
	int j;
	char *message;
	int  pid;
	
	if(agrc != 3)
	{
		ft_putstr_fd("the argument is wrong!\n", 1);
		ft_putstr_fd("./client PID message\n", 1);
		return (0);
	}
	i = 0;
	j = 0;
	pid = ft_atoi(argv[1]);
	message = argv[2];
	while (j < ft_strlen(message))
	{
		while(i < message[j])
		{
			usleep(25);
			kill(pid, SIGUSR1);
			i ++;
		}
		i = 0;
		j ++;
		kill(pid, SIGUSR2);
	}
	
	
	return (0);
	
}
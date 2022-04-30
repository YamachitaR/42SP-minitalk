#include <stdio.h>
# include <signal.h>



void nome(int signal)
{
	printf("%d", signal);
	if(signal == SIGUSR1)
		printf("nome\n");
	else
		printf("outra coisa \n");
}


int main (void)
{
	int i;
	i = 0;
	printf("O id= %d \n", getpid());
	signal(SIGUSR1, nome);
	signal(SIGUSR2, nome);

	while( 1)
	{
		
	}
	
	return (0);
}
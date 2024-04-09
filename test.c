#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>

int mails = 0;

void	*ft_routine()
{
	//printf("Hello from the thread\n");
	//sleep(3);
	//printf("Good bye from the thread\n");
	for (int i = 0; i < 1000000; i++)
		mails++;
}

int	main(void)
{
	pthread_t	t1;
	pthread_t	t2;

	if (pthread_create(&t1, NULL, &ft_routine, NULL) != 0)
		return (1);
	if (pthread_create(&t2, NULL, &ft_routine, NULL) != 0)
		return (1);
	if (pthread_join(t1, NULL) != 0)
		return (1);
	if (pthread_join(t2, NULL) != 0)
		return (1);
	printf("Valor de mails: %d\n", mails);
	return (0);
}

/*int	main(int argc, char **argv)
{
	int	x;
	int	pid;

	x = 2;
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
		x++;
	sleep(2);
	printf("value of x: %d\n", x);
	if (pid != 0)
		wait(NULL);
	return (0);
}*/

#include <stdio.h>
#include <pthread.h>

void	*ft_routine()
{
	printf("Hello from the thread");
}

int	main(void)
{
	pthread_t	t1;

	pthread_create(&t1, NULL, &ft_routine, NULL);
	pthread_join(t1, NULL);
	return (0);
}

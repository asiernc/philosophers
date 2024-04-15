/*#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

int balance = 0;

void write_balance(int new_balance)
{
  usleep(250000);
  balance = new_balance;
}

int read_balance()
{
  usleep(250000);
  return balance;
}

void* deposit(void *amount)
{
  pthread_mutex_lock(&mutex);

  int account_balance = read_balance();
  account_balance += *((int *) amount);
  write_balance(account_balance);
  pthread_mutex_unlock(&mutex);

  return NULL;
}

int main()
{
  pthread_mutex_t	mutex;

  int before = read_balance();
  printf("Before: %d\n", before);
  pthread_t thread1;
  pthread_t thread2;
  pthread_mutex_init(&mutex, NULL);
  int deposit1 = 300;
  int deposit2 = 200;
  pthread_create(&thread1, NULL, deposit, (void*) &deposit1);
  pthread_create(&thread2, NULL, deposit, (void*) &deposit2);
  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  pthread_mutex_destroy(&mutex);
  int after = read_balance();
  printf("After: %d\n", after);
  return 0;
}*/

/*#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

// Define ANSI escape sequences for colors and styles
#define BOLD_CYAN "\033[1;36m"
#define RESET "\033[0m"

int main()
{
    struct timeval start, end;

    gettimeofday(&start, NULL); // Get the current time before sleeping
    usleep(500000);  // Expected sleep: 500 milliseconds (0.5 seconds)
    gettimeofday(&end, NULL);  // Get the time after sleeping

    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;

    double elapsedMilliseconds = (seconds * 1000.0) + (microseconds / 1000.0);

    printf("Expected sleep duration: "BOLD_CYAN"\t500 milliseconds\n"RESET);
    printf("Actual sleep duration: "BOLD_CYAN"\t\t%.2f milliseconds\n\n"RESET, elapsedMilliseconds);

    return 0;
}*/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

// Assuming these functions are defined elsewhere in your code.
int ft_usleep(size_t milliseconds);
size_t get_time(void);

int main() {
    size_t start_time, end_time, elapsed_time;
    size_t sleep_duration = 1000;  // Sleep duration in milliseconds

    // Get the current time before sleep
    start_time = get_time();
    printf("Starting sleep at: %zu ms\n", start_time);

    // Call your custom usleep function
    ft_usleep(sleep_duration);

    // Get the current time after sleep
    end_time = get_time();
    printf("Woke up at: %zu ms\n", end_time);

    // Calculate the elapsed time
    elapsed_time = end_time - start_time;
    printf("Requested sleep time was %zu ms, and the measured sleep time was %zu ms.\n", sleep_duration, elapsed_time);

    return 0;
}

int	ft_usleep(size_t miliseconds)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < miliseconds)
		usleep(500);
	return (0);
}

size_t	get_time(void)
{
	struct timeval	time_value;

	if (gettimeofday(&time_value, NULL) == -1)
		return (0);
	return ((time_value.tv_sec * 1000) + (time_value.tv_usec / 1000));
}

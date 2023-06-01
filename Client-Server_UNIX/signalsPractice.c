/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signalsPractice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:35:16 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/06/01 18:55:30 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


void	signal_handler(int signal_number)
{
	printf("Received signal: %d\n", signal_number);
}

/*
Sending signals with kill()
*/
void	signal_handler1(int signal_number)
{
	printf("Received SIGUSR1 signal\n");
}

int	signals1()
{
	pid_t	pid;
	int		res;

	pid = getpid();
	printf("My process ID: %d\n", pid);

	sleep(2);

	res = kill(pid, SIGUSR1);
	if (res == 0)
		printf("SIGUSR1 signal sent successfully.\n");
	else
	{
		perror("Error sending signal");
		return (1);
	}

	sleep(5);

	return (0);
}
/*
In this example, the program obtains its own process ID (pid) and prints it.
After a delay, it uses the kill() function to send the SIGUSR1 signal to itself.
The signal handler is defined to hande the SIGUSR1 signal and prints the message. 
*/

int	sigempysetpractice()
{
	sigset_t	signal_set;

	if (sigemptyset(&signal_set) == -1)
		printf("Error executing sigemptyset()");

	//Add signals to the set using sigaddset() and sigfillset()
}

/*
The signal_set is now an empy set.
*/



// struct sigaction
// {
// 	void	(*sa_handler)(int);
// 	void	(*sa_sigaction)(int, siginfo_t *, void *);
// 	sigset_t	sa_mask;
// 	int			sa_flag;
// 	void		(*sa_restorer)(void);
// };

void	signal_handler3(int signal_number)
{
	printf("Received signal: %d \n", signal_number);

	//Additional signal haning
}

void	ft_sigaction()
{
	struct sigaction sa;

	sa.sa_handler = signal_handler3;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;

	if (sigaction(SIGINT, &sa, NULL) == -1)
	{
		perror("sigaction");
		return (-1);
	}

	//main program logic
}

int	main()
{
	int n = signals1();
	return 0;
}


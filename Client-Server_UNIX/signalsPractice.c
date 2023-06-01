/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signalsPractice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:35:16 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/06/01 17:49:57 by mdiez-as         ###   ########.fr       */
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

	sleep(5);

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

int	main()
{
	int n = signals1();
	return 0;
}


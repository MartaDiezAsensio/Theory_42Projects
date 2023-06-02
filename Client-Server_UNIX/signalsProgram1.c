/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signalsProgram.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:35:16 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/06/01 23:34:25 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

/*
Be careful with functions inside signal hadlers. They need to be able to run asynchronously
(they can interrupt the code at any time). So look at the functions that arer signal hadler safe.
printf is not one of theem but write is. Try to use that instead.
*/

void	signal_handler(int signum)
{
	printf("Received signal: %d\n", signum);
	printf("Exiting the program.\n");
	exit(0);
}

int	main()
{
	struct sigaction sa;

	sa.sa_handler = signal_handler;
	// sigemptyset(&sa.sa_mask);
	// sa.sa_flags = 0;

	if (sigaction(SIGINT, &sa, NULL) == -1)
	{
		perror("sigaction");
		return 1;
	}

	//Another way, using signal(). For portability reasons is better to use sigaction()

	//signal(SIGINT, &signal_handler(SIGINT));

	printf("Press Ctrl+C to send a SIGINT signal.\n");

	while (1)
	{
		printf("Inside the main program loop.\n");
		sleep(1);
	}

	return 0;
	
}


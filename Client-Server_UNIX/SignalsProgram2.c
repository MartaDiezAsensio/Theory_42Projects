/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SignalsProgram2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:35:16 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/06/02 09:09:35 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

struct Person
{
	int		age;
	char	*name;
};

static struct Person p1;

void	handle_sigusr1(int sig)
{
	if (p1.age == 0)
	{
		write(1, "\nPlease, enter your details.\n", 28);
		free(p1.name);
	}
}

int	main(void)



{
	int	pid;
	struct sigaction	sa;

	pid = fork();
	if (pid == -1)
		return (1); 

	p1.name = (char *)malloc(sizeof(char) * 100);
	if (!p1.name)
		return (1); 
	
	if (pid == 0)
	{
		sleep(3); 							//Wait for 3s
		kill(getppid(), SIGUSR1); 			//Send signal to parent process, there send message
	}
	else
	{	
		p1.age = 0;

		sa.sa_flags = SA_RESTART; 			//Just because we are using scanf(). Otherwise no need to specify.
		sa.sa_handler = &handle_sigusr1;
		sigaction(SIGUSR1, &sa, NULL);

		printf("Enter your NAME: ");
		scanf("%s", p1.name);
		wait(NULL);
		printf("\n");
		printf("Enter your AGE: ");
		scanf("%d", &p1.age);
		wait(NULL);
	}
}
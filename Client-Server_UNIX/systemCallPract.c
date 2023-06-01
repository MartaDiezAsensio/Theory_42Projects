/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   systemCallPract.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiez-as <mdiez-as@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:53:42 by mdiez-as          #+#    #+#             */
/*   Updated: 2023/06/01 16:59:48 by mdiez-as         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

/*
Here global variable change in one process does not affect the other one
because the data/state of the two processes is different. And also hild and
parent run "su¡imultaneously".
*/

void	forkexample()
{
	int	id;
	int	n = 1;
	
	id = fork();
	if (id == 0)
		printf("This is child: %d\n", ++n);
	else
		printf("This is Parent: %d\n", --n);
}

/*
fork() vs exec()

The fork()system call creates a new process. The new process created by fork() is
a copy of the current process except for the returned value. 
On the other hand, the exec() system call replaces the current process with a  new 
program.
The exec() call is often used after fork() call in the child process to load a different
program or script. The exec() call takes the path to the new program as an argument,
along with anu¡y comman-line arguments that need to be passedd to the program.
*/

int	diff_forkExec()
{
	pid_t	child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (child_pid == 0)
	{
		//Replace chilid proces with a different program

		char *args[] = {"ls", NULL};
		if (execvp("ping", args))
		{
			perror("execvp");
			return (-1);
		}
	}
	else
	{
		//wait for the child process too complete, then execute.
		printf("Child process completed\n");
	}
	return (0);
}

/*
|^Notes on the above code

	- pid_t: data type used in c to represent PIDs in Unix-like OSs. 
	(equivalent to int or long int). Used in various system calls and 
	functions related to process management (fork(), wait(), kill()). 
	
	- fuction perror(): Function used to printan error message corresponfing 
	to the current value of the global variable 'errno'. 
	
	- execvp(): C function used to execute a program by replacing the current 
	process image with a new one. vp is typically used when you want to execute
	a program with a specified name without providing the full path to the executable.
		int	execvp(cont char *file, char const *argv[]);

		- FILE specifies the name or path of the executable path.
		- ARGV agument is an array of strings that represent the command line
		arguments to be passed to the new program. The last element of argv array
		must always be a NULL. (similar architecture to printf). 
*/

void	waitPractice1()
{
	if (fork() == 0)
		printf("Hello from child process\n");
	else
	{
		printf("Hello form parent\n");
		wait(NULL);
		printf("Child has terminated\n");
	}
	printf("bye\n");
}

void	waitPractice2()
{
	pid_t	cpid;

	if (fork() == 0)
		exit(0); 					/*Terminate child*/
	else
		cpid = wait(NULL); 			/*Reaping parent*/
	
	printf("Parent pid = %d\n", getpid());
	printf("child pid = %d\n", cpid);
}

void	waitPractice3()
{
	int	n;
	int	id;

	id = fork();
	if (id == 0)
		n = 1;
	else
	{
		n = 10;
		wait(NULL);
	}
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", n + i);
	}
	if (id != 0)
		printf("\n");
}

int	main()
{
	waitPractice2();
	return 0;
}

SIGNALS is C

A signal is a software geerated interrupt that is sent toa process by the OS
because of when user, for example, press Ctrl-c or another process tells
something to the process. 

There are fix set of signals that can be sent to a process. signals are identified
by integers. 
Signal numbers have symbolic names. For example SIGCHLD is a number of the 
signal sent to the parent process when child terminates (as seen in previous examples).

Examples

#define SIGHUP  1   /* Hangup the process */ 
#define SIGINT  2   /* Interrupt the process */ 
#define SIGQUIT 3   /* Quit the process */ 
#define SIGILL  4   /* Illegal instruction. */ 
#define SIGTRAP 5   /* Trace trap. */ 
#define SIGABRT 6   /* Abort. */

These are some of the key points to understand about signals in c

	1. Signal Basics
		- Signals represent asynchronous events that can occur at any
		time during the execution of a program. When a signal occurs, the 
		Operatinf System interrupts the normal flow of the program and 
		delivers the signal to the process.  

	2. Signal Handling
		- This involves defining hoe a process should respond to a specific
		signal. signal handling is performed using signal hadlers, which are 
		functions that are invoked when a particular signal occurs. A signal
		handler can pform custom actions, ignore the signal or restore the 
		default behaviour. 

	3. Signal numbers
		- Each signal is identified by a unique signal number. Signal numbers
		are defined as constants in C library 'signals.h'. For example, 'SIGINT'
		is the signal number for the interrupt signal(Ctr+c).

	4. Handling sugnals with signal()
		- The signal() function is used to stablish a sigal handler for a specific
		signal. It takes two arguments: The signal number and the function pointer 
		to the signal handler. 

	5. Default Signal Handlin 
		- Each signal has a default behavior defined by the operatig system (terminate 
		process, ignore signal...). By setting a signal handler, you can override the 
		default behaviour and define custom actions. 

	6. Handling signals with sigaction()
		- The sigaction() function provides a more advanced and reliable way to handle
		signals compared to signal(). It allows more control over the behaviour of
		signals and includes other features. 

Overall Signals provide a mechanism for interprocesses communication, error handling and
managing program execution flow in reesponse to external events.  

FUNCTIONS NEEDED IN MINITALK

	- signal()
		- SIGUSR1 and SIGUSR2
			- These signals are not assigned any specifc meaning by the operating system.
			Instead, they are proided as a general purpose signals that can be used by user
			applications to eestablish their own signaling mechanism or to communicate specific
			events between processes. 

			the primary purpose of SIGUSR1 and SIGUSR2 signals is to allow applications or
			processes to define their own custom behaviours upon receiving these signals. applications
			can register signal handlers forSIGUSR1 and 2 to perform certain actions or initiate
			specific processes when these signals are received.

			In summary, SIGUSR1 and SIGUSR2 are user-defined signals that can be used by applications 
			to implement custom signaling mechanisms or communicate specific events between processes. 
			Their behavior and handling are determined by the application itself.

	- sigemptyset()
		- This function is used to initialize a signa set to an empty set. A data signal set is a data 
		structure that represents a collection of signals. 
			int	sigemptyset(sigset_t *set);
		The set parameter is  a pointer to the signal set that we want to initialize. 
		* See typical usein examples. 

	- sigaddset()
		- int	sigaddset(sigset_t *set, int signal_number);

	- sigaction()
		- The sigaction() function is used to examineor modify the acion taken by a process upon 
		receiving a specific signal. It allows you to set up signal handling behaviour, such as defining
		a signal handler function, specifying signal flags, and accessing the previous signal disposition.
			int	sigaction(int signal_number, const struct sigaction *act, struct sigaction *oldact);
		Parameter description:
			- signal_number: Signal number of the signal you want to modify/examine.
			- act: A pointer to a struct sigaction object that specifies the new signal action. 
			This includes the signal hadler function, sgnal flags, and other attributes.
			- oldact: A pointer to a struct sigaction object that will receive the previous signal action.
			*See struct sigaction in examples.  

	- kill()
		- This system call allows a process to send a signal to another process or group
		of processes. it provides a mechanism for interpocesses communication and process management.
			int	kill(pid_t pid, int signal),
		The PID argument specifies the process ID off the target process or process group and the 'signal' 
		argument specifies the signal to be sent.

		These are some important points to understand about kil()
			1. Sending Signals: if pid > 0 sends signal to the process with specified PID.
			if pid == 0 sends signal to all processes in the current process group.
			if pid == -1 sends signal to all processes for which the calling process has permision. 

			2. Signal numbers: signal parameter can take any signal int defined by signals.h header.
			3. Signal handling: Signal process is customizable.
			4. Error handling: kill() function returns -1 when an error has occurred. 

	- getpid()
		- Function that returns the PId of the current process

	- pause()
	- sleep()
		Adds a delay between actions, in this case to wait for signals to arrive. 
	- usleep()
	- exit()



	Struct sigaction

	sigaction is the improved version of signal() systtem call. 

	The struct sigacttion is used to define the behaviour of a signal in C.
	It contains several members that allow you to specify the action to be taken when a signal occurs,
	control signal masking and configure additional signal hadling attributes. 

		Struct	sigaction
		{
			void		(*sa_handler)(int);
			void		(*sa_sigaction)(int, siginfo_t *, void *);
			sigset_t	sa_mask;
			int			sa_flags;
			void		(*sa_restorer)(void);
		}

	There are various methods to send signals programmatically or via the command line. Here are a few examples:
		- Sending signals programmatically
			- Using the kill() function: you can use the kill() funtion to send a specific signal to a process 
			identified by it's PID. 
				int kill(pid_t pid, int sig);
			ex. Kill(1234, SIGTEERM).

			- Using the raise() function: thiis function allows a process to send a signal to itself.
				int raise(int sig);
			For instance to send a SIIGUSR1 signal to the current process.
		
		- Sending signals from the command line
			- Using kill command following the syntax: kill -SIGNUM PID for example (kill -TERM 1234) This sends a
			SIGTERM signal to the process with pid 1234. 

	THeses are some of thte SIGNALS:

		SIGHUP	- Hangup
		SIGINT	- Interrupt
		SIGQUIT	- Quit
		SIGILL	- Illegal instruction
		SIGTRAP	- Trace/breakpoint trap
		SIGABRT	- Aborted
		SIGIOT	- IOT trap (abort)
		SIGBUS	- Bus error




	PROCESSES vs THREADS
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void sighup();
void sigint();
void sigquit();

int main()
{
	int pid;
	pid = fork();
	if (pid == 0)
    {
		signal(SIGHUP, sighup);
		signal(SIGINT, sigint);
		signal(SIGQUIT, sigquit);
		for (;;)
			;
	}

	else
		{
			printf("\nPARENT: sending SIGHUP\n\n");
			kill(pid, SIGHUP);
			sleep(3); // pause for 3 seconds

			printf("\nPARENT: sending SIGINT\n\n");
			kill(pid, SIGINT);
			sleep(3); // pause for 3 seconds

			printf("\nPARENT: sending SIGQUIT\n\n");
			kill(pid, SIGQUIT);
			sleep(3); // pause for 3 seconds
		}
  return 0;
}

// function definition of sighup()
void sighup()
{
	signal(SIGHUP, sighup); /* reset signal */
	printf("CHILD: I have received a SIGHUP\n");
}

// function definition of sigint()
void sigint()
{
	signal(SIGINT, sigint); /* reset signal */
	printf("CHILD: I have received a SIGINT\n");
}

// function definition of sigquit()
void sigquit()
{
	printf("CHILD : Killed\n");
	exit(0);
}

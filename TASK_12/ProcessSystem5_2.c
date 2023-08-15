// Client
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>

#include<sys/msg.h>

struct my_msg_st
{
	long int my_msg_type;
	char some_text[BUFSIZ];
};

int main()
{
	int running = 1;
	int msgid;
	struct my_msg_st data;
	long int msg_to_receive = 0;

	msgid = msgget( (key_t)1234,0666 );

	while (running)
	{
		msgrcv(msgid, (void*)&data,BUFSIZ,msg_to_receive,0);

		printf("You Wrote: %s",  data.some_text);
		if(strncmp(data.some_text, "end", 3)== 0)
		{
			running = 0;
		}
	}

	exit(EXIT_SUCCESS);
}
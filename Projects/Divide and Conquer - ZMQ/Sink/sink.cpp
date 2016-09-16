// sink.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "zhelpers.h"

//
//  Task sink
//  Binds PULL socket to tcp://localhost:5558
//  Collects results from workers via that socket
//

int main(void)
{
	//  Prepare our context and socket
	void *context = zmq_ctx_new();
	if (context == NULL)
		return errno;
	void *receiver = zmq_socket(context, ZMQ_PULL);
	if (receiver == NULL)
		return errno;
	if (zmq_bind(receiver, "tcp://*:5558") == -1)
		return errno;

	//  Wait for start of batch
	char *string = s_recv(receiver);
	if (string == NULL)
		return errno;
	free(string);

	//  Start our clock now
	int64_t start_time = s_clock();

	//  Process 100 confirmations
	int task_nbr;
	for (task_nbr = 0; task_nbr < 100; task_nbr++) {
		char *string = s_recv(receiver);
		if (string == NULL)
			return errno;
		free(string);
		if ((task_nbr / 10) * 10 == task_nbr)
			printf(":");	// displays : at every 10th confirmation
		else
			printf(".");	// displays . for every confirmation
		fflush(stdout);
	}
	//  Calculate and report duration of batch
	printf("Total elapsed time: %d msec\n",
		(int)(s_clock() - start_time));

	zmq_close(receiver);
	zmq_ctx_destroy(context);
	
	system("pause");
	return 0;
}

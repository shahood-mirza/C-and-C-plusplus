// master.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "zhelpers.h"

//
//  Task ventilator
//  Binds PUSH socket to tcp://localhost:5557
//  Sends batch of tasks to workers via that socket
//

int main(void)
{
	void *context = zmq_ctx_new();
	if (context == NULL)
		return errno;

	//  Socket to send messages on
	void *sender = zmq_socket(context, ZMQ_PUSH);
	if (sender == NULL)
		return errno;
	if (zmq_bind(sender, "tcp://*:5557") == -1)
		return errno;

	//  Socket to send start of batch message on
	void *sink = zmq_socket(context, ZMQ_PUSH);
	if (sink == NULL)
		return errno;
	if (zmq_connect(sink, "tcp://localhost:5558") == -1)
		return errno;

	printf("Press Enter when the workers are ready: ");
	getchar();
	printf("Sending tasks to workers...\n");

	//  The first message is "0" and signals start of batch
	if (s_send(sink, "0") == -1)
		return errno;

	//  Initialize random number generator
	srandom((unsigned)time(NULL));

	//  Send 100 tasks
	int task_nbr;
	int total_msec = 0;     //  Total expected cost in msec
	for (task_nbr = 0; task_nbr < 100; task_nbr++) {
		int workload;
		//  Random workload from 1 to 100 msec
		workload = randof(100) + 1;
		total_msec += workload;
		char string[10];
		sprintf_s(string, "%d", workload);
		if (s_send(sender, string) == -1)
			return errno;
	}
	printf("Total expected cost: %d msec\n", total_msec);
	Sleep(1);	// Give 0MQ time to deliver

	zmq_close(sink);
	zmq_close(sender);
	zmq_ctx_destroy(context);
	
	system("pause");
	return 0;
}

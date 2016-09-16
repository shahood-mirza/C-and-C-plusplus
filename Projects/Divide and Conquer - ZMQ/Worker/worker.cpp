// worker.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "zhelpers.h"

//
//  Task worker
//  Connects PULL socket to tcp://localhost:5557
//  Collects workloads from ventilator via that socket
//  Connects PUSH socket to tcp://localhost:5558
//  Sends results to sink via that socket
//

int main(void)
{
	void *context = zmq_ctx_new();
	if (context == NULL)
		return errno;

	//  Socket to receive messages on
	void *receiver = zmq_socket(context, ZMQ_PULL);
	if (receiver == NULL)
		return errno;
	if(zmq_connect(receiver, "tcp://localhost:5557") == -1)
		return errno;

	//  Socket to send messages to
	void *sender = zmq_socket(context, ZMQ_PUSH);
	if (sender == NULL)
		return errno;
	if (zmq_connect(sender, "tcp://localhost:5558") == -1)
		return errno;

	//  Process tasks forever
	while (1) {
		char *string = s_recv(receiver);
		if (string == NULL)
			return errno;
		//  Simple progress indicator for the viewer
		fflush(stdout);
		printf("%s.", string);

		//  Do the work
		s_sleep(atoi(string));
		free(string);

		//  Send results to sink
		if (s_send(sender, "") == -1)
			return errno;
	}
	zmq_close(receiver);
	zmq_close(sender);
	zmq_ctx_destroy(context);
	
	system("pause");
	return 0;
}

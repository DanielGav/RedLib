

#include <stdlib.h>  
#include <mqueue.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <sys/time.h>



std::string getNow()
{
	
	timeval curTime;
	gettimeofday(&curTime, NULL);
	int milli = curTime.tv_usec / 1000;

	char buffer [80];
	strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", localtime(&curTime.tv_sec));

	char currentTime[84] = "";
	sprintf(currentTime, "%s.%d", buffer, milli);
	return currentTime;
}

int main (int argc, char **argv)
{
	if(argc > 1)
	{
		std::string client_queue_name = argv[1];

		std::string dispatch_queue_name = "/dispatch";
		mqd_t mqd_pro;
		mqd_t mqd_dis;   // queue descriptors
		struct mq_attr _attr1;
		struct mq_attr _attr2;
		
		std::cout << "Opening process message queue " << argv[1] << std::endl;

		mqd_pro = mq_open(client_queue_name.c_str(), O_RDWR | O_CREAT, 0665, 0);
		if (mqd_pro == -1) 
		{
			std::cout << "Error opening message queue" << std::endl;
			exit(1);
		}
		mq_getattr(mqd_pro, &_attr1);
		
		std::cout << "Opening dispatcher message queue " << dispatch_queue_name << std::endl;
		mqd_dis = mq_open(dispatch_queue_name.c_str(), O_RDWR | O_CREAT, 0665, 0);
		if (mqd_dis == -1) 
		{
			std::cout << "Error opening message queue" << std::endl;
			exit(1);
		}
		mq_getattr(mqd_dis, &_attr2);
		
		while(true) 
		{
			// Default max message size is set to 8192 bytes, so we create a 9000 byte buffer
			char *buffer = new char[9000];
			unsigned int _prio = 1;
			memset(buffer, '\0', 9000);
			std::cout << "Reading message from queue " << std::string(argv[1]) << "..." << std::endl;
			if(mq_receive(mqd_pro, buffer, 9000, &_prio) == -1) 
			{
				std::cout << "Error reading message" << std::endl;
				exit(1);
			}
			std::cout << "(" << getNow() << ") Recived:" << std::string(buffer) << std::endl;
			delete [] buffer;
			std::cout << "Sending request...";
			std::string send = std::string(argv[1]) + std::string(" - ") + getNow() ;
			mq_send(mqd_dis, send.c_str(), send.length(), _prio);
			std::cout << "OK" << std::endl;
			
		}
		

	}
	else	
	{
		std::cout << "Run as: proccesX <queue_name>" << std::endl; 
		exit(1);
	}
	exit(0);
}

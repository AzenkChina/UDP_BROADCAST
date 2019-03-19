// TEST_CPP.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include "comm_socket.h"
#if defined ( __linux )
#include <unistd.h>
#endif

int main()
{
	//实例化一个接收器
	class CommReceiver Receiver(20001);
	//实例化一个发送器
	class CommEmitter Emitter(20001);
	uint8_t buff[32];

	memset(buff, 'A', sizeof(buff));

	//通过发送器发送数据
	std::cout << Emitter.Send(buff, sizeof(buff)) << std::endl;

#if defined ( _WIN32 ) || defined ( _WIN64 )
	Sleep(10);
#elif defined ( __linux )
	sleep(1);
#endif

	//通过接收器接收数据
	memset(buff, 0, sizeof(buff));
	std::cout << Receiver.Receive(buff, sizeof(buff)) << std::endl;

	//打印接收到的数据
	buff[31] = 0;
	std::cout << buff << std::endl;

#if defined ( _WIN32 ) || defined ( _WIN64 )
	system("pause");
#elif defined ( __linux )
	getchar();
#endif
    return 0;
}


// TEST_C.c : 定义控制台应用程序的入口点。
//
#include <stdio.h>
#include "comm_socket.h"
#if defined ( __linux )
#include <unistd.h>
#endif

int main()
{
	SOCKADDR_IN sin;
	uint8_t buff[32];

	//初始化一个发射器
	SOCKET send = emitter.open(20001, &sin);

	//初始化一个接收器
	SOCKET recv = receiver.open(20001);

	//发送数据
	memset(buff, 'A', sizeof(buff));
	printf("%d\n", emitter.write(send, &sin, buff, sizeof(buff)));
#if defined ( _WIN32 ) || defined ( _WIN64 )
	Sleep(10);
#elif defined ( __linux )
	sleep(1);
#endif
	//接收数据
	memset(buff, 0, sizeof(buff));
	printf("%d\n", receiver.read(recv, buff, sizeof(buff)));

	//打印接收的数据
	buff[31] = 0;
	printf("%s\n", buff);

	//关闭发射器
	emitter.close(send);

	//关闭接收器
	receiver.close(recv);

#if defined ( _WIN32 ) || defined ( _WIN64 )
	system("pause");
#elif defined ( __linux )
	getchar();
#endif
    return 0;
}


// TEST_CPP.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>
#include "comm_socket.h"
#if defined ( __linux )
#include <unistd.h>
#endif

int main()
{
	//ʵ����һ��������
	class CommReceiver Receiver(20001);
	//ʵ����һ��������
	class CommEmitter Emitter(20001);
	uint8_t buff[32];

	memset(buff, 'A', sizeof(buff));

	//ͨ����������������
	std::cout << Emitter.Send(buff, sizeof(buff)) << std::endl;

#if defined ( _WIN32 ) || defined ( _WIN64 )
	Sleep(10);
#elif defined ( __linux )
	sleep(1);
#endif

	//ͨ����������������
	memset(buff, 0, sizeof(buff));
	std::cout << Receiver.Receive(buff, sizeof(buff)) << std::endl;

	//��ӡ���յ�������
	buff[31] = 0;
	std::cout << buff << std::endl;

#if defined ( _WIN32 ) || defined ( _WIN64 )
	system("pause");
#elif defined ( __linux )
	getchar();
#endif
    return 0;
}


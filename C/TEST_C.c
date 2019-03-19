// TEST_C.c : �������̨Ӧ�ó������ڵ㡣
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

	//��ʼ��һ��������
	SOCKET send = emitter.open(20001, &sin);

	//��ʼ��һ��������
	SOCKET recv = receiver.open(20001);

	//��������
	memset(buff, 'A', sizeof(buff));
	printf("%d\n", emitter.write(send, &sin, buff, sizeof(buff)));
#if defined ( _WIN32 ) || defined ( _WIN64 )
	Sleep(10);
#elif defined ( __linux )
	sleep(1);
#endif
	//��������
	memset(buff, 0, sizeof(buff));
	printf("%d\n", receiver.read(recv, buff, sizeof(buff)));

	//��ӡ���յ�����
	buff[31] = 0;
	printf("%s\n", buff);

	//�رշ�����
	emitter.close(send);

	//�رս�����
	receiver.close(recv);

#if defined ( _WIN32 ) || defined ( _WIN64 )
	system("pause");
#elif defined ( __linux )
	getchar();
#endif
    return 0;
}


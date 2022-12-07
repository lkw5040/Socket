/*

#include<stdlib.h>
#include <stdio.h>
#include<WinSock2.h>
#include <WS2tcpip.h>

#pragma comment(lib, "ws2_32")

#define PORT 7777
#define SERVER_IP "127.0.0.1"

int main(void) {
	WSADATA wsaData = {0,};
	SOCKADDR_IN Addr = {0,};
	char strInput[MAX_PATH] = {0,}, cRecvBuf[MAX_PATH] = {0,};
	SOCKET hSocket = NULL;
	int nErrorCode = 0;

	WSAStartup(MAKEWORD(2, 2), &wsaData);

	hSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (hSocket == INVALID_SOCKET) {
		printf("Socket() Error!");
	}

	Addr.sin_family = AF_INET;
	Addr.sin_port = htons(PORT);
	inet_pton(AF_INET, SERVER_IP, &Addr.sin_addr);

	nErrorCode = connect(hSocket, (SOCKADDR*)&Addr, sizeof(Addr));
	if (nErrorCode == SOCKET_ERROR) {
		printf("connect() Error!");
	}
	printf("Connecting Success\n\n");

	while (1)	//true
	{
		memset(&strInput, 0, sizeof(strInput));
		printf("Client Send Msg : ");
		fgets(strInput, MAX_PATH, stdin);

		printf("A=",strcmp(strInput, "exit"), strInput);

		if (strcmp(strInput,"exit") == 0) {
			printf("프로그램 종료\n");
			break;
		}
		nErrorCode = send(hSocket, strInput, MAX_PATH, 0);
		if (nErrorCode == SOCKET_ERROR) {
			printf("Send() Error!");
		}
		memset(&cRecvBuf, 0, sizeof(cRecvBuf));
		nErrorCode = recv(hSocket, cRecvBuf, MAX_PATH, 0);
		if (nErrorCode == SOCKET_ERROR) {
			printf("Recv() Error!");
		}
		printf("\nServer From Msg : %s\n", cRecvBuf);
	}
	closesocket(hSocket);
	WSACleanup();

	return 0;
}

*/
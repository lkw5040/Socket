/*

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <WinSock2.h>
#include <WS2tcpip.h>

#pragma comment(lib, "ws2_32")

#define PORT 7777

int main() {
	printf("Server Working...\n\n");

	WSADATA wsaData = {0,};
	SOCKADDR_IN listnAddr = {0,};
	SOCKADDR_IN ClntAddr = {0,};
	char buf[MAX_PATH] = {0,};
	SOCKET hListen = NULL;
	int iClntSize = 0, nErrorCode = 0;

	WSAStartup(MAKEWORD(2, 2), &wsaData);

	hListen = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (hListen == SOCKET_ERROR) {
		printf("Socket Error!");
	}

	listnAddr.sin_family = AF_INET;
	listnAddr.sin_port = htons(PORT);
	listnAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	nErrorCode = bind(hListen, (SOCKADDR*)&listnAddr, sizeof(listnAddr));
	if (nErrorCode == SOCKET_ERROR) {
		printf("Bind() Error!");
		return 0;
	}

	nErrorCode = listen(hListen, SOMAXCONN);
	if (nErrorCode == -1) {
		printf("Listen() Error!");
		return 0;
	}
	iClntSize = sizeof(ClntAddr);

	SOCKET hClient = accept(hListen, (SOCKADDR*)&ClntAddr, &iClntSize);
	if (hClient == SOCKET_ERROR) {
		printf("Accept() Error!");
		return 0;
	}
	
	while (1) { //TRUE
		nErrorCode = recv(hClient, buf, MAX_PATH, 0);
		if (nErrorCode == SOCKET_ERROR) {
			printf("Recv() Error!");
			break;
		}

		printf("Client Msg = %s\n", buf);

		nErrorCode = send(hClient, buf, strlen(buf), 0);
		if (nErrorCode == SOCKET_ERROR) {
			printf("Send() Error!");
			break;
		}
	}
	closesocket(hListen);
	WSACleanup();
}

*/
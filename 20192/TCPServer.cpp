// TCPServer.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <winsock2.h>
#include <WS2tcpip.h>
#define SERVER_PORT 5500
#define SERVER_ADDR "127.0.0.1"
#define BUFF_SIZE 2048

int _tmain(int argc, _TCHAR* argv[])
{
	//Step 1: Initiate WinSock
	WSADATA wsaData;
	WORD wVersion = MAKEWORD(2,2);
	if(WSAStartup(wVersion, &wsaData))
		printf("Version is not supported\n");

	//Step 2: Construct socket	
	SOCKET listenSock;
	listenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	//Step 3: Bind address to socket
	sockaddr_in serverAddr;	
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(SERVER_PORT);
	serverAddr.sin_addr.s_addr = inet_addr(SERVER_ADDR);

	if(bind(listenSock,(sockaddr *)&serverAddr, sizeof(serverAddr)))
	{
		printf("Error! Cannot bind this address.");
		_getch();
		return 0;
	}
	
	//Step 4: Listen request from client
	if(listen(listenSock, 10)){
		printf("Error! Cannot listen.");
		_getch();
		return 0;
	}

	printf("Server started!");

	//Step 5: Communicate with client
	sockaddr_in clientAddr;
	char buff[BUFF_SIZE];
	int ret, clientAddrLen = sizeof(clientAddr);

	while(1){
		SOCKET connSock;

		//accept request
		connSock = accept(listenSock, (sockaddr *) & clientAddr, &clientAddrLen);

		//receive message from client
   		ret = recv(connSock, buff, BUFF_SIZE, 0);
   		if(ret == SOCKET_ERROR){
			printf("Error : %", WSAGetLastError());
			break;
		}
   		else if (strlen(buff) > 0){
			buff[ret] = 0;
   			printf("Receive from client[%s:%d] %s\n",
			inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port),buff);
				
			//Echo to client
   			ret = send(connSock, buff, strlen(buff), 0);
   			if(ret  == SOCKET_ERROR)
			printf("Error: %", WSAGetLastError());
   		}
		closesocket(connSock);
	} //end accepting

	//Step 5: Close socket
	closesocket(listenSock);
	
	//Step 6: Terminate Winsock
	WSACleanup();

	return 0;
}



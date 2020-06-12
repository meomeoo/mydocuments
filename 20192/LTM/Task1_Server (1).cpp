// SingleIOCPServer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <winsock2.h>
#include <WS2tcpip.h>
#include <fstream>
#include <cstring>
#include <process.h>
#include <queue> 


#define DATA_BUFSIZE 8192
#define RECEIVE 0
#define SEND 1

#define SERVER_ADDR "10.0.0.1"
#define BUFF_SIZE 2048


#pragma warning(disable : 4018)
#pragma warning(disable : 4996)
#pragma warning(disable : 4703)


#pragma comment(lib, "ws2_32.lib")

using namespace std;

bool userLogging[10000];
int clientActing[10000];
bool semaphore = false;


// Structure definition
typedef struct {
	WSAOVERLAPPED overlapped;
	WSABUF dataBuff;
	char buffer[DATA_BUFSIZE];
	int bufLen;
	int recvBytes;
	int sentBytes;
	int operation;
	SOCKET socket;

} PER_IO_OPERATION_DATA, *LPPER_IO_OPERATION_DATA;

typedef struct {
	SOCKET socket;
} PER_HANDLE_DATA, *LPPER_HANDLE_DATA;


queue <PER_IO_OPERATION_DATA> queueOfIoData; 

unsigned __stdcall serverWorkerThread(LPVOID CompletionPortID);
unsigned __stdcall serverHandleBussinessThread(LPVOID CompletionPortID);

void wait(){
	while(semaphore == true){}
	semaphore = true;
}

void signal(){
	semaphore = false;
}

// Fuction read content in file, if the userName exsit in flie return the position of user in flie (the position strat form 0)
// if the userName not esxit in file return -1
int readAndCheckFromFile(char* userName, char* passWord, bool* checkUserName, bool* checkPassWord, bool* checkStatus) {
	string accountText;
	int n = -1;
	*checkUserName = false;
	*checkPassWord = false;
	*checkStatus = false;

	ifstream accountFile("account.txt");

	while (getline(accountFile, accountText))
	{
		// Output the text from the file
		if (*checkUserName == true)
			break;
		n += 1;
		int i = 0;
		string userNameFromFile = "";
		for (i; accountText[i] != ' '; ++i) {
			userNameFromFile += accountText[i];
		}
		if (userNameFromFile.compare(userName) == 0) {
			*checkUserName = true;
			string passWordFromFile = "";
			for (++i; accountText[i] != ' '; ++i) {
				passWordFromFile += accountText[i];
			}
			// kiem tra xem passWord co dung khong 
			if (passWordFromFile.compare(passWord) == 0) {
				*checkPassWord = true;
			}
			else
				*checkPassWord = false;
			// lay ra gia tri status
			if (accountText[i + 1] == '0')
				*checkStatus = true;
			else
				*checkStatus = false;
		}

	}
	// Close the file
	accountFile.close();
	if (*checkUserName == true) {
		return n;
	}
	else
	{
		return -1;
	}

}

// Fuction return position of userName in file (position start from 0)
// Return -1 if userName not exsit in file
int getPositionOfUser(char* userName) {

	bool checkUserName = false;
	string accountText;
	int n = -1;

	ifstream accountFile("account.txt");
	while (getline(accountFile, accountText))
	{
		n += 1;
		int i = 0;
		string userNameFromFile = "";
		for (i; accountText[i] != ' '; ++i) {
			userNameFromFile += accountText[i];
		}
		if (userNameFromFile.compare(userName) == 0) {
			checkUserName = true;
			return n;
		}
	}
	if (checkUserName == false)
		return -1;
}


// Block the status of userName in file
void updateFileStatus(string userName) {

	std::fstream file("account.txt", std::ios::in | std::ios::out);
	std::string user, pass;
	char status;
	while (file >> user >> pass)
		if (user == userName) {
			int pos = file.tellg();
			file >> status;
			++pos;
			file.seekp(pos);
			file << '1';
			break;
		}
		else {
			file >> status;
		}
		file.close();
		return;
}

// Fuction craft mess sent to client
void craftMessage(bool* checkUserName, bool* checkPassWord, bool* checkStatus, bool checkLogging, char* messToClient) {
	if (*checkUserName == true) {
		messToClient[0] = 1;
	}
	else {
		messToClient[0] = 0;
	}
	if (*checkPassWord == true) {
		messToClient[1] = 1;
	}
	else {
		messToClient[1] = 0;
	}
	if (*checkStatus == true) {
		messToClient[2] = 1;
	}
	else {
		messToClient[2] = 0;
	}
	if (checkLogging == true) {
		messToClient[3] = 1;
	}
	else
	{
		messToClient[3] = 0;
	}


}

// fuction wrap of send() 
void sendData(SOCKET connSock, char* buff, int dataLength) {

	int index = 0, nLeft = dataLength, ret;

	while (nLeft > 0) {
		ret = send(connSock, &(buff[index]), nLeft, 0);
		if (ret == SOCKET_ERROR) {
			cout << "\n\tError: " << WSAGetLastError() << " when sen data to server" << endl;
			break;
		}

		index += ret;
		nLeft -= ret;
	}
}

// fuction wrap of recv() 
bool recvData(SOCKET connSock, char* buff, int dataLength) {

	int index = 0, nLeft = dataLength, ret;

	while (nLeft > 0) {
		ret = recv(connSock, &(buff[index]), nLeft, 0);
		if (ret == SOCKET_ERROR) {
			return false;
		}

		index += ret;
		nLeft -= ret;
		buff[dataLength] = 0;
	}
	return true;
}


// Fuction recv request from server
// return 1 if request is log in
// return 2 if request is log out
// return 3 if request is exit

int recvDataFromClient(char* buff, char* userName, char* passWord) {
	int dataLength, ret = 0;

	if (buff[0] == 1) { // request from user is login
		dataLength = buff[1] - 2;
		buff = buff + 2;
		int position1 = 0, lengOfUserName = buff[1];
		for (int i = 0; i < lengOfUserName; ++i) {
			userName[i] = buff[2 + i];
		}
		userName[lengOfUserName] = 0;
		int position2 = 2 + lengOfUserName, lengOfPassWord = buff[position2 + 1];
		for (int i = 0; i < lengOfPassWord; ++i) {
			passWord[i] = buff[position2 + 2 + i];
		}
		passWord[lengOfPassWord] = 0;

		return 1;
	}
	else if (buff[0] == 2) {  // request from user is logout
		dataLength = buff[1] - 2;
		buff = buff + 2;
		int lengOfUserName = buff[1];
		for (int i = 0; i < lengOfUserName; ++i) {
			userName[i] = buff[2 + i];
		}
		userName[lengOfUserName] = 0;
		return 2;

	}
	else // request from user is exit (close connect)
		return 3;

}

bool checkLoggin(SOCKET connSock) {
	for (int i = 0; i < 10000; ++i) {
		if (clientActing[i] == int(connSock)) {
			if (userLogging[i] == true)
				return true;
			else
			{
				return false;
			}
		}
	}

	return false;
}



// fuction bussiness handle request in server
// buff is array char contain content of userName and passWord from client request
// userName, passWord is array char contain userName, passWord from client
// buffWrongOfUser save time of enter wrong password for one userName  
// buffWrongOfUser[i] = 1 mean i_th userName wronged 1 time (index of userName start from 0)
// if not more than 3 times wrong and logging success the value resart = 0
// messToClient array contain status of acount
bool bussiness(LPPER_HANDLE_DATA perHandleData, LPPER_IO_OPERATION_DATA perIoData) {
	char userName[100], passWord[100];
	char buffWrongOfUser[BUFF_SIZE];
	char messToClient[4];
	int clientActie;
	DWORD transferredBytes;
	char* buff = perIoData->buffer;
	cout << "recvByte: " << perIoData->recvBytes << endl;
	cout << "mess type: " << perIoData->buffer[0] << "messleng: " << perIoData->buffer[1] << endl;



	for (int i = 0; i < BUFF_SIZE; ++i) {
		buffWrongOfUser[i] = 0;
	}

	clientActie = recvDataFromClient(&(buff[0]), &(userName[0]), &(passWord[0]));
	cout << "actice: " << clientActie << endl; 
	bool checkUserName = false, checkPassWord = false, checkStatus = false;
	if (clientActie == 1) { // Handle request login
		int positionOfUser = readAndCheckFromFile(userName, passWord, &checkUserName, &checkPassWord, &checkStatus);
		if (userLogging[positionOfUser] == false) { // check userName present not logging
			if (positionOfUser != -1 && checkStatus == true) {
				if (checkPassWord == false) {
					buffWrongOfUser[positionOfUser] += 1;
					if (buffWrongOfUser[positionOfUser] == 4) {
						checkStatus = false;
						updateFileStatus(&(userName[0]));
					}
				}
				else // Log in successfull
				{
					buffWrongOfUser[positionOfUser] = 0;
					userLogging[positionOfUser] = true;
					clientActing[positionOfUser] = int(perHandleData->socket);

				}

			}
			craftMessage(&checkUserName, &checkPassWord, &checkStatus, false, &(messToClient[0]));

		}
		else {

			craftMessage(&checkUserName, &checkPassWord, &checkStatus, true, &(messToClient[0]));
		}

		memcpy(perIoData->buffer, messToClient, 4);

		ZeroMemory(&(perIoData->overlapped), sizeof(OVERLAPPED));
		perIoData->dataBuff.buf = perIoData->buffer;
		perIoData->dataBuff.len = 4;
		perIoData->operation = SEND;
		perIoData->sentBytes = 0;

		if (WSASend(perHandleData->socket,
			&(perIoData->dataBuff),
			1,
			&transferredBytes,
			0,
			&(perIoData->overlapped),
			NULL) == SOCKET_ERROR) {
			if (WSAGetLastError() != ERROR_IO_PENDING) {
				printf("WSASend() failed with error %d\n", WSAGetLastError());
				return 0;
			}
		}
		return true;
	}
	else if (clientActie == 2) { // Handle request logout
		if (userLogging[getPositionOfUser(&(userName[0]))] == true) {
			userLogging[getPositionOfUser(&(userName[0]))] = false;
			clientActing[getPositionOfUser(&(userName[0]))] = 0;
		}

		return true;

	}
	else { // Handle request exit (or close socket)
		cout << "\n\tClient with " << "socKet: " << (int)perHandleData->socket << " disconnected !" << endl;
		for (int i = 0; i < 10000; ++i) {
			if (clientActing[i] == int(perHandleData->socket)) {
				userLogging[i] = false;
				clientActing[i] = 0;
			}
		}
		if (closesocket(perHandleData->socket) == SOCKET_ERROR) {
			printf("closesocket() failed with error %d\n", WSAGetLastError());
			return 0;
		}
		return false;
	}
}



int main(int argc, char* argv[])
{

	ifstream ifile;
	ifile.open("account.txt");
	if (ifile) {
		ifile.close();
	}
	else {
		ofstream MyFile("account.txt");
		MyFile.close();
	}

	SOCKADDR_IN serverAddr;
	SOCKET listenSock, acceptSock;
	HANDLE completionPort;
	SYSTEM_INFO systemInfo;
	LPPER_HANDLE_DATA perHandleData;
	LPPER_IO_OPERATION_DATA perIoData;
	DWORD transferredBytes;
	DWORD flags;
	WSADATA wsaData;

	if (WSAStartup((2, 2), &wsaData) != 0) {
		printf("WSAStartup() failed with error %d\n", GetLastError());
		return 1;
	}

	// Step 1: Setup an I/O completion port
	if ((completionPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0)) == NULL) {
		printf("CreateIoCompletionPort() failed with error %d\n", GetLastError());
		return 1;
	}

	// Step 2: Determine how many processors are on the system
	GetSystemInfo(&systemInfo);

	for (int i = 0; i < 1; i++) {
		// Create a server worker thread and pass the completion port to the thread
		if (_beginthreadex(0, 0, serverHandleBussinessThread, NULL, 0, 0) == 0) {
			printf("Create thread failed with error %d\n", GetLastError());
			return 1;
		}
	}

	// Step 3: Create worker threads based on the number of processors available on the
	// system. Create two worker threads for each processor	
	for (int i = 0; i < (int)systemInfo.dwNumberOfProcessors * 2; i++) {
		// Create a server worker thread and pass the completion port to the thread
		if (_beginthreadex(0, 0, serverWorkerThread, (void*)completionPort, 0, 0) == 0) {
			printf("Create thread failed with error %d\n", GetLastError());
			return 1;
		}
	}

	// Step 4: Create a listening socket
	if ((listenSock = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED)) == INVALID_SOCKET) {
		printf("WSASocket() failed with error %d\n", WSAGetLastError());
		return 1;
	}

	u_short serverPort = (u_short)strtoul(argv[1], NULL, 0);
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddr.sin_port = htons(serverPort);
	if (bind(listenSock, (PSOCKADDR)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
		printf("bind() failed with error %d\n", WSAGetLastError());
		return 1;
	}

	// Prepare socket for listening
	if (listen(listenSock, 20) == SOCKET_ERROR) {
		printf("listen() failed with error %d\n", WSAGetLastError());
		return 1;
	}
	cout << "Server started !" << endl;

	//Step 5: Communicate with client

	cout << "\nListening new connect..." << endl;
	// Step 6: Create a socket information structure to associate with the socket
	if ((perHandleData = (LPPER_HANDLE_DATA)GlobalAlloc(GPTR, sizeof(PER_HANDLE_DATA))) == NULL) {
		printf("GlobalAlloc() failed with error %d\n", GetLastError());
		return 1;
	}

		// Step 8: Create per I/O socket information structure to associate with the WSARecv call
		if ((perIoData = (LPPER_IO_OPERATION_DATA)GlobalAlloc(GPTR, sizeof(PER_IO_OPERATION_DATA))) == NULL) {
			printf("GlobalAlloc() failed with error %d\n", GetLastError());
			return 1;
		}

	while (true)
	{
		// Step 5: Accept connections
		if ((acceptSock = WSAAccept(listenSock, NULL, NULL, NULL, 0)) == SOCKET_ERROR) {
			printf("WSAAccept() failed with error %d\n", WSAGetLastError());
			return 1;
		}
		// Step 7: Associate the accepted socket with the original completion port
		perHandleData->socket = acceptSock;
		if (CreateIoCompletionPort((HANDLE)acceptSock, completionPort, (DWORD)perHandleData, 0) == NULL) {
			printf("CreateIoCompletionPort() failed with error %d\n", GetLastError());
			return 1;
		}

		ZeroMemory(&(perIoData->overlapped), sizeof(OVERLAPPED));
		perIoData->sentBytes = 0;
		perIoData->recvBytes = 0;
		perIoData->dataBuff.len = DATA_BUFSIZE;
		perIoData->dataBuff.buf = perIoData->buffer;
		perIoData->operation = RECEIVE;
		flags = 0;

		if (WSARecv(acceptSock, &(perIoData->dataBuff), 1, &transferredBytes, &flags, &(perIoData->overlapped), NULL) == SOCKET_ERROR) {
			if (WSAGetLastError() != ERROR_IO_PENDING) {
				printf("WSARecv() failed with error %d\n", WSAGetLastError());
				return 1;
			}
		}
		printf("Socket number %d got connected...\n", acceptSock);


	}  //end while

	_getch();
	return 0;
}

unsigned __stdcall serverHandleBussinessThread(LPVOID completionPortID){

	PER_HANDLE_DATA perHandeData;
	PER_IO_OPERATION_DATA perIoData;
	LPPER_IO_OPERATION_DATA pointIoData;
	while (true)
	{
		wait();
		if (queueOfIoData.size() != 0) {
			pointIoData = &(queueOfIoData.front());
			perIoData.recvBytes = pointIoData->recvBytes;
			memcpy(perIoData.buffer, pointIoData->buffer, perIoData.recvBytes);
			perIoData.dataBuff.buf = perIoData.buffer;
			perIoData.dataBuff.len = perIoData.recvBytes;
			perIoData.sentBytes = 0;
			perIoData.operation = pointIoData->operation;
			perIoData.socket = pointIoData->socket;
			perHandeData.socket = perIoData.socket;
			queueOfIoData.pop();
			signal();
			bussiness(&perHandeData, &perIoData);
		}
		
	}

}



unsigned __stdcall serverWorkerThread(LPVOID completionPortID)
{
	HANDLE completionPort = (HANDLE)completionPortID;
	DWORD transferredBytes;
	LPPER_HANDLE_DATA perHandleData;
	LPPER_IO_OPERATION_DATA perIoData;
	DWORD flags;

	while (TRUE) {
		if (GetQueuedCompletionStatus(completionPort, &transferredBytes,
			(LPDWORD)&perHandleData, (LPOVERLAPPED *)&perIoData, INFINITE) == 0) {
			printf("GetQueuedCompletionStatus() failed with error %d\n", GetLastError());
			return 0;
		}
		cout << "1111111" << endl;

		cout << "socket: " << perHandleData->socket << endl;


		// Check to see if an error has occurred on the socket and if so
		// then close the socket and cleanup the SOCKET_INFORMATION structure
		// associated with the socket
		if (transferredBytes == 0) {
			printf("Closing socket %d\n", perHandleData->socket);
			if (closesocket(perHandleData->socket) == SOCKET_ERROR) {
				printf("closesocket() failed with error %d\n", WSAGetLastError());
				return 0;
			}
			perHandleData->socket = 0;
			continue;
		}
		// Check to see if the operation field equals RECEIVE. If this is so, then
		// this means a WSARecv call just completed so update the recvBytes field
		// with the transferredBytes value from the completed WSARecv() call
		if (perIoData->operation == RECEIVE) {
			perIoData->recvBytes = transferredBytes;
			perIoData->sentBytes = 0;
			perIoData->operation = SEND;
			perIoData->socket = perHandleData->socket;
			queueOfIoData.push(*perIoData);
			continue;

		}
		else if (perIoData->operation == SEND) {
			perIoData->sentBytes += transferredBytes;
		}

		if (perIoData->operation == SEND && transferredBytes == 4) {
			// No more bytes to send post another WSARecv() request
			perIoData->recvBytes = 0;
			perIoData->operation = RECEIVE;
			flags = 0;
			ZeroMemory(&(perIoData->overlapped), sizeof(OVERLAPPED));
			perIoData->dataBuff.len = DATA_BUFSIZE;
			perIoData->dataBuff.buf = perIoData->buffer;
			if (WSARecv(perHandleData->socket,
				&(perIoData->dataBuff),
				1,
				&transferredBytes,
				&flags,
				&(perIoData->overlapped), NULL) == SOCKET_ERROR) {
				if (WSAGetLastError() != ERROR_IO_PENDING) {
					printf("WSARecv() failed with error %d\n", WSAGetLastError());
					return 0;
				}
			}
		}
	}
}
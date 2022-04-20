#pragma once

#include <cassert>
#include <iostream>
#include <thread>
#include <vector>
#include <unordered_map>
#include <WinSock2.h>


#pragma comment(lib, "Ws2_32.lib")

#define SIZE 1024

namespace Net
{
class Server
{
private:
	WSADATA wsa;
	SOCKET serversocket;
	std::string ipaddress;
	int port;
	char buffer[SIZE];
	std::string message;
	struct sockaddr_in info;
	int infoLengh;
	int reciveleng;
public:
	Server(int, std::string);
	~Server();
public:
	void start();
	void stop();
private:
	void init();
	void receive();
	void send();
	void proccess();
};

}
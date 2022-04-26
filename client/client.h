#pragma once
  
#include <cassert>
#include <iosfwd>
#include <thread>
#include <vector>
#include <unordered_map>
#include <WinSock2.h>
#include <string>


#pragma comment(lib, "Ws2_32.lib")


#define SIZE 1024


namespace Net
{
	class Client
	{
	private:
		WSADATA wsa;
		SOCKET clientsocket;
		std::string ipaddress;
		int port;
		char buffer[SIZE];
		std::string message;
		struct sockaddr_in info;
		int infoLengh;
		int reciveleng;
	public:
		Client(int, std::string);
		~Client();
	public:
		void connect();
	private:
		void init();
		void receive();
		void send();
		void proccess();
	};

}
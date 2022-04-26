#include "client.h"
#include <iostream>



#pragma warning(disable: 4996)


namespace Net
{
	Client::Client(int port, std::string ipaddress)
		:
		wsa{ 0 },
		port(port),
		ipaddress(ipaddress),
		clientsocket(INVALID_SOCKET),
		info{ 0 },
		infoLengh(sizeof(info))
	{}


	void Client::init()
	{
		info.sin_family = AF_INET;
		info.sin_port = htons(port);
		info.sin_addr.s_addr = inet_addr(ipaddress.c_str());

		std::cout << "WSA init\n";
		if (WSAStartup(MAKEWORD(2, 2), &wsa))
		{
			std::cout << "COULDN'T INIT WSA\n";
		}
		//assert(!(WSAStartup(MAKEWORD(2,2), &wsa)) && "COULDN'T INIT WSA");
		std::cout << "WSA success\n";


		std::cout << "SOCKET creating\n";
		if ((clientsocket = socket(AF_INET, SOCK_DGRAM, 0)) == SOCKET_ERROR)
		{
			std::cout << "COULDN'T CREATE SOCKET\n";
		}

	//	assert(!((clientsocket = socket(AF_INET, SOCK_DGRAM, 0)) == SOCKET_ERROR) && "COULDN'T CREATE SOCKET");
		std::cout << "SOCKET success\n";


	}

	void Client::send()
	{
		std::cout << "enter messege\n";
		std::getline(std::cin, message);
		if ((sendto(clientsocket, message.c_str(), message.size(), 0, (struct sockaddr*)&info, infoLengh)) == SOCKET_ERROR)
		{
			std::cout << " send() failed...  " << WSAGetLastError();
			exit(EXIT_FAILURE);
		}
	}


	void Client::connect()
	{
		init();
		for (;;)
		{
			send();
			receive();
			proccess();
		}
	}

	void Client::receive()
	{

		if ((reciveleng = recvfrom(clientsocket, buffer, SIZE, 0, (struct sockaddr*)&info, &infoLengh)) == SOCKET_ERROR)
		{
			std::cout << " recv() failed...  " << reciveleng << ":" << WSAGetLastError();
			exit(EXIT_FAILURE);
		}
	}

	void Client::proccess()
	{
		std::cout << "packet from  " << inet_ntoa(info.sin_addr) << " : " << ntohs(info.sin_port);
		for (unsigned i = 0; i < reciveleng; i++)
		{
			std::cout << buffer[i];
		}
		std::cout << std::endl;
	}


	Client::~Client()
	{

		closesocket(clientsocket);
		WSACleanup();
	}

}
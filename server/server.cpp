#include "server.h"


#pragma warning(disable: 4996)

namespace Net
{
	Server::Server(int port, std::string ipaddress)
		:
		wsa{ 0 },
		port(port),
		ipaddress(ipaddress),
		serversocket(INVALID_SOCKET),
		info{0},
		infoLengh(sizeof(info)){}

		void Server::init()
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
		assert(!((serversocket = socket(AF_INET, SOCK_DGRAM, 0)) == SOCKET_ERROR) && "COULDN'T CREATE SOCKET");
		std::cout << "SOCKET success\n";

		std::cout << "SOCKET bind\n";
		assert(!(bind(serversocket, (struct sockaddr*) & info, infoLengh)) && "COULDN'T BIND SOCKET");
		std::cout << "SOCKET binded\n";

		std::cout << "server started " << inet_ntoa(info.sin_addr) << " : " << ntohs(info.sin_port);
	}

	void Server::start()
	{
		init();
		for (;;)
		{
			receive();
			proccess();
			send();
		}
	}
	void Server::receive()
	{

		if ((reciveleng = recvfrom(serversocket, buffer, SIZE, 0, (struct sockaddr*) & info, &infoLengh)) == SOCKET_ERROR) 
		{
			std::cout << " recv() failed...  " << reciveleng  << ":"<<WSAGetLastError();
			exit(EXIT_FAILURE);
		}
	}
	void Server::proccess()
	{
		std::cout << "packet from  " << inet_ntoa(info.sin_addr) << " : " << ntohs(info.sin_port);
		for (unsigned i = 0; i < reciveleng; i++)
		{
			std::cout << buffer[i];
		}
		std::cout << std::endl;
	}
	void Server::send()
	{
		if ((sendto(serversocket, buffer, reciveleng, 0, (struct sockaddr*)& info, infoLengh)) == SOCKET_ERROR)
		{
			std::cout << " send() failed...  " << WSAGetLastError();
			exit(EXIT_FAILURE);
		}
	}
	void Server::stop()
	{
	
	
	}

	Server::~Server()
	{
		
		closesocket(serversocket);
		WSACleanup();
	}

}
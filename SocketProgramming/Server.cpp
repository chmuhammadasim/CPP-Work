#include <iostream>
#include <winsock.h>
using namespace std;
#define PORT 9090
struct sockaddr_in srv;

int main()
{
	WSADATA ws;  
	int nStatus = WSAStartup(MAKEWORD(2, 2), &ws);
	if (nStatus < 0)
	{
		cout << endl << "WSAStartup failed";
		exit(EXIT_FAILURE);
	}
	int nListener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (nListener < 0)
	{
		cout << endl << "socket API failed to open listener";
		exit(EXIT_FAILURE);
	}
	srv.sin_family = AF_INET;
	srv.sin_port = htons(PORT);
	srv.sin_addr.s_addr = INADDR_ANY;
	memset(&srv.sin_zero, 0, sizeof(srv.sin_zero));

	nStatus = bind(nListener, (struct sockaddr*)&srv, sizeof(srv));
	if (nStatus < 0)
	{
		cout << endl << "bind failed";
		exit(EXIT_FAILURE);
	}
	nStatus = listen(nListener, 5);
	if (nStatus < 0)
	{
		cout << endl << "listen failed";
		exit(EXIT_FAILURE);
	}
	int nLen = sizeof(srv);
	int nClientSocket = accept(nListener, NULL, &nLen);
	if (nClientSocket < 0)
	{
		cout << endl << "Client socket not connected";
		exit(EXIT_FAILURE);
	}
	else
	{
		char sBuff[1024] = { 0, };
		while (1)
		{
			nStatus = recv(nClientSocket, sBuff, 1024, 0);
			if (nStatus > 0)
			{
				cout << endl << sBuff;
			}
		}
	}
	return 0;
}

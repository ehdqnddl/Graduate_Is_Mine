#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>

void ErrorHandling(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

void main() {

	WSADATA wsadata;
	SOCKET server_socket, client_socket;

	struct sockaddr_in server_address;
	struct sockaddr_in client_address;
	int client_address_size;
	int n = -1;
	char order[4] = { 0 }, filename[15] = { 0 }, packet[5] = { 0 };
	char bbbbbb[5] = { 1 };
	FILE *fp;

	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
		ErrorHandling("WSAStartup()");

	server_socket = socket(PF_INET, SOCK_STREAM, 0);
	if (server_socket == -1)
		ErrorHandling("socket()");

	memset(&server_address, 0, sizeof(server_address));
	server_address.sin_family = AF_INET;//IPv4사용
	server_address.sin_addr.s_addr = htonl(INADDR_ANY);//자동할당
	server_address.sin_port = htons(atoi("9190"));

	if (bind(server_socket, (SOCKADDR*)&server_address, sizeof(server_address)) == SOCKET_ERROR)
		ErrorHandling("bind()");

	if (listen(server_socket, 5) == SOCKET_ERROR)
		ErrorHandling("listen()");

	client_address_size = sizeof(client_address);
	client_socket = accept(server_socket, (SOCKADDR*)&client_address, &client_address_size);
	if (client_socket == INVALID_SOCKET)
		ErrorHandling("accept()");
	
	/*실행 내용*/
	recv(client_socket, order, 4, 0);
	printf("%s",order);
	if (strcmp(order, "put") == 0) {
		recv(client_socket, filename, 15, 0);
		printf("%s", filename);
		fp = fopen(filename, "w");
	//	n = recv(client_socket, packet, 3, 0);
	//	packet[3] = '\0';
	//	fprintf(fp, "%s", packet);
	//	fprintf(fp, "\n");
		while (1) {

			n = recv(client_socket, packet, 3, 0);
			if (!strcmp(bbbbbb, packet))
				break;
			strcpy(bbbbbb, packet);


			packet[3] = '\0';
			fprintf(fp, "%s", packet);
			fprintf(fp, "\n");
		}
		fclose(fp);
	}
	closesocket(client_socket);
	closesocket(server_socket);
}
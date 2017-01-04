#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>

#define MAX_BUF 1024

void ErrorHandling(char *message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

void main(int argc, char *argv[]) {

	WSADATA wsadata;
	SOCKET sock;
	struct sockaddr_in server_address;
	int str_len;
	int n = 0;
	FILE *fp;
	char packet[4] = { 0 };
	char filename[23] = { 0 };

	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
		ErrorHandling("WSAStartup()");

	sock = socket(PF_INET, SOCK_STREAM, 0);
	if (sock == -1)
		ErrorHandling("socket()");

	memset(&server_address, 0, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_address.sin_port = htons(atoi("9190"));

	if (connect(sock, (SOCKADDR*)&server_address, sizeof(server_address)) == SOCKET_ERROR)
		ErrorHandling("connect()");
	
	/*실행할 함수*/
	strcpy(filename,argv[1]);
	strcat(filename, "_sub.txt");
	printf("%s", filename);

	send(sock, "put", 4, 0);
	send(sock, filename, 14, 0);
	fp = fopen(filename, "r");
	//printf("safe");

	while ( 1 ) {
		fscanf(fp, "%s", packet);
		n = send(sock, packet, 3, 0);
		if (feof(fp))
			break;
	}
	fclose(fp);

	closesocket(sock);
	WSACleanup();
}
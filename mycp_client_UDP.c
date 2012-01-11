#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/select.h>

#define SERVER_PORT		20001
#define BUFFER_SIZE	    1024	

char buffer[BUFFER_SIZE];
int i;

int main(int argc, char *argv[])
{
	int i,n,len;
	int client_sock;
	socklen_t server_len;
	struct sockaddr_in server;
    int fd;
	fd_set input_fd;
    int count = 0;
    char filename[256];

	//if(argc != 3)
	//{
		//printf("\nSorry, your type is wrong.\n");
		//printf("Usage: %s x.x.x.x(server IP) filename\n\n", argv[0]);
		//exit(EXIT_FAILURE);
	//}

	if ((client_sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
	{
		fprintf(stderr, "%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("create socket ok!\n");
	}

	bzero(&server, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);
	server.sin_addr.s_addr = inet_addr(argv[1]);

    server_len = sizeof(server);
    n = sendto(client_sock, argv[2], BUFFER_SIZE, 0, (struct sockaddr *)&server, server_len);
    //if((len = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0)
    //{
        //server_len = sizeof(server);
        //n = sendto(client_sock, buffer, len, 0, (struct sockaddr *)&server, server_len);
    //}
    
    //fd = open(argv[2], O_RDWR | O_CREAT, 00776);
    sprintf(filename, "%s.copy",argv[2]);
    fd = open(filename, O_RDWR | O_CREAT, 00776);
    if (fd < 0) 
    {
        perror("open");
        exit(1);
    }
	
    while (1)
	{
        FD_ZERO(&input_fd);
		FD_SET(client_sock, &input_fd);
        //FD_SET(fd, &input_fd);

        //if((select(fd+1, &input_fd, NULL, NULL, NULL)) < 0)
        if((select(client_sock+1, &input_fd, NULL, NULL, NULL)) < 0)
		{
			fprintf(stderr, "%s\n", strerror(errno));
			continue;
		}

        if(FD_ISSET(client_sock, &input_fd))
        {
            n = recvfrom(client_sock, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&server, &server_len);
            if (n < 0) 
            {
                close(client_sock);
                fprintf(stderr, "%s\n", strerror(errno));
                exit(EXIT_FAILURE);
            }
            write(fd, buffer, n);
            //count++;
        }

        //if ((n < BUFFER_SIZE) || (count = 1)) 
        if (n < BUFFER_SIZE) 
        {
            break;
        }
	}

    close(fd);
	close(client_sock);
    printf("%s copy succeed\n",argv[2]);
	exit(EXIT_SUCCESS);
}


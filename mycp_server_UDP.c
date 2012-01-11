#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SERVER_PORT     20001  
#define BUFFER_SIZE     1024 

char buffer[BUFFER_SIZE]; 
char filename[256]; 
int i;

int main(int argc, const char *argv[])
{
    int len;
    int server_sock;
    socklen_t client_len;  
    struct sockaddr_in server, client;
    struct in_addr in;
    int fd;
    struct stat buf;
    
    if ((server_sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) 
    {
        fprintf(stderr, "%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("create socket ok !\n");
    }

    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);
    server.sin_addr.s_addr = htons(INADDR_ANY);

    if (bind(server_sock, (struct sockaddr *)&server, sizeof(server)) < 0) 
    {
        fprintf(stderr, "%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("bind addr ok !\n\n");
    }

    // start to receive data
    client_len = sizeof(client);
    len = recvfrom(server_sock, filename, BUFFER_SIZE, 0, (struct sockaddr *)&client, &client_len);
    if (len < 0) 
    {
        close(server_sock);
        fprintf(stderr, "%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("recvfrom client ok !\n");
        in.s_addr = client.sin_addr.s_addr;  
        printf("client ip : %s\n",inet_ntoa(in));
        printf("client port : %d\n\n",ntohs(client.sin_port));
        fd = open(filename, O_RDONLY);
        if (fd < 0) 
        {
            perror("open");
            exit(1);
        }
        printf("Copying file %s ...\n",filename);
    }

    stat(filename, &buf);
    //while ((len = read(fd1, buffer, buf.st_size)) > 0)
    //len = read(fd, buffer, BUFFER_SIZE);
    //client_len = sizeof(client);
    //sendto(server_sock, buffer, len, 0, (struct sockaddr *)&client ,client_len);
    //write(fd2, buffer, buf.st_size);

    while ((len = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        client_len = sizeof(client);
        sendto(server_sock, buffer, len, 0, (struct sockaddr *)&client ,client_len);
    }

    sleep(1);
    printf("%s copy finished\n",filename);
    close(fd);
    close(server_sock);
    exit(EXIT_SUCCESS);

    return 0;
}


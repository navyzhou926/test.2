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
#include <sys/stat.h>
#include <dirent.h>

#define SERVER_PORT	    8000	
#define BUFFER_SIZE	    1024	

FILE *fd_before = NULL;
int flag = 0;

FILE * received_file(const char *buffer, int len, char *filename)
{
    int iret = 0;
    static FILE *fd = NULL;
    char path[4096] = {'\0'};

    if (buffer[1] == '1') 
    {
        //if (fd != NULL) 
        //fclose(fd);
        strcpy(path, filename);
        iret = access(path, W_OK);
        if(iret != 0)
        {
            iret = mkdir(path, 0777);
            if(iret != 0)
            {
                printf("can not create dir");
                exit(1);
            }
        }
        strcat(path, "/");
        strcat(path, (buffer + 4));
        fd = fopen(path, "w+");
        if(fd == NULL)
        {
            printf("can not open file");
            exit(1);
        }
        if (flag == 0) 
        {
            flag = 1;
            fd_before = fd;
        }
        if (fd_before != fd) 
        {
            fclose(fd_before);
            fd_before = fd;
        }
        printf("\n%s\n",(buffer + 4));
    }
    if (buffer[1] == '0') 
    {
        printf("Received byte = %d\n",len);
        len = fwrite(buffer + 4, 1, len-4, fd);
        //printf("write byte = %d\n",len);
        printf("write byte = %d\n",len + 4);
    }

    return fd;
}

int main(int argc, char *argv[])
{
    int len = 0;
    char buffer[4096];
    int server_sock;
    socklen_t client_len;  
    struct sockaddr_in server, client;
    struct in_addr in;

	int server_sock_tcp,client_sock_tcp; 
	struct sockaddr_in server_tcp,client_tcp;
    char *filename[256] = {"PictureFile", "MediaFile", "TextFile", "OtherFile"};

start:
    if ((server_sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) 
    {
        fprintf(stderr, "%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("UDP create socket ok !\n");
    }

	bzero(&server, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);
    //server.sin_addr.s_addr = inet_addr("255.255.255.255");
    server.sin_addr.s_addr = htons(INADDR_ANY);

    #if 1
    if (bind(server_sock, (struct sockaddr *)&server, sizeof(server)) < 0) 
    {
        fprintf(stderr, "%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("UDP bind addr ok !\n\n");
    }
    #endif

    client_len = sizeof(client);
again:
    len = recvfrom(server_sock, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client, &client_len);
    printf("%s\n", buffer);
    if (len < 0) 
    {
        close(server_sock);
        fprintf(stderr, "%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    if (strcmp(buffer, "ready1") != 0) 
    {
        //printf("receive data\n");
        goto again;
    }

//TCP
    #if 1
	if ((server_sock_tcp = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		fprintf(stderr, "%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("TCP create socket ok!\n");
	}
    int on = 1;
    setsockopt(server_sock_tcp, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
	bzero(&server_tcp, sizeof(server_tcp));
	server_tcp.sin_family = AF_INET;
	server_tcp.sin_port = htons(SERVER_PORT);
    server_tcp.sin_addr.s_addr = htons(INADDR_ANY);
	if(bind(server_sock_tcp, (struct sockaddr *)&server_tcp, sizeof(server_tcp)) < 0)
	{
		fprintf(stderr, "%s\n", strerror(errno));
        exit(EXIT_FAILURE);
	}
	else
	{
        printf("TCP bind addr ok!\n");
	}
	if(listen(server_sock_tcp, 5) < 0)
	{
		fprintf(stderr, "%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	else
	{
        printf("TCP listen ok!\n");
	}
    #endif

    //delete files and ready to sync
    DIR *dir;
    struct dirent *ptr;
    int i = 0;
    int iret = 0;

    for (i = 0; i < 4; i++) 
    {
        sprintf(buffer, "../%s", *(filename + i));
        if ((dir = opendir(buffer)) != NULL) 
        {
            while ((ptr = readdir(dir)) != NULL)
            {
                if (ptr->d_type == DT_REG) 
                {
                    sprintf(buffer, "../%s/%s",*(filename + i), ptr->d_name);
                    if ((iret = remove(buffer)) < 0)
                    {
                        printf("fail to delete %s \n",ptr->d_name);
                    }
                    printf("delete one file\n");
                }
            }
        }
    }
//UDP
    printf("UDP Connect client successfully !\n");
    client_len = sizeof(client);
    sendto(server_sock, "ready to sync", BUFFER_SIZE, 0,(struct sockaddr *)&client ,client_len);

//TCP
    #if 1
    client_len = sizeof(client_tcp);
    if((client_sock_tcp = accept(server_sock_tcp, (struct sockaddr *)&client_tcp, &client_len)) < 0)
    {
        close(server_sock_tcp);
        fprintf(stderr, "%s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("accept client ok!\n");
        in.s_addr = client_tcp.sin_addr.s_addr;
        printf("client ip  : %s\n", inet_ntoa(in));
        printf("client port: %d\n", ntohs(client_tcp.sin_port));
    }

    FILE *fd = NULL;
    memset(buffer, 0, sizeof(buffer));
    while ((recv(client_sock_tcp, buffer, BUFFER_SIZE, 0)) > 0)
    {
        len = ((buffer[2] << 8)&0xff00) + buffer[3];
        //printf("%s\n",buffer + 4);
        #if 1
        switch(buffer[0])
        {
            case '0':
                fd = received_file(buffer, len, "./PictureFile");
                break;
            case '1':
                fd = received_file(buffer, len, "./MediaFile");
                break;
            case '2':
                fd = received_file(buffer, len, "./TextFile");
                break;
            case '3':
                fd = received_file(buffer, len, "./OtherFile");
                #if 0
                if (buffer[1] == '1') 
                {
                    //if (fd != NULL) 
                    //fclose(fd);
                    strcpy(path, "./upload-folder/OtherFile");
                    iret = access(path, W_OK);
                    if(iret != 0)
                    {
                        iret = mkdir(path, 0777);
                        if(iret != 0)
                        {
                            printf("can not create dir");
                            exit(1);
                        }
                    }
                    strcat(path, "/");
                    strcat(path, (buffer + 4));
                    fd = fopen(path, "w+");
                    if(fd == NULL)
                    {
                        printf("can not open file");
                        exit(1);
                    }
                    printf("%s",(buffer + 4));
                }
                if (buffer[1] == '0') 
                {
                    len = fwrite(buffer + 4, 1, len-4, fd);
                    printf("write len = %d\n",len);
                }
                #endif
                break;
            default : break;
        }
        #endif
    }
    if (fd != NULL) 
    {
        fclose(fd);
    }
    flag = 0;
    fd_before = NULL;
	close(server_sock_tcp);
    #endif
    close(server_sock);
    goto start;
	exit(EXIT_SUCCESS);
}


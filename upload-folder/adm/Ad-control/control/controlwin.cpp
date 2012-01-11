#include "controlwin.h"
#include <QApplication>
#include <QPushButton>
#include <QDebug>
#include <QProcess>
#include <QByteArray>
#include <QHostAddress>
#include <sys/types.h>
#include <sys/wait.h>

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <dirent.h>

#include <QLabel>

#define SERVER_PORT	    21203
#define BUFFER_SIZE	    1024

FILE *fd_before = NULL;
FILE *fd_now = NULL;
int flag_fd = 0;

FILE * received_file(const char *buffer, int len, char *filename)
{
		int iret = 0;
		//static FILE *fd = NULL;
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
				fd_now = fopen(path, "w+");

				if(fd_now == NULL)
				{
						printf("can not open file");
						exit(1);
				}
				if (flag_fd == 0)
				{
						flag_fd = 1;
						fd_before = fd_now;
				}
				if (fd_before != fd_now)
				{
						fclose(fd_before);
						fd_before = fd_now;
				}
				printf("\n%s\n",(buffer + 4));
		}
		if (buffer[1] == '0')
		{
				len = fwrite(buffer + 4, 1, len-4, fd_now);
				printf("write byte = %d\n",len);
		}

		return fd_now;
}


ControlWin::ControlWin(QWidget *parent) :
		QWidget(parent)
{
		flag = 0;
		resize(200,100);

		this->disProcess = new QProcess(this);
		disProcess->start("/home/liu/at-ARM-show/Ad-control/Back/Back");

		QPushButton *quit = new QPushButton("Quit",this);
		quit->setGeometry(100,50,80,40);
		//connect(quit,SIGNAL(clicked()),qApp,SLOT(quit()));
		connect(quit,SIGNAL(clicked()),this,SLOT(slotSendMsg()));


		udpSocket = new QUdpSocket(this);
		// udpSocket->bind(QHostAddress::Any,8000);
		udpSocket->bind(8000);
		connect(udpSocket,SIGNAL(readyRead()),this,SLOT(slotready()));
}

//execut the Advertisement display function
void ControlWin::OnON()
{
		disProcess->close();
		disProcess->start("/home/liu/at-ARM-show/Ad-display/Advertisement");
		flag = 1;
}

void ControlWin::exe_a()
{   
		//this->disProcess_a = new QProcess(this);
		pid_t pid;
		//int val;
		pid = fork();
		if(pid < 0)
				exit(1);
		if(pid == 0)
		{
				execl("/home/liu/at-ARM-show/Ad-control/a.out","a.out",NULL);
				exit(1);
		}
		else
		{
				//udpSocket->close();
				//waitpid(pid, &val, 0);
				//udpSocket->open(8000);
		}


		qDebug() << "a.out has execut yet!";
}

//clos advertisement display function
void ControlWin::OnOFF()
{
		this->disProcess->close();
		disProcess->start("/home/liu/at-ARM-show/Ad-control/Back/Back");
		flag = 0;
}

QHostAddress addr;
quint16 port;
void ControlWin::slotSendMsg()
{
		char info[] = "ready to sync";
		udpSocket->writeDatagram(info,strlen(info)+1,addr,port);
		qDebug() << "send info to server!";
}

//receive msg from server : (hello,I'm one of client!)
void ControlWin::slotready()
{
		char buf[1024];
		udpSocket->readDatagram(buf, 1024, &addr, &port);
		qDebug() << "PORT >>>>>" <<port;
		QString ba(buf);
		if((strstr(buf,"startall") || strstr(buf,"start1")) && flag == 0)   //if receive "ON" from server -> execut Ad display function
		{
				OnON();
		}
		else if((strstr(buf,"stopall") || strstr(buf,"stop1")) && flag == 1) //if receive "OFF" from server -> close Ad display function
		{
				OnOFF();
		}
                else if(strstr(buf,"ready1") || strstr(buf,"readyall"))
		{
				//exe_a(); // tcp server
				disProcess->close();
				disProcess->start("/home/liu/at-ARM-show/Ad-control/SyncBack/SyncBack");

				// slotSendMsg(); // tong zhi duifang lianjie

				int len = 0;
				char buffer[1024];
				int server_sock;
				socklen_t client_len;
				struct sockaddr_in server, client;
				struct in_addr in;

				int server_sock_tcp,client_sock_tcp;
				struct sockaddr_in server_tcp,client_tcp;
				char *filename[256] = {"PictureFile", "MediaFile", "TextFile", "OtherFile"};
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

				slotSendMsg();

				client_len = sizeof(client_tcp);
				if((client_sock_tcp = accept(server_sock_tcp, (struct sockaddr *)&client_tcp, &client_len)) < 0)
				{
						//close(server_sock_tcp);
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
				fd_now = NULL;
				flag_fd = 0;

				int length = 0;

				memset(buffer, 0, sizeof(buffer));
				while ((length = recv(client_sock_tcp, buffer, BUFFER_SIZE, 0)) > 0)
				{
						while (length != BUFFER_SIZE)
						{
								length += recv(client_sock_tcp, buffer + length, BUFFER_SIZE-length, 0);
						}
						len = ((buffer[2] << 8)&0xff00) + buffer[3];
						//printf("len = %d",len);
						//printf("length = %d",length);
						//printf("%s\n",buffer + 4);
						switch(buffer[0])
						{
								case '0':
										received_file(buffer, len, "../PictureFile");
										break;
								case '1':
										received_file(buffer, len, "../MediaFile");
										break;
								case '2':
										received_file(buffer, len, "../TextFile");
										break;
								case '3':
										received_file(buffer, len, "../OtherFile");
										break;
								default : break;
						}
				}
				if (fd_now != NULL)
				{
						fclose(fd_now);
				}
				::close(server_sock_tcp);



				qDebug() << "get ready1";
				disProcess->close();
                                disProcess->start("/home/liu/at-ARM-show/Ad-control/Timer/Timer");
                                sleep(4);
                                disProcess->close();
                                disProcess->start("/home/liu/at-ARM-show/Ad-display/Advertisement");
                                flag = 1;
		}
		else
				qDebug() << "nether ON no OFF and is :" << ba;

		//slotSendMsg();
}

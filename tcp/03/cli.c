/*************************************************************************
	> File Name: cli.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月18日 星期六 10时07分54秒
 ************************************************************************/

#include<stdio.h>
#include<>
#include<>

void process_handler(int sockConn);
void main(int argc, char *argv[])
{
    int sockSer = star_up(argv[1],ati(argv[2]),TCP);
    printf("server wait client connect------------------");

    calcst oper;
    struct sockaddr_in addrCli;
    socklen_t len = sizeof(struct sockaddr);
    int sockConn;
    while(1)
    {
        sockConn = accept(sockSer,(struct sockaddr*)&addrCLi, &len);
        if(sockConn == -1)
        {
            perror("accept client connect fail.");
            continue;
        }
        else
        {
            printf("<===========client===========>\n");
            printf("<you can use these mode_type!>\n");
            printf("<   ADD   MUL     DIV     SUB>\n");
            printf("< ip = %s\n",iet_ntoa(addrCli.sin_addr));
            printf("<port = %d\n",ntohs(addrCli,sin_port));
            printf("<=============================>\n");
        }
        pid_t pid = fork();
        if(pid == 0)
        {
            process_handler(sockConn);
        }
        else if(pid > :0)
    }

}

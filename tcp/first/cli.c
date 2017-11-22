/*************************************************************************
	> File Name: cli.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月15日 星期三 18时52分39秒
 ************************************************************************/

#include"../utili.h"

int main()
{
    int SockCli = socket(AF_INET,SOCK_STREAM, 0);
    if(SockCli == -1)
    {
        perror("socket.");
        return -1;
    }
    struct sockaddr_in addrSer;
    addrser.sin_family = AF_INET;
    addrSer.sin_port = htons(SERVER_PORT);
    addrSer.sin_addr.s_addr = inet_addr(SERVER_IP);

    struct sockaddr_in addrCli;
    addrCli.sin_family = AF_INET;
    addrCli.sin_addr.s_addr = inet_addr("192.168.0.9");
    socklen_t len = sizeof(struct sockaddr);
    int ret = bind(sockCli,(struct sockaddr*)&addrCli, len);
    if(ret == -1)
    {
        perror("bind.");
        return -1;
    }
    ret = connect(sockCli,(struct sockaddr*)&addrSer,len);
    if(ret == -1)
    {
        printf("client connect server error.\n");
        return -1;
    }
    else 
    printf("client connect server success.\n");

    char sendbuf[BUFFER_SIZE];
    char recvbuf[BUFFER_SIZE];

    while(1)
    {
        recv(sockCli,recvbuf,BUFFER_SIZE,0);
        printf("ser:>%s\n",recvbuf);
        printf("cli:>");
        scanf("%s",sendbuf);
        if(!strcmp(sendbuf,"quit"))
        break;
        send(sockCli,sendbuf,strlen(sendbuf)+1,0);

    }
    close(sockCli);
    return 0;
}


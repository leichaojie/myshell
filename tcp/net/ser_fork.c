/*************************************************************************
	> File Name: ser_fork.c
	> Author: 
	> Mail: 
	> Created Time: 2017年11月18日 星期六 11时28分09秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(int argc, char *argv[])
{
    unsigned short port = 8080;
    //chuangjian tcp
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd < 0)
    {
        perror("socket fail!");
        exit(-1);
    }
    // pei zhi
    struct sockaddr_in my_addr;
    bzero(&my_addr,sizeof(my_addr));
    my_addr.sin_family = AF_INET; //IPV4
    my_addr.sin_port   =htons(port);
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    int err_log = bind(sockfd,(struct sockaddr*)&my_addr,sizeof(my_addr));
    if(err_log != 0)
    {
        perror("binding ");
        close(sockfd);
        exit(-1);
    }
    err_log = listen(sockfd,10);
    if(err_log != 0)
    {
        perror("listen");
        close(sockfd);
        exit(-1);
    }

    while(1)
    {
        char cli_ip[INET_ADDRSTRLEN]= {0};
        struct sockaddr_in client_addr;
        socklen_t cliaddr_len =sizeof(client_addr);

        //qu chu kehuduan lianjie
        int connfd = accept(sockfd,(struct sockaddr*)&client_addr,&cliaddr_len);
        if(connfd < 0)
        {
            perror("accept fail");
            close(sockfd);
            exit(-1);
        }

        pid_t pid = fork();
        if(pid < 0)
        {
            perror("fork fail!");
            exit(-1);
        }
        else if(pid == 0)
        {
            close(sockfd);

            char recv_buf[1024]= {0};
            int recv_len = 0;

            memset(cli_ip, 0, sizeof(cli_ip));
            inet_ntop(AF_INET,&client_addr.sin_addr,cli_ip,INET_ADDRSTRLEN);
            printf("-------------------------------------------\n");
            printf("client ip=%s, port=%d\n",cli_ip,ntohs(client_addr.sin_port));

            // jieshou shuju
            while((recv_len = recv(connfd,recv_buf,sizeof(recv_buf),0))>0)
            {
                printf("recv_buf:%s\n",recv_buf);
                send(connfd,recv_buf,recv_len,0);
            }
            printf("client closed!\n");
            close(connfd);
            exit(0);
        }
        else if(pid>0)
        {
            close(connfd);
        }
    }
close(sockfd);
return 0;
}

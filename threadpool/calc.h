/*************************************************************************
	> File Name: calc.h
	> Author: 
	> Mail: 
	> Created Time: 2017年11月18日 星期六 17时23分40秒
 ************************************************************************/

#ifndef _CALC_H
#define _CALC_H
#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define CMD_SIZE 5
typedef enum{QUIT,ADD, SUB, MUL ,DIV, MOD}ENUM_CALC_TYPE;
typedef struct calcst
{
    int op1;
    int op2;
    ENUM_CALC_TYPE op;
}calcst;
#endif

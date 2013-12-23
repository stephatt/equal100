//
//  main.c
//  equal100
//
//  Created by Tong Tingting on 13-12-20.
//  Copyright (c) 2013年 Tong Tingting. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static char sarr[9]={'1','2','3', '4', '5', '6', '7', '8', '9' };


int main()
{

    void cal(char str[]);
    char mix(char str[]);
    char itos(int i);
    void fo(char str[8],int n);
    char str[8]={0};
    fo(str,0);
    
}


char mix(char star[])  //数字和运算符交叉连接
{
    char mixx[17]={0};
    int i,lenth=0;
    for (i=0; i<9; i++) {
        if (sarr[i]!='\0') {
            mixx[lenth++]=sarr[i];
        }
        if (star[i]!='\0') {
            mixx[lenth++]=sarr[i];
        }
        
    }
    return mixx;
}

void cal(char str[])
{
    int sum=0,n=0;
    char *sb=str;
    char strr={'+'},nchar[]={0};
    for (; *sb!='\0'; sb++) {
        if (*sb>='1'&&*sb<='9') {
            n=n*10+*sb-'0';
            continue;
        }
        sprintf(nchar, "%d",n);
        strcat(&strr, nchar);
        n=0;
        if (*sb=='+'||*sb=='-') {
            strcat(&strr, sb);
        }
    }
    for (char *i=&strr; *i!='\0'; i++) {
        switch (*i) {
            case '+':
                sum+=*(++i);
                break;
            case '-':
                sum-=*(--i);
                break;
        }
    }
    if (sum==100) {
        printf("%hhd",strr);
    }
}

char itos(int i)
{
    switch (i) {
        case 0:
            return '+';
            break;
        case 1:
            return '-';
            break;
        case 2:
            return ' ';
            break;
    }
}


void fo(char str[8],int n)
{
    
    int i;
    for (i=0; i<=2; i++) {
        str[n]=itos(i);
        if (n==7) {
           cal(mix(str));
           if(i==2)
              break;
        }
        else{
           fo(str,n+1);
        }
    }
}



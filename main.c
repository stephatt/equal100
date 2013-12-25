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

//static char sarr[9]={'1','2','3','4','5','6','7','8','9'};

int main()
{

    void cal(char str[]);
    char mix(char *a,char *b);
    char itos(int i);
    void fo(char str[8],int n);
    char str[8];
    
    fo(str,0);
    
}


char mix(char *a,char *b)  //数字和运算符交叉连接
{
    char mixx[17]={0};
    int i,lenth=0;
    for (i=0; i<9; i++) {
        if (a[i]!='\0') {
            mixx[lenth++]=a[i];
        }
        if (b[i]!='\0') {
            mixx[lenth++]=b[i];
        }
        
    }
    return mixx;
}

void cal(char strm[])
{
    int sum=0,n=0,i=0;
    char strr={'+'},nchar[]={0};
    for (i=0; *(strm+i)!='\0'; i++) {
        if (*(strm+i)>='1'&&*(strm+i)<='9') {
            n=n*10+*(strm+i)-'0';
            continue;
        }
        else
            sprintf(nchar, "%d",n);  //将int型转化成字符串形式
        strcat(strr, nchar);
        n=0;
        if (*(strm+i)=='+'||*(strm+i)=='-') {
            strcat(strr, *(strm+i));
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
    
    int i,j,lenth=0;
    char sarr[9]={'1','2','3','4','5','6','7','8','9'},mixx[17]={0};
    for (i=0; i<=2; i++) {
        str[n]=itos(i);
        if (n==7) {
            for (j=0; j<9; j++) {
                if (sarr[j]!='\0') {
                    mixx[lenth++]=sarr[j];
                }
                if (str[j]!='\0') {
                    mixx[lenth++]=str[j];
                }
                
            }
            //s=mix(*sarr,*str);
            cal(mixx);
            if(i==2)
              break;
        }
        else{
           fo(str,n+1);
        }
    }
}



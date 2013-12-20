//
//  main.c
//  equal100
//
//  Created by Tong Tingting on 13-12-20.
//  Copyright (c) 2013年 Tong Tingting. All rights reserved.
//

#include <stdio.h>

static char sarr[9]={"1","2","3", "4", "5", "6", "7", "8", "9" };
char str[8];

int main()
{

    enum Symbol {
        NULL = 0,
        ADD = 1,
        MINUS = 2
    };
    enum Symbol i;
    void cal(char str);
    char mix(char str[]);
    char itos(int i);
    
    
}


char mix(char str[])  //数字和运算符交叉连接
{
    char sb[17];
    int i;
    for (i=0; i<9; i++) {
        sb[2*i]=sarr[i];
        sb[2*i+1]=str[i];
    }
    return sb;
}

void cal(char str)
{
    int sum=0;
    char *sb=str;
    for (; *sb!='\0'; sb++) {
        if (*sb=='+') {
            sum+=*(++sb);
        }
        if (*sb=='-') {
            sum-=*(++sb);
        }
        //if (*sb==NULL) {
            //sum
        //}
    }
}

char itos(int i)
{
    switch (i) {
        case 0:
            return " ";
            break;
        case 1:
            return "+";
            break;
        case 2:
            return "-";
            break;
        default:
            return NULL;
            break;
    }
}


void fo(char str[8],int n)
{
    
    int i,total=0;
    for (i=0; i<=2; i++) {
     str[n]=itos(i);
     if (n==7) {
        cal(mix(str));
        total++;
        if(i==2)
            break;
    }
    else{
        fo(str,n+1);
    }
  }
}



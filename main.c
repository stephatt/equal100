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

char sarr[9]={'1','2','3','4','5','6','7','8','9'};
#define Line 8   	//行数
#define MAXC 2   	//每行最大字符数

void MatCombin(char (*)[MAXC+1],int ,char *);

char strout[Line];
char mixx[2*Line+1];


int main (){
    int i;
    char mat[Line][MAXC+1] ={"+- ","+- ","+- ","+- ","+- ","+- ","+- ","+- "};
    MatCombin(mat, Line, strout);
    void mix(char *a,char *b);
    void cal(char *strm);
    exit (0);
}

//递归地进行组合,对8个位置上的符号进行枚举
void MatCombin(char(*p)[MAXC+1],int n,char *q){
    int i;
    //这个p对应最后一行，考虑输出
    if (n==1) {
        for (i=0; i<=MAXC; i++) {
            if(!p[0][i]) return;
            *q = p[0][i]; //最后一个字符写入到strout
            puts(strout);
            mix(sarr, strout);
        }
        
    }
    //不是最后一行，继续细分
    else {
        for (i=0; i<=MAXC; i++) {
            if(!p[0][i]) return;
            *q = p[0][i]; //写入一个字符
            MatCombin(p+1,n-1,q+1);
        }
    }
    
    
    return ;
}



void mix(char *a,char *b)  //数字和运算符交叉连接
{

    int i,lenth=0;
    for (i=0; i<9; i++) {
        if (a[i]!='\0') {
            mixx[lenth++]=a[i];
            mixx[lenth++]=b[i];
        }
        if (lenth<17) {
            continue;
        }
        puts(mixx);
        
    }
    
    cal(mixx);
    return ;
}


void cal(char *strm)
{
    int sum=0,n=0,i,j=0;
    char strr[17]={0},nchar[9]={0};
    for (i=0; strm[i]!='\0'; i++) {
        if (strm[i]==' ') {
            continue;
        }
        else if (strm[i]>='1'&&strm[i]<='9') {
            n=n*10+strm[i]-'0';
            continue;
        }
        else if (strm[i]=='+'||strm[i]=='-') {
            sprintf(nchar,"%d",n);  //将int型转化成字符串形式
            strr[j++]=nchar;
            n=0;
            strr[j++]=strm[i];
        }
        
    }
    for (char *q=strr; *q!='\0'; q++) {
        if (*q=='+') {
            sum+=*(++q);
            break;
        }
        else if (*q=='-'){
            sum-=*(--q);
            break;
        }
        
    }
    if (sum==100) {
        printf("%s",strr);
    }
}









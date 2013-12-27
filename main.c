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
#define Line 8   	//数字中间的间隔数总共可以添加3种运算符
#define MAXC 3   	//总共可以添加3种运算符

void MatCombin(char (*)[3],int ,char *);

char strout[Line];  //9个数字之间运算符的排列组合
char mixx[2*Line+1];  //数字和运算符交叉结合后的字符串


int main (){
    int i;
    char mat[Line][MAXC] ={"+- ","+- ","+- ","+- ","+- ","+- ","+- ","+- "};  //每个间隔可以选取的运算符
    MatCombin(mat, Line, strout);
    void mix(char *a,char *b);
    void cal(char *strm);
    exit (0);
}

//递归地进行组合,对8个间隔位置上的运算符进行枚举
void MatCombin(char(*p)[MAXC],int n,char *q){
    int i;
    //这个p对应最后一行，考虑输出
    if (n==1) {
        for (i=0; i<MAXC; i++) {
            if(!p[0][i]) return;
            *q = p[0][i]; //最后一个字符写入到strout
            //puts(strout);
            mix(sarr, strout);
        }
        
    }
    //不是最后一行，继续细分
    else {
        for (i=0; i<MAXC; i++) {
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
        
        
    }
    //删去字符串中的空格符
    int m;
    m=strlen(mixx);
    for (int j=0; j<m; j++) {
        if (*(mixx+j)!=' ') {
            continue;
        }
        for (int k=j; k<m; k++) {
            *(mixx+k)=*(mixx+k+1);
        }
        j--;m--;
    }
        
    //puts(mixx);
    cal(mixx);
    return ;
}

//计算和
void cal(char *strm)
{
    int sum,n=0,i,j=0,p=0,num[9]={0};
    char nchar[8]={0};
    for (i=0; *(strm+i)!='\0'; i++) {
        if (*(strm+i)>='1'&&*(strm+i)<='9') {
            n=n*10+*(strm+i)-'0';
            continue;
        }//遇到数字则变为int型
        else if (*(strm+i)=='+'||*(strm+i)=='-') {
            num[j++]=n;
            nchar[p++]=*(strm+i);
            n=0;
        }//把int型数字存放在num中，运算符存在nchar中
        
        
    }
    num[j]=n;
    //计算和值
    sum=num[0];
    for (i=j=0; *(nchar+i)!='\0'; i++) {
        if (*(nchar+i)=='+') {
            sum=sum+num[++j];
        }
        else if (*(nchar+i)=='-'){
            sum=sum-num[++j];
            
        }
        
    }
    
    if (sum==100) {
        printf("%s",mixx);
        printf("\n");
    }
    
}







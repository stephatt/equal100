equal100
========

在1、2、3...9（保持这个顺序）之间可任意放+或者-或者不放，使其结果等于100，输出所有可能的放法。例如：1 + 2 + 3 – 4 + 5 + 6 + 78 + 9 = 100。
Write a program that outputs all possibilities to put + or - or nothing between the numbers 1,2,…,9 (in this order) such that the result is 100. For example 1 + 2 + 3 - 4 + 5 + 6 + 78 + 9 = 100.


/*共9个数字，数字之间有8个间隔，每个间隔可以选择插入3种运算符，分别为+，-和空格*/
//把8个间隔3种运算符看为8*3的字符串数组mat
main()
{
   //声明函数
   //定义数据类型,即8个间隔运算符排列组合的字符串组strout、数字与运算符交叉后的字符串组mixx
   //调用MatCombin函数
}

void MatCombin(char(*p)[MAXC],int n,char *q)
{
   //从第一种strout选择mat的第0个元素开始
   //递归调用MatCombin函数，直到确定每一种strout最后一个间隔的运算符
   //循环3次，保证每种运算符都被调用过
   
}


void mix(char *a,char *b)
{
   
   {if(字符串没有结束）
      mixx[lenth++]=a[i]
      mixx[lenth++]=b[i]
    }  //数字与运算符交叉连接
    if(mixx[i]=' ')
      mixx[i]=mixx[i+1] //删去空格
}

void cal(char *strm)
{
   //把字符串中的数字转化成int，存放在num数组中
   //把字符串中的运算符存放在nchar中
   //遍历nchar，第i位上遇+或-，则加上或减去num[i+1]
}
   
   

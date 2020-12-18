//#include "stdafx.h"
#include <iostream>
using namespace std;
 void swap(int &a,int &b)//交换连个元素
 {
     int tem;
     tem = a;
     a = b;
     b = tem;
 }
 void cal(int *a,int first,int length)
 {
     if(first == length)//如果递归到深层时，到最后交换的元素即时最后一个元素时就打印出来
     {
         for(int i = 0; i <= length; i++)
         cout<<a[i]<<" ";
         cout<<endl;
     }
     else
     {
         for(int i = first; i <= length; i++)
         {//循环遍历使得当前位置后边的每一个元素都和当前深度的第一个元素交换一次
             swap(a[first],a[i]);//使得与第一个元素交换
             cal(a,first+1,length);//深入递归，此时已确定前边的元素，处理后边子序列的全排列形式。
             swap(a[first],a[i]);//恢复交换之前的状态
         }
     }
 }
 int main()
 {
     int a[10] = {1,2,3,4,5,6,7,8,9,10};
     cal(a,0,9);
     return 0;
 }

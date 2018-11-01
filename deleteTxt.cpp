/* deleteTxt.cpp : 定义控制台应用程序的入口点。
delete .txt in specific folder
copyright©2017DandelionLau
*/

#include "stdafx.h"
#include<io.h>
#include<string>
#include<stdio.h>
#include<iostream>
#include <stdlib.h>
using namespace std;

int main()
{	
	int filecount = 1;
	char path1[200] = "G:\\speech material\\ACELP\\CBD_70%\\all\\*.txt";	//文件路径名
	char path2[200] = "G:\\speech material\\ACELP\\CBD_70%\\all\\";		//文件当前路径
	long handle;															//用于查找的句柄 
	struct _finddata_t fileinfo;											//文件信息的结构体 
	handle = _findfirst(path1, &fileinfo);									//第一次查找 
	if (-1 == handle) return -1;
	//printf("%s\n", fileinfo.name);										//打印出找到的文件的文件名 
	char *name = fileinfo.name;												//获取文件名
	//cout << name << endl;
	remove(strcat(path2, name));
	while (!_findnext(handle, &fileinfo))									//循环查找其他符合的文件，知道找不到其他的为止 
	{
		//printf("%s\n", fileinfo.name);
		char path3[200] = "G:\\speech material\\ACELP\\CBD_70%\\all\\";
		name = fileinfo.name;
		remove(strcat(path3, name));
		filecount++;
		
	}
	printf("总共删除%d个文件\n", filecount);
	_findclose(handle);														//关闭句柄 
	system("pause");	

    return 0;
}

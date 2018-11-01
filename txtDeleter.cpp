/* 
delete specific txt file in a given path
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
	char path1[200] = "G:\\data\\*.txt";		//file name
	char path2[200] = "G:\\data\\";			//file folder name
	long handle;					//handle for search
	struct _finddata_t fileinfo;			//struct for file information 
	handle = _findfirst(path1, &fileinfo);		//find the file head
	if (-1 == handle) return -1;
	//printf("%s\n", fileinfo.name);		//print the filename
	char *name = fileinfo.name;			//get the filename
	//cout << name << endl;
	remove(strcat(path2, name));
	while (!_findnext(handle, &fileinfo))		//delete all the file according to condition
	{
		//printf("%s\n", fileinfo.name);
		char path3[200] = "G:\\data\\";
		name = fileinfo.name;
		remove(strcat(path3, name));
		filecount++;
		
	}
	printf("The total of files is %d", filecount);
	_findclose(handle);				//close handle
	system("pause");	

    return 0;
}

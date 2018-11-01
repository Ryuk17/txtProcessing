// halfTxt.cpp : 定义控制台应用程序的入口点。
/*	divide txt into two parts and save in different fold
	copyright©2017DandelionLau 
*/

#include "stdafx.h"
#include<string>
#include<io.h>
#include "stdio.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
int main(){

	int rate,i;
	char inFilePath[200];
	char trainFilePath[200];
	char testFilePath[200];


	

	char* cFileName[5]={"1","2","3","4","5"};
	char* eFileName[5]={"a","b","c","d","e"};

	for(rate =1;rate<=10;rate++){
		for(i=0;i<5;i++){

				sprintf(inFilePath,"F:\\test_%d\\%s.txt",rate*10,eFileName[i]);
				printf("%s\n",inFilePath);//get input file  path
				sprintf(trainFilePath,"F:\\test_%d\\%s\\train.txt",rate*10,cFileName[i]);
				printf("%s\n",trainFilePath);//get train.txt path
				sprintf(testFilePath,"F:\\test_%d\\%s\\test.txt",rate*10,cFileName[i]);
				printf("%s\n",testFilePath);//get test.txt path

				fstream data;//source file 
				ofstream train;//target file1
				ofstream test;//target file2
				string buff;
				int mid = 0,count = 0,line = 0;//mid the:txt's lines, count :txt's total lines,line :counter

				data.open(inFilePath,ios::in);
				if (!data.is_open())
				 {
					  cout << "Can not find target file." << endl;
					  return 0;
				 }
				while(getline(data, buff)){count++;}//get total lines
				//cout<<"count ="<<count<<endl;
				mid = count/2;
				//cout<<"mid ="<<mid<<endl;
				data.close();
				
				data.open(inFilePath,ios::in);
				if (!data.is_open())
				 {
					  cout << "Can not find target file." << endl;
					  return 0;
				 }

				train.open(trainFilePath,ios::app);
				while(getline(data, buff)) { 
					
					if(line>mid){break;}
					train<<buff<<endl;//write first-half into train.txt
					line++;
				 }
				data.close();
			    train.close();

				data.open(inFilePath,ios::in);
				if (!data.is_open())
				 {
					  cout << "Can not find target file." << endl;
					  return 0;
				 }
				cout<<line<<endl;
				line = 0;
				test.open(testFilePath,ios::app);
			    while(getline(data, buff)) { 
					if(line>mid){	
					test<<buff<<endl;//write last-half into test.tx		
					}//end if
					line++;
				
				 }

			   data.close();
			   test.close();
			   system("pause");

			}//end for i
	}//end for rate													

	return 0;
}

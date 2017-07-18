// createTxt.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<io.h>
#include<iostream>
#include<string>
#include<fstream>
#include<stdio.h>
using namespace std;

int main()
{	
	char *filename[3] = {"data.txt","test.txt","out.txt"};
	for (int i = 0;i < 3;i++) {
		string path = "";
		fstream fn;
		string name = path.append(filename[i]);
		fn.open( name,ofstream::out);
		if (fn) cout << name << "\t\t"<<filename[i] << " has been created" << endl;
		fn.close();
	}
	
	return 0;
}


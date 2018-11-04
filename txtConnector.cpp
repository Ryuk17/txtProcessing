#include "stdafx.h"
#include "stdafx.h"
#include<string>
#include<io.h>
#include "stdio.h"
#include <string>
#include <iostream>
#include <fstream>

int main(){
  char outFilePath[200];
	char inFilePath1[200];
	char inFilePath2[200];
  cout<<"Starting connecting txt files"<<endl;
  for(int j=0;j<2;j++){
    sprintf(outFilePath,"C:\\desktop\\out.txt");
    sprintf(inFilePath1,"C:\\desktop\\in1.txt");
    sprintf(inFilePath2,"C:\\desktop\\in2.txt");
          
    fstream in1;//source file1
    fstream in2;//source file2
    ofstream out;//target file
    string buff;
          
    in1.open(inFilePath1,ios::in);
    if (!in1.is_open()){
      cout << "Can not find target file." << endl;
      return 0;
    }
    cout<<"in1 open successfully"<<endl;
    out.open(outFilePath,ios::app);
    while(getline(in1, buff)){
      out<<buff<<endl;
    }
    out.close();
    in1.close();

    in2.open(inFilePath2,ios::in);
    if (!in2.is_open()){
      cout << "Can not find target file." << endl;
      return 0;
    }
    cout<<"in2 open successfully"<<endl;
    out.open(outFilePath,ios::app);
    while(getline(in2, buff)){
      out<<buff<<endl;
    }
    
    out.close();
    in2.close();

  }//end for j
}

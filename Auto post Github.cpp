#include <stdio.h> 
#include <dirent.h>
#include <fstream>  
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int main(void) 
{ 
	struct dirent *de; // Pointer for directory entry 

	// opendir() returns a pointer of DIR type. 
	cout<<"Enter the File Address to be proccessed"<<endl;
	string filepath;
	cin>>filepath;
	char fpath[1000];
	int pth=0;
	for(auto it:filepath)fpath[pth++]=it;
		fpath[pth]='\0';
	// cout<<"The file path +"<<filepath<<endl;
	 // /Users/babayaga/Desktop/ada/sql
	DIR *dr = opendir(fpath); 

	if (dr == NULL) // opendir returns NULL if couldn't open directory 
	{ 
		printf("Could not open current directory" ); 
		return 0; 
	} 
	vector<string>vs;
	string one="<h1><p style=\"color:red\">SQL Codes Of Real life Examples</p></h1>";
	string two="<h1><a href=\"https://babayaga9823.github.io\">.</a> </h1><br>";
    string three="h1><a href=\"https://www.quora.com/profile/Khitish-Panigrahi\">..</a></h1> <br>";
	string a="<a href=\"https://github.com/babayaga9823/leetcode-solved-codes/blob/master/";
	string b="</a> ";
	while ((de = readdir(dr)) != NULL) 
	{
		
			// printf("%s\n", de->d_name); 
		string tmp=de->d_name,str;
		 // str=tmp;
		int ac=0;
		char star[1000]={0};
		for(int i=0;i<tmp.length();i++)
		{
			if(tmp[i]==' ')
			{
				star[ac++]='%';
				star[ac++]='2';
				star[ac++]='0';
			}
			else
			{
				star[ac++]=tmp[i];
			}

		}
		star[ac]='\0';
		str=star;
		 string finalstring="";
		if(tmp==".")finalstring=two;
		else if(tmp=="..")finalstring=three;
		else 
		{
			finalstring=a+str+"\">"+tmp+b+"<br>";

		}
		vs.push_back(finalstring);
	}
	closedir(dr);	 
	ofstream fout; 
	string readme=filepath+"/README.m";
	fout.open(readme); 
	fout<<one<<endl;
	for(auto it:vs)
	{
		fout << it <<endl<<endl<<endl;;
	}
	fout.close(); 
	
	return 0; 
} 

// <a href="https://www.instagram.com/khitish_panigrahi/">
// </a> 
#include<iostream>
#include<fstream>

using namespace std;

int main(){
	fstream frw("sample.txt", ios::in | ios::out | ios::app);
	frw<<"HELLO";
	string s;
	frw.seekg(0);
	frw>>s;
	cout<<s;
	frw.close();
	return 0;
}

#include<iostream>
#include<map>
using namespace std;

int main()
{
	map<int,string> m1;
	
	m1[10]="Parag";
	m1[30]="Yogesh";
	m1[20]="Mayur";
	m1[40]="Manish";
	
	map<int,string> m2{ {10,"Parag"}, {30,"Yogesh"}, {20,"Mayur"} };
	
	m1.insert(pair<int,string>(35,"Bhushan"));
	
	map<int,string>:: iterator i=m1.begin();
	
	while(i!=m1.end())
	{
		cout<<"Roll No.:"<<i->first<<" Name:"<<i->second<<endl;
		i++;	
	}
	
	cout<<"\nName of student with Roll No. 20: "<<m1[20];
	cout<<"\nName of student with Roll No. 30: "<<m1.at(30);
	cout<<"\nTotal number of students: "<<m1.size();
	
	m1.clear();
	
	if(m1.empty())
	{
		cout<<"\nAll entries of map are deleted.\n";
	}	
}
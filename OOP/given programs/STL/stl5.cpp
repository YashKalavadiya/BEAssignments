#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct student
	{
		int rollno;
		char name[20];
	};

bool compare(student a, student b)
{
	return a.rollno>b.rollno;
}

int main()
{
	student s1{10,"Parag"},s2{40,"Mayur"},s3{20,"Nilesh"},s4{30,"Bhushan"};
	
	vector<student> v{s1,s2,s3,s4};
	
	sort(v.begin(),v.end(),compare);
	
	vector<student>::iterator it=v.begin();
	
	cout<<"Sorted by Roll Numbers:"<<endl;
	
	while(it!=v.end())
	{
		cout<<"Roll No.:"<<(*it).rollno<<endl;
		cout<<"Name:"<<(*it).name<<endl;
		it++;
	}
}


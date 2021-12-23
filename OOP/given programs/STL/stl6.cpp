#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct student
	{
		int rollno;
		const char* name;
	};

int main()
{
	student s1{10,"Parag"},s2{40,"Mayur"},s3{20,"Nilesh"},s4{30,"Bhushan"};
	
	vector<student> v{s1,s2,s3,s4};
	
	vector<student>::iterator it=v.begin();
	
	while(it!=v.end())
	{
		if((*it).rollno==20)
			break;
		it++;
	}
	
	cout<<"Roll No.:"<<(*it).rollno<<endl;
	cout<<"Name:"<<(*it).name<<endl;
	it++;		
}


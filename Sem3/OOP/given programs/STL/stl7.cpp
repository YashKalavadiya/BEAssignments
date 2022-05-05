#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> v{10, 40, 20, 30};
	
	vector<int>::iterator it;
	
	it=find(v.begin(),v.end(),60);
	
	if(it!=v.end())
	{
		cout<<"Element found in vector"<<endl;	
	}
	else
	{
		cout<<"Element does not found in vector"<<endl;	
	}
		
}


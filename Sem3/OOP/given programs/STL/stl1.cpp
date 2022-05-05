#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v1;
	vector<char> v2(5);
	vector<char> v3(4,'a');
	vector<char> v4{'a','b','c','d'};
	
	cout<<"Size of Vector:"<<v1.size()<<endl;
	cout<<"Capacity of Vector:"<<v1.capacity()<<endl;
	
	v1.push_back(10);
	cout<<"Size of Vector:"<<v1.size()<<endl;
	cout<<"Capacity of Vector:"<<v1.capacity()<<endl;
		
	v1.push_back(20);
	cout<<"Size of Vector:"<<v1.size()<<endl;
	cout<<"Capacity of Vector:"<<v1.capacity()<<endl;
	
	v1.push_back(30);
	cout<<"Size of Vector:"<<v1.size()<<endl;
	cout<<"Capacity of Vector:"<<v1.capacity()<<endl;
	
	v1.pop_back();
	cout<<"Size of Vector:"<<v1.size()<<endl;
	cout<<"Capacity of Vector:"<<v1.capacity()<<endl;
	
	cout<<"First Element:"<<v1.front()<<endl;
	cout<<"Last Element:"<<v1.back()<<endl;
	
	cout<<"Element at index 0:"<<v1.at(0)<<endl;
	cout<<"Element at index 1:"<<v1.at(1)<<endl;
	
	cout<<"Element at index 0:"<<v1[0]<<endl;
	cout<<"Element at index 1:"<<v1[1]<<endl;
	
	vector<int>::iterator it=v1.begin();
	v1.insert(it+1,40);
	cout<<"Size of Vector:"<<v1.size()<<endl;
	cout<<"Capacity of Vector:"<<v1.capacity()<<endl;
	
	vector<int>::iterator it1=v1.begin();
	while(it1!=v1.end())
	{
		cout<<"Value of iterator:"<<*it1<<endl;
		it1++;
	}
		
}


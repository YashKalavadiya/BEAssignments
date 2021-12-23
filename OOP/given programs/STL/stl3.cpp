#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(int a, int b)  //comparator function
{
	return a>b;
}

int main()
{
	vector<int> v{10, 40, 20, 30};
	
	vector<int>::iterator it=v.begin();
	
	sort(v.begin(),v.end(),compare);
	
	while(it!=v.end())
	{
		cout<<"Value of iterator:"<<*it<<endl;
		it++;
	}
		
}


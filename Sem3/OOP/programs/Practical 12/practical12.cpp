#include<bits/stdc++.h>
using namespace std;
class mappractical
{
	public:
		void inputelements(map<string, int> &temp_map,int n)
		{
			string state;
			int population;
			for(int i=0;i<n;i++)
			{
				cout<<"Enter state:"<<endl;
				cin>>state;
				cout<<"Enter its population:"<<endl;
				cin>>population;
				temp_map.insert({state,population});
			}
			map<string,int>:: iterator i1=temp_map.begin();
			cout<<"Entered states and their population are as follows:\n";
			while(i1!=temp_map.end())
			{
				cout<<"State:\t"<<i1->first<<endl;
				cout<<"Population:\t"<<i1->second<<endl;
				i1++;
			}
		}
		
		void returnpopulation(std::map<string,int> &temp_map)
		{
			string findstate;
			cout<<"Enter state to get its population:"<<endl;
			cin>>findstate;
			if(temp_map.find(findstate)==temp_map.end())
			{
				cout<<findstate<<"  not found";
			}
			else
			{
				cout<<findstate<<" has a population of "<<temp_map.find(findstate)->second;
			}
			
		}
};//describes the end of the declaration of class,enum,struct
int main()
{
	map <string,int> m1;
	int population;
	string state;
	int n,flag=0;
	mappractical m;
	while(flag!=1)
	{
	cout<<"MENU:"<<endl;
	cout<<"1.Input States:"<<endl;
	cout<<"2.Find Population:"<<endl;
	int op;
	cout<<"Enter your choice:"<<endl;
	cin>>op;
	
		
		switch(op)
		{
			case 1:
				
				cout<<"Enter number of states you want to enter:";
				cin>>n;
				m.inputelements(m1,n);
				
				break;
				
			case 2:
				m.returnpopulation(m1);
				flag=1;
				break;
		}
	}
}

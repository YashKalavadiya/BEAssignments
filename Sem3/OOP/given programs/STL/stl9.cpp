#include<iostream>
#include<map>
using namespace std;

int main()
{
	map<string,string> m1;
	
	m1["Maharashtra"]="Mumbai";
	m1["Karnataka"]="Bangalore";
	m1["Telangana"]="Hyderabad";
	m1["Goa"]="Panaji";
	
	m1.insert(pair<string,string>("Kerala","Thiruvananthapuram"));
	
	map<string,string>:: iterator i=m1.begin();
	
	while(i!=m1.end())
	{
		cout<<"State:"<<i->first<<" Capital:"<<i->second<<endl;
		i++;	
	}
	
	cout<<"\nState with capital Karnataka: "<<m1["Karnataka"];
	cout<<"\nState with capital Telangana: "<<m1.at("Telangana");
	cout<<"\nTotal States in map: "<<m1.size();
	
	m1.clear();
	
	if(m1.empty())
	{
		cout<<"\nAll entries of map are deleted.\n";
	}	
}
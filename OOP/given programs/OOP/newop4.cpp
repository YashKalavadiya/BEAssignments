//using friend keyword in operator overloading
#include<iostream>
using namespace std;
class Num2;
class Num1
{
	int a=4;
	friend int operator>(Num1 x,Num2 y);  // protype of opertor overloadiing
};

class Num2
{
	int b=3;
	friend int operator>(Num1 x,Num2 y);
};

int operator>(Num1 x,Num2 y)  //defination of opetor overloading
{
	if(x.a>y.b)
		return 1;
	else
		return 0;
}

int main()
{
	Num1 n1;
	Num2 n2;
	
	if(n1>n2)   //overloading > symbol, n1 and n2 are object
	{
		cout<<"Num1 has higher value than Num2\n";
	}
	else
	{
		cout<<"Num1 has smaller or equal value than Num2\n";
	}
}
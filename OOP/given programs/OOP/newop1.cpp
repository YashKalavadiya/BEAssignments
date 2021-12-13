//function overloading
#include<iostream>
using namespace std;

class Calc
{

	public:
	int add(int x,int y) //x and y formal parameters
	{
		return x+y;
	}
	double add(double x,double y)
	{
		return x+y;
	}
};


int main()
{
	Calc c;
	int sumint=c.add(4,5); //actual parameters
	cout<<"Sum of Integers="<<sumint<<"\n";
	double sumdouble=c.add(4.3,5.0);
	cout<<"Sum of Doubles="<<sumdouble<<"\n";
}
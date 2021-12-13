//Overloading unary operator
#include<iostream>
using namespace std;

class Complex
{
	int real=0,img=0;
	
	public:
	
	Complex(int x,int y)
	{
		real=x;
		img=y;
	}
	
	void operator++()  // defination , return type
	{
		real++;
		img++;
		
	}
	
	void show()
	{
		cout<<real<<"+"<<img<<"i";
	}
};



int main()
{
	double a=3.4;
	++a;
	cout<<"a="<<a<<endl;
	
	Complex c1(2,3);
	++c1; //c1.operator++()  // c1 pass as implict
	//c1++;
	c1.show();
	
}
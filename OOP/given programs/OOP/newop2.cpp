//overloading + operator for Complex Numbers
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
	
	Complex operator+(Complex y) // overloading + operator 
	{
		Complex temp(0,0);  // temp is object of complex class
		temp.real=real+y.real;
		temp.img=img+y.img;
		return temp;
		
	}
	
	void show()
	{
		cout<<real<<"+"<<img<<"i";
	}
};



int main()
{
	int a=3,b=5;
	int c;
	c=a+b;
	cout<<"Sum="<<c<<endl;
	
	Complex c1(2,3),c2(3,4);
	Complex c3=c1+c2;    //c1 implicit parameter c2 explicit parameter
	//c1.operator+(c2)
	
	c3.show();
	
	// c1 ans c2 are object , adding two o
	
}
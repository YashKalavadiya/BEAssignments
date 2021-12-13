//overloading extraction >> and insertion << operator
//>>Extraction opwertor cin  istream class
//<<insertion opertor cout ostream class
#include <iostream>
using namespace std;

class Complex
{
private:
	int real, imag;
public:
	Complex(int r = 0, int i =0)
	{ 
	real = r; 
	imag = i; 
	}
	
	friend void operator >> (istream &in, Complex &c);
	friend void operator << (ostream &out, Complex &c);
};

void operator >> (istream &in, Complex &c)// defination of opertor overloading
{
	cout << "Enter Real Part ";
	in >> c.real;
	cout << "Enter Imaginary Part ";
	in >> c.imag;
	//return in;
}

void operator << (ostream &out, Complex &c)
{
	out << c.real;
	out << "+" << c.imag<<"i" << endl; 
	//return out;
}

int main()
{
	
Complex c1;
cin >> c1; // >> is extraction operator  C1 IS OBJ input
cout << "The complex object is ";
cout << c1; // << is insertion operator  for output.
return 0;

}










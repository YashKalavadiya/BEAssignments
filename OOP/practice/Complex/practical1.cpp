#include "iostream"

using namespace std;

class Complex {
public:
	float real, img;
	Complex() {
		this->real = 0;
		this->img = 0;
	}

	Complex(float real, float img) {
		this->real = real;
		this->img = img;
	}

	Complex operator+(Complex c) {
		Complex t;
		t.real = this->real + c.real;
		t.img = this->img + c.img;
		return t;
	}

	Complex operator*(Complex c) {
		Complex t;
		t.real = (this->real * c.real) - (this->img*c.img);
		t.img = (this->img * c.real) + (this->real * c.img);
		return t;
	}

	friend ostream &operator<<(ostream &out, Complex &c) {
		out<<"\n============\n";
		out<<c.real<<"+"<<c.img<<"i";
		out<<"\n===========\n";
		return out;
	}

	friend istream &operator>>(istream &in, Complex &c) {
		cout<<"\nEnter Real Part: ";
		in>>c.real;
		cout<<"\nEnter Imaginary part: ";
		in>>c.img;
		return in;
	}
};
int main() {
	Complex c1, c2;
	cin>>c1;
	cin>>c2;
	Complex c3;
	c3 = c1 + c2;
	cout<<c1<<endl;
	cout<<c2<<endl;
	cout<<c3<<endl;
	c3 = c1 * c2;
	cout<<c3<<endl;
}

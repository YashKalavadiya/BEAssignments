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
void printMenu() {
	cout<<"\nMENU";
	cout<<"\n1. Add complex";
	cout<<"\n2. Multiply Complex";
	cout<<"\n3. Display both Complex";
	cout<<"\n4. Exit";
}

void execute(){
	Complex c1, c2;
	Complex mul, add;
	cout<<"\nEnter Complex number 1:";
	cin>>c1;
	cout<<"\nEnter Complex number 2:";
	cin>>c2;
	bool isExit = false;
	while(!isExit){
		printMenu();
		cout<<"\nEnter your choice: ";
		int ch;
		cin>>ch;
		switch(ch){
			case 1:
				add = c1 + c2;
				cout<<"\nAddition: ";
				cout<<add;
				break;
			case 2:
				mul = c1*c2;
				cout<<"\nMultiplication: ";
				cout<<mul;
				break;
			case 3:
				cout<<"\nComplex no 1: ";
				cout<<c1;
				cout<<"\nComplex no 2: ";
				cout<<c2;
				break;
			case 4:
				isExit = true;
				break;
		}
	}
}
int main() {
	execute();
}

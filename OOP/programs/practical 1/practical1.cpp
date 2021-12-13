#include<iostream>
using namespace std;

class Complex{

    float x, y;
    public:
    Complex(){
        x = 0;
        y = 0;
    }

    friend istream &operator >>(istream &input, Complex &t){
        cout<<"Enter the real part: ";
        input>>t.x;
        cout<<"Enter imaginary part:";
        input>>t.y;
    }

    friend ostream &operator <<(ostream &output, Complex &t){
        output<<t.x<<"+"<<t.y<<"i\n";
    }
    Complex operator+(Complex c){
        Complex temp;
        temp.x = this->x + c.x;
        temp.y = this->y + c.y;
        return(temp);
    }
    Complex operator*(Complex c){
        Complex temp;
        temp.x = x * c.x;
        temp.y = y * c.y;
        return(temp);
    }
};

int main(){
    Complex c1,c2,c3,c4;
    cout<<"Enter first number:\n";
    cin>>c1;
    cout<<"Enter second number:\n";
    cin>>c2;

    c3 = c1 + c2;
    c4 = c1 * c2;

    cout<<"First Number is: \n";
    cout<<c1;
    cout<<"Second number is:\n";
    cout<<c2;

    cout<<"Addition is: \n";
    cout<<c3;

    cout<<"Multiplication is:\n";
    cout<<c4;

    return 0;
}
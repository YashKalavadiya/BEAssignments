#include "iostream"

using namespace std;


class Stack{
public:
	int top = -1;
	char *s;
	Stack(int n) {
		s = new char[n];
	}

	void push(char c){
		s[++top] = c;
	}

	bool check(char ele) {
		if(ele == ']' and s[top] == '['){
			return true;
		}
		else if(ele == ')' and s[top] == '('){
			return true;
		}
		else if(ele == '}' and s[top] == '}'){
			return true;
		}
		return false;
	}

	char pop() {
		return s[top--];
	}

	int getTop(){
		return top;
	}
	void printStack() {
		for(int i = 0; i < top; i++) {
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
};

class ParenthesisChecker {
	string expression;
public:
	void printMenu() {
		cout<<"\nMENU";
		cout<<"\n1. Check Expression";
		cout<<"\n2. Change Expression";
		cout<<"\n3. EXIT";
	}

	void checkExpression() {
		Stack s(expression.length());
		for(int i = 0; i < expression.length(); i++) {
			char c = expression[i];

			if(c == '[' || c == '(' || c == '{') {
				s.push(c);
			}
			else if(c == ']' || c == ')' || c == '}') {
				if(s.check(c)){
					s.pop();
				}
			}
//			s.printStack();
		}
		if(s.getTop() == -1){
			cout<<"\nExpression is well paranthesized";
		}
		else{
			cout<<"\nExpression is not well parenthized";
		}

	}
	void execute() {
		cout<<"\nEnter Expression: ";
		cin>>expression;
		bool isExit = false;

		while(!isExit) {
			printMenu();
			cout<<"\nEnter your choice: ";
			int ch;
			cin>>ch;
			switch(ch) {
			case 1:
				checkExpression();
				break;
			case 2:
				cout<<"\nEnter Expression: ";
				cin>>expression;
				break;
			case 3:
				isExit = true;
				break;
			}
		}
	}
};
int main() {

	ParenthesisChecker pc;
	pc.execute();

	return 0;
}

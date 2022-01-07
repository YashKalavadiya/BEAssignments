#include "iostream"
#include "vector"

using namespace std;


class Stack {
	char *s;
	int top = -1;

public:

	Stack(int len) {
		s = new char[len];
	}

	void push(char ele) {
		s[++top] = ele;
	}

	string conversionHelper(char ele) {
//		s[++top] = ele;
//		cout<<ele<<endl;
		string returnStr = "";
		if(ele == '-' || ele == '+') {
			if(top == -1) {
				s[++top] = ele;
//				cout<<returnStr<<"l23"<<endl;
				return returnStr;
			}
			if(s[top] == '*' || s[top] == '/') {
				returnStr += pop();
//				cout<<returnStr<<"l28"<<endl;
				return (returnStr + conversionHelper(ele));
			}
			else if(s[top] == '+' || s[top] == '-') {
				returnStr += pop();
//				cout<<returnStr<<"l33"<<endl;
				return (returnStr + conversionHelper(ele));
			}
			else{
				s[++top] = ele;
//				cout<<returnStr<<"l37"<<endl;
				return returnStr;
			}
		}
		else{
			if(top == -1) {
				s[++top] = ele;
//				cout<<returnStr<<"l44"<<endl;
				return returnStr;
			}
			if(s[top] == '/' || s[top] == '*') {
				returnStr += pop();
//				cout<<returnStr<<"l49"<<endl;
				return (returnStr + conversionHelper(ele));
			}
			s[++top] = ele;
//			cout<<returnStr<<"l52"<<endl;
			return returnStr;

		}
		return returnStr;
	}

	string popAllStack() {
		string retStr = "";
		while(top != -1) {
			retStr += s[top--];
		}
		return retStr;
	}

	char pop() {
		return s[top--];
	}
};

class ExpressionConv {
	string expression, postfix = "";

public:
	void printMenu() {
		cout<<"\nMENU";
		cout<<"\n1. Print Postfix Expression";
		cout<<"\n2. Evaluate given expression";
		cout<<"\n3. EXIT";
	}

	void convertExpression() {
		Stack s(expression.length());
//		cout<<expression;
		for(int i = 0; i < expression.length(); i++) {
			char current = expression[i];
			if(current == '+' || current == '-' || current == '*' || current == '/') {
				string str = s.conversionHelper(current);
				postfix += str;
//				cout<<"postfix: "<<postfix<<"and"<<str<<endl;
			}
			else{
				postfix += current;
			}
		}
		postfix += s.popAllStack();
		cout<<postfix<<endl;
	}

	int exec(char operation, int a, int b) {
		switch(operation){
		case '+':
			return a+b;
		case '-':
			return b-a;
		case '*':
			return a*b;
		case '/':
			return b/a;
		default:
			return 0;
		}
	}
	void evaluatePostfix() {
		Stack s(postfix.length());
		vector<int> evals;
		for(int i = 0; i < postfix.length(); i++) {
			char current = postfix[i];
			if(current == '+' || current =='-' || current == '/' || current == '*') {
//				int a = int(s.pop())-48;
//				int b = int(s.pop());
				int a = evals.back();
				evals.pop_back();
				int b = evals.back();
				evals.pop_back();

				cout<<a<<current<<b<<endl;

				int ans = exec(current, a, b);

//				s.push((ans+"")[0]);
				evals.push_back(int(ans));
			}else{
//				s.push(postfix[i]);
				evals.push_back(int(postfix[i])-48);
			}
		}
//		int ans = evals.pop_back();
		cout<<"\nExpression evaluated to: "<<evals.back();
	}
	void execute() {
		cout<<"\nEnter Expression: ";
		cin>>expression;
		bool isExit = false;
		while(!isExit) {
			printMenu();
			cout<<"\nEnter Choice: ";
			int ch;
			cin>>ch;
			switch(ch) {
			case 1:
				convertExpression();
				break;
			case 2:
				evaluatePostfix();
				break;
			case 3:
				isExit = true;
				break;
			}
		}
	}
};


int main() {
	ExpressionConv c;
	c.execute();

	return 0;
}

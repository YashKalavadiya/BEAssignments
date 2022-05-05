#include"iostream"

using namespace std;

class Publication {
public:
	string title;
	float price;
	void inputData() {
		cout<<"\nEnter Title of book: ";
		cin>>title;
		cout<<"\nEnter price: ";
		cin>>price;
	}
	void displayData() {
		cout<<"\nTitle: "<<title;
		cout<<"\nPrice: "<<price;
	}
};

class Book: public Publication {
public:
	int pageCount;

	void setPageCount() {
		retryPG:
		try{
		cout<<"\nEnter No of pages: ";
		cin>>pageCount;
		if(pageCount<0) {
			throw 0;
		}
		}
		catch(int err) {
			cout<<"\nPage Count must be more than 0";
			goto retryPG;
		}
	}

	void displayPageCount() {
		cout<<"\nTotal Pages: "<<pageCount;
	}
};

class Tape: public Publication {
public:
	float minutes;
	void setDuration() {
		retryDu:
		try{
		cout<<"\nEnter duration of audio book in minutes:";
		cin>>minutes;
		if(minutes<0){
			throw 0;
		}
		}
		catch(int err){
			cout<<"\nEnter valid duration!";
			goto retryDu;
		}
	}
	void displayDuration() {
		cout<<"\nDuration(in minutes):"<<minutes;
	}
};

void printMenu() {
	cout<<"\n1. Display all books";
	cout<<"\n2. Exit";
}
int main() {
	cout<<"\nEnter total no of records to enter: ";
	int n;
	cin>>n;
	Tape *t = new Tape[n];
	Book *b = new Book[n];
	for(int i = 0; i < n; i++) {
		t[i].inputData();
		t[i].setDuration();
		b[i].setPageCount();
	}

	bool isExit = false;
	int ch;

	while(!isExit) {
		printMenu();
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch) {
		case 1:
			for(int i = 0; i < n; i++) {
			t[i].displayData();
			t[i].displayDuration();
			b[i].displayPageCount();
			}
			break;
		case 2:
			isExit = true;
			break;
		}
	}
	return 0;
}

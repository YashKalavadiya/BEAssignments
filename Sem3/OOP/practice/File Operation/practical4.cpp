#include "iostream"
#include "fstream"
#include "climits"

using namespace std;

class FileOPeration {
public:
	ifstream r;
	ofstream w;

	void readData() {
		string data;
		r.open("data.txt");
		while(getline(r, data)) {
			cout<<data<<endl;
		}
		r.close();

	}

	void writeData() {
		w.open("data.txt", ios::app);
		string data;
		cout<<"\nEnter Data: ";
		cin.clear();
		cin.ignore(INT_MAX,'\n');
//		getline(cin, data);
		cin>>data;
		w<<endl;
		w<<data;
		w.close();
	}
};

void printMenu() {
	cout<<"\nMENU";
	cout<<"\n1.Write Data to file";
	cout<<"\n2. Read Data from file";
	cout<<"\n3. Exit";
}

int main() {

	FileOPeration fo;
	bool isExit = false;
	while(!isExit) {
		printMenu();
		int ch;
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch){
		case 1:
			fo.writeData();
			break;
		case 2:
			fo.readData();
			break;
		case 3:
			isExit = true;
			break;
		default:
			cout<<"\nInnvalid Choice";
			break;
		}
	}

	return 0;
}

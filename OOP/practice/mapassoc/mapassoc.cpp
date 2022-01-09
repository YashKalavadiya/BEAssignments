#include"iostream"
#include"map"

using namespace std;


class StateData {
public:
	map<string, double> states;
	void getElements(int n) {
		for (int i = 0; i < n; i++) {
			string state;
			double pop;
			cout<<"\nEnter state name: ";
			cin>>state;
			cout<<"\nEnter state population: ";
			cin>>pop;
			states.insert({state, pop});
		}
	}

	void displayElements() {
		map<string, double>::iterator i = states.begin();
		while(i != states.end()) {
			cout<<"\n"<<i->first<<" : "<<i->second;
			i++;
		}
	}

	void getPopulation() {
		string state;
		cout<<"\nEnter name of state: ";
		cin>>state;
		if(states.find(state) == states.end()) {
			cout<<"\nNot Found";
		}
		else {
			cout<<"population is: "<<states.find(state)->second;
		}

	}
};

void printMenu() {
	cout<<"\nMENU";
	cout<<"\n1. Print All States";
	cout<<"\n2. Get Particular state";
	cout<<"\n3. Exit";
}

int main() {
	StateData sd;
	cout<<"\nEnter no of states: ";
	int n;
	cin>>n;
	sd.getElements(n);
	bool isExit = false;
	while(!isExit) {
		printMenu();
		int ch;
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch) {
		case 1:
			sd.displayElements();
			break;
		case 2:
			sd.getPopulation();
			break;
		case 3:
			isExit = true;
			break;
		}
	}
	return 0;
}

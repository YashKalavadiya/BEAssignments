#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;


struct studRecord {
	string name, telephone, DOB;
	int rollNo;
};


bool compareByName(studRecord a, studRecord b) {
	return a.name[0] > b.name[0];
}

bool compareByRollNo(studRecord a, studRecord b) {
	return a.rollNo > b.rollNo;
}

class StudentDB {
public:
	vector<studRecord> sdb;

	void addElement() {
		studRecord r;
		cout<<"\nEnter name: ";
		cin>>r.name;
		cout<<"\nEnter telephone no: ";
		cin>>r.telephone;
		cout<<"\nEnter DOB:";
		cin>>r.DOB;
		cout<<"\nEnter Roll No: ";
		cin>>r.rollNo;

		sdb.push_back(r);
	}

	void addElements(int n) {
		for(int i = 0; i < n; i++) {
			studRecord r;
			cout<<"\nEnter name: ";
			cin>>r.name;
			cout<<"\nEnter telephone no: ";
			cin>>r.telephone;
			cout<<"\nEnter DOB:";
			cin>>r.DOB;
			cout<<"\nEnter Roll No: ";
			cin>>r.rollNo;
			sdb.push_back(r);
		}
	}

	void displayElements() {
		vector<studRecord>::iterator i = sdb.begin();
		while(i != sdb.end()) {
			cout<<"\n===================";
			cout<<"\nName: "<<i->name;
			cout<<"\nTel: "<<i->telephone;
			cout<<"\nDOB: "<<i->DOB;
			cout<<"\nRoll No: "<<i->rollNo;
			cout<<"\n==================";
			i++;
		}
	}

	void sortData(string filter) {
		if(filter == "name") {
			sort(sdb.begin(), sdb.end(), compareByName);
		}
		else if(filter == "rollno") {
			sort(sdb.begin(), sdb.end(), compareByRollNo);
		}
	}

	void searchData(string name = "", int rollNo = 0) {
		vector<studRecord>::iterator i = sdb.begin();
		int count = 0;
		while(i != sdb.end()){
			if(i->name == name or i->rollNo == rollNo) {
				cout<<"\nRecord is present at location : "<<count;
				return;
			}
			count += 1;
			i++;
		}
		cout<<"\nRecord not found";
	}
};

void printMenu() {
	cout<<"\nMENU";
	cout<<"\n1. Add Element";
	cout<<"\n2. Display all Elements";
	cout<<"\n3. sort by name";
	cout<<"\n4. sort by roll no";
	cout<<"\n5. search by name";
	cout<<"\n6. search by roll no";
	cout<<"\n7. exit";
}
int main() {
	int ch;
	int n;
	cout<<"\nEnter no of records you want: ";
	cin>>n;
	bool isExit = false;

	StudentDB db;

	db.addElements(n);

	while(!isExit) {
		printMenu();
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch) {
		case 1:
			db.addElement();
			break;
		case 2:
			db.displayElements();
			break;
		case 3:
			db.sortData("name");
			break;
		case 4:
			db.sortData("rollno");
			break;
		case 5: {
			cout<<"\nEnter Name to search: ";
			string name;
			cin>>name;
			db.searchData(name);
			break;
		}
		case 6: {
			cout<<"\nEnter roll no to search: ";
			int rollNo;
			cin>>rollNo;
			db.searchData("", rollNo);
			break;
		}
		default:
			isExit = true;
			break;
		}
	}
	return 0;
}

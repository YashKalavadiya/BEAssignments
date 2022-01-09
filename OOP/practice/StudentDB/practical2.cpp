#include<iostream>

using namespace std;

class StudentDB {
	string nm, cl, div, DOB, bloodGroup, address, telephone, licenseNo, rollNo;
	friend class Student;
};

class Student {

public:
	StudentDB data;

	static int count;

	inline static void showCount() {
		cout<<"\nTotal Records: "<<count;
	}

	inline static void incCount() {
		count += 1;
	}

	Student() {
		data.DOB = "";
		data.nm = "";
		data.cl = "";
		data.div = "";
		data.bloodGroup = "";
		data.address = "";
		data.telephone = "";
		data.licenseNo = "";
		data.rollNo = "";
	}

	Student(Student &s) {
		data.DOB = s.data.DOB;
		data.nm = s.data.nm;
		data.cl = s.data.cl;
		data.div = s.data.div;
		data.bloodGroup = s.data.bloodGroup;
		data.address = s.data.address;
		data.telephone = s.data.telephone;
		data.licenseNo = s.data.licenseNo;
		data.rollNo = s.data.rollNo;
	}
	~Student(){

		cout<<"\nDestroyed!!!!!!";
	}

	void getData() {

		cout<<"\nEnter Data for Student: "<<endl;
		cout<<"Name: ";
		cin>>data.nm;
		cout<<"\nClass: ";
		cin>>data.cl;
		cout<<"\nDOB:";
		cin>>data.DOB;
		cout<<"\nDivision: ";
		cin>>data.div;
		cout<<"\nblood group: ";
		cin>>data.bloodGroup;
		cout<<"\ntelephone: ";
		cin>>data.telephone;
		cout<<"\nRoll No: ";
		cin>>data.rollNo;
		incCount();
	}

	void displayData() {
		cout<<"\n====================\n";
		cout<<data.nm<<endl;
		cout<<data.cl<<endl;
		cout<<data.div<<endl;
		cout<<data.DOB<<endl;
		cout<<data.bloodGroup<<endl;
		cout<<data.address<<endl;
		cout<<data.telephone<<endl;
		cout<<data.licenseNo<<endl;
		cout<<data.rollNo<<endl;
		cout<<"\n=====================\n";
	}
	friend class StudentDB;
};

void printMenu() {
	cout<<"\nMENU";
	cout<<"\n1. Display all Students";
	cout<<"\n2.Create object copy";
	cout<<"\n3. Exit";
}
int Student::count = 0;
int main() {
	int noOfStud;
	retry:
	try{
	cout<<"\nEnter no of students you want:";
	cin>>noOfStud;
	if(noOfStud < 0){
		throw 0;
	}
	}
	catch(int ex){
		cout<<"\nEnter Valid No of records";
		goto retry;
//		return 0;
	}
	Student *sobj = new Student[noOfStud];
	for(int i = 0; i < noOfStud; i++) {
		sobj[i].getData();
	}
	bool isExit = false;

	while(!isExit) {
		printMenu();
		cout<<"\nEnter Choice: ";
		int ch;
		cin>>ch;
		switch(ch) {
		case 1:
			for(int i = 0; i < noOfStud; i++) {
				sobj[i].displayData();
			}
			break;
		case 2:
		{
			Student copy;
			cout<<"Enter Inedx of student to copy: ";
			int idx = 0;
			cin>>idx;
			copy = sobj[idx];
			cout<<"\nCopied....";
			copy.displayData();
			break;
		}
		case 3:
			isExit = false;
			delete [] sobj;
			break;
		}
	}
	return 0;
}

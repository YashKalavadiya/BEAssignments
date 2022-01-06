#include "iostream"

using namespace std;


struct Node {
	bool v, b;
	string name;
	struct Node *next;
};

class LinkedList {
	struct Node *head = NULL;

	void addELement(string name, bool b, bool v) {
		struct Node *ele = head;

		if(head == NULL) {
			head = new Node;
			head->name = name;
			head->b = b;
			head->v = v;
			head->next = NULL;
			return;
		}

		while(ele->next != NULL) {
			ele = ele->next;
		}

		struct Node *newNode = new Node;
		newNode->next = NULL;
		newNode->b = b;
		newNode->v = v;
		newNode->name = name;

		ele->next = newNode;
		return;
	}

	void printElements(string filter) {
		struct Node *ele = head;
		if(head == NULL) {
			cout<<"\nList is empty";
			return;
		}
		while(ele != NULL) {
			if(filter == "none") {
				cout<<"\n Name: "<<ele->name;
			}
			else if(filter == "VorB") {
				if((ele->v or ele->b) and !(ele->v and ele->b)){
					cout<<"\n Name: "<<ele->name;
				}
			}
			else if(filter == "VnB") {
				if(ele->v and ele->b){
					cout<<"\n Name: "<<ele->name;
				}
			}
			else if(filter == "!either") {
				if(!ele->v and !ele->b){
					cout<<"\n Name: "<<ele->name;
				}
			}
			ele = ele->next;
		}
	}

	void inputStudDataAndSave() {
		cout<<"\nEnter Name: ";
		string nm;
		cin>>nm;
		char ans1, ans2;
		cout<<"\ndoes "<<nm<<" like Vanilla?(y/n): ";
		cin>>ans1;
		cout<<"\ndoes "<<nm<<" like ButterScotch?(y/n): ";
		cin>>ans2;
		bool v = ans1 == 'y';
		bool b = ans2 == 'y';
		addELement(nm, b, v);
	}
	void printMenu() {
		cout<<"\n=================================";
		cout<<"\nMENU";
		cout<<"\n1. Add Student";
		cout<<"\n2. Students who like both flavours";
		cout<<"\n3. Students who dont like both flavours";
		cout<<"\n4. Students who like any or none flavours but not both";
		cout<<"\n5. Print alll students";
		cout<<"\n6. Exit";
		cout<<"\n=================================";
	}

public:
	void execute() {
		cout<<"\nEnter number of students you want: ";
		int n;
		cin>>n;
		for(int i = 0; i < n; i++) {
			inputStudDataAndSave();
		}

		bool isExit = false;

		while(!isExit) {
			printMenu();
			cout<<"\nEnter your Choice: ";
			int ch;
			cin>>ch;
			switch(ch) {
			case 1:
				inputStudDataAndSave();
				break;
			case 2:
				printElements("VnB");
				break;
			case 3:
				printElements("!either");
				break;
			case 4:
				printElements("VorB");
				break;
			case 5:
				printElements("none");
				break;
			case 6:
				isExit = true;
				break;
			}
		}
	}
};
int main() {

	LinkedList ll;
	ll.execute();

	return 0;
}











//
//
//
//
//
//
//
//
//if(filter == "none") {
//			int count = 1;
//			cout<<"\nAll Students in List: "<<endl;
//			while(ele!= NULL) {
//				cout<<"\n"<<count++<<" Name: "<<ele->name;
//			ele = ele->next;
//			}
//		}
//		else if(filter == "VorB") {
//			int count = 1;
//			cout<<"\nStudents who like either vanilla or Butter scotch or not Both: "<<endl;
//			while(ele != NULL) {
//				if((ele->v or ele->b) and !(ele->v and ele->b)){
//					cout<<"\n"<<count++<<" Name: "<<ele->name;
//				}
//				ele = ele->next;
//			}
//		}
//		else if(filter == "VnB") {
//			int count = 1;
//			cout<<"\nStudents who like both vanilla and Butter scotch: "<<endl;
//			while(ele != NULL) {
//				if(ele->v and ele->b){
//					cout<<"\n"<<count++<<" Name: "<<ele->name;
//				}
//				ele = ele->next;
//			}
//		}
//		else if(filter == "!either") {
//			int count = 1;
//			cout<<"\nStudents who dont like both vanilla and Butter scotch: "<<endl;
//			while(ele != NULL) {
//				if(!(ele->v and ele->b)){
//					cout<<"\n"<<count++<<" Name: "<<ele->name;
//				}
//				ele = ele->next;
//			}
//		}

#include<iostream>
using namespace std;

struct Node {
    string binary;
    bool vanilla = false, butterscotch = false;
    string name;
    struct Node *next, *prev;
};

struct Node *head = NULL;

class LinkedListManager {
    public:

void printMenu() {
    cout<<"\n=========================";
    cout<<"\nMENU"<<endl;
    cout<<"\n1.Print Linked List"<<endl;
    cout<<"\n2. get students who like both vanilla and butterscotch both"<<endl;
    cout<<"\n3. get students who like either vanilla or butterscotch but not both"<<endl;
    cout<<"\n4. get students who like neither vanilla not butterscotch"<<endl;
    cout<<"\n5. EXIT"<<endl;
    cout<<"=========================";
}

void addElementToEnd(string name, bool vanilla, bool butterscotch) {
    struct Node *ele = head;
    if(head == NULL) {
        head = new Node;
        head->butterscotch = butterscotch;
        head->vanilla = vanilla;
        head->name = name;
        head->next = NULL;
        head->prev = NULL;
        return;
    }
    while(ele->next != NULL){
        ele = ele->next;
    }
    struct Node* newData = new Node;
    newData->butterscotch = butterscotch;
    newData->vanilla = vanilla;
    newData->name = name;
    newData->next = NULL;
    newData->prev = ele;
    ele->next = newData;
}

void printAllElements() {
    struct Node *ele = head;
    int count = 1;
    if(head == NULL) {
        cout<<"\nList is empty";
    }
    while(ele != NULL) {
        cout<<"\nStudent "<<count<<" : "<<ele->name<<" vanilla: "<<ele->vanilla<<" Butterscotch: "<<ele->butterscotch;
        ele = ele->next;
        count++;
    }
}

void printConditionally(string filter) {
    struct Node *ele = head;
    int count = 1;
    if(head == NULL) {
        cout<<"\nList is empty";
    }
    while(ele != NULL) {
        if(filter == "both") {
            if(ele->butterscotch && ele->vanilla) {
                cout<<"\n"<<ele->name<<endl;
            }
        }
        else if(filter == "VorB") {
            if((ele->butterscotch || ele->vanilla) && !(ele->butterscotch && ele->vanilla)) {
                cout<<"\n"<<ele->name<<", vanilla: "<<ele->vanilla<<", Butterscotch: "<<ele->butterscotch;
            }
        }
        else if(filter == "!either") {
            if(!ele->butterscotch && !ele->vanilla) {
                cout<<"\n"<<ele->name;
            }
        }
        ele = ele->next;
        count++;
    }
}

void execute() {
    int n;
    bool isExit = false;
    cout<<"Enter No of students you want: ";
    cin>>n;
    for(int i = 0; i < n; i++) {
        string name;
        char butterscotch, vanilla;
        cout<<"Enter Name "<<i+1<<" :";
        cin>>name;
        cout<<"\nDoes this student like butterscotch(y/n): ";
        cin>>butterscotch;
        cout<<"\nDoes this student like vanilla(y/n):";
        cin>>vanilla;
        addElementToEnd(name, vanilla == 'y' ? (true) : (false), butterscotch == 'y' ? (true) : (false));
    }

    while(!isExit) {
        printMenu();
        int ch;
        cout<<"\nEnter yor choice: ";
        cin>>ch;
        switch(ch) {
            case 1:
            printAllElements();
            break;
            case 2:
            printConditionally("both");
            break;
            case 3:
            printConditionally("VorB");
            break;
            case 4:
            printConditionally("!either");
            break;
            case 5:
            isExit = true;
            break;
        }
    }
}
};

int main() {
    LinkedListManager lm;
    lm.execute();
    return 0;
}
#include<iostream>
using namespace std;

struct Node {
    string binary;
    struct Node *next, *prev;
};

struct Node *head = NULL;

class LinkedListManager {
    public:

void printMenu() {
    cout<<"\n=========================";
    cout<<"\nMENU"<<endl;
    cout<<"\n1.Print Linked List"<<endl;
    cout<<"\n2. get 1's Compliment"<<endl;
    cout<<"\n3. get 2's compliment"<<endl;
    cout<<"\n4. Add two binary numbers"<<endl;
    cout<<"\n5. EXIT"<<endl;
    cout<<"=========================";
}

void addElementToEnd(string node_data) {
    struct Node *ele = head;
    if(head == NULL) {
        head = new Node;
        head->binary = node_data;
        head->next = NULL;
        head->prev = NULL;
        return;
    }
    while(ele->next != NULL){
        ele = ele->next;
    }
    struct Node* newData = new Node;
    newData->binary = node_data;
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
        cout<<"\nElement "<<count<<" : "<<ele->binary;
        ele = ele->next;
        count++;
    }
}

string addBinary(string a, string b){
   string result = "";
   int temp = 0;
   int size_a = a.size() - 1;
   int size_b = b.size() - 1;
   while (size_a >= 0 || size_b >= 0 || temp == 1){
      temp += ((size_a >= 0)? a[size_a] - '0': 0);
      temp += ((size_b >= 0)? b[size_b] - '0': 0);
      result = char(temp % 2 + '0') + result;
    //   cout<<"+++++++"<<(temp%2 + '0');
      temp /= 2;
      size_a--; size_b--;
   }
   return result;
}

void onesCompliment() {
    struct Node *ele = head;
    int count = 1;
    if(head == NULL) {
        cout<<"\nList is Empty!!!";
    }
    while(ele != NULL) {
        string bin = ele->binary;
        string compliment = "";
        for(int i = 0; i < bin.length(); i++) {
            if(bin[i] == '1') {
                compliment += "0";
                continue;
            }
            compliment += "1";
        }
        cout<<"\nPosition "<<count<<" : "<<bin<<" ==>"<<compliment;
        count++;
        ele = ele->next;
    }
}

void twosCompliment(int pos) {
    struct Node *ele = head;
    int count = 1;
    if(head == NULL) {
        cout<<"\nList is Empty!!!";
    }
    while(ele != NULL) {
        if(pos == count) {
            string bin = ele->binary;
            string compliment = "";
            for(int i = 0; i < bin.length(); i++) {
                if(bin[i] == '1') {
                    compliment += "0";
                    continue;
                }
                compliment += "1";
            }
            string twosCom = addBinary(compliment, "1");
            cout<<"\nPosition "<<count<<" : "<<bin<<" ==>"<<twosCom;
        }
        count++;
        ele = ele->next;
    }
}

void addTwoElements(int first, int second) {
    string firstBin = "", secondBin = "";
    struct Node *ele = head;
    int count = 1;
    if(head == NULL) {
        cout<<"\nList is empty";
        return;
    }
    while(ele!=NULL) {
        if(count == first) {
            firstBin = ele->binary;
        }
        else if(count == second) {
            secondBin = ele->binary;
        }
        ele = ele->next;
        count++;
    }
    string result = addBinary(firstBin, secondBin);

    cout<<"\n"<<firstBin<<" + "<<secondBin<<" = "<<result;

}

void execute() {
        int n;
    bool isExit = false;
    cout<<"Enter No of elements you want: ";
    cin>>n;
    for(int i = 0; i < n; i++) {
        string s;
        cout<<"Enter element "<<i+1<<" :";
        cin>>s;
        addElementToEnd(s);
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
            cout<<"Calculating 1's compliment...";
            onesCompliment();
            break;
            case 3:
            cout<<"\nEnter Position of element: ";
            int pos;
            cin>>pos;
            twosCompliment(pos);
            break;
            case 4:
            int pos1, pos2;
            cout<<"\nEnter Position of 1st element: ";
            cin>>pos1;
            cout<<"\nEnter Position of 2nd element: ";
            cin>>pos2;
            addTwoElements(pos1, pos2);
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
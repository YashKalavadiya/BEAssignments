#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct itemDetails {
    string name, telephone, DOB, code;
    int qty;
    float cost;
    int _id;
};

bool compareById(itemDetails a, itemDetails b) {
    return a.code > b.code;
}
bool compareByName(itemDetails a, itemDetails b) {
    return a.name[0] > b.name[0];
}
bool compareByCost(itemDetails a, itemDetails b) {
    return a.cost < b.cost;
}

bool compareByQty(itemDetails a, itemDetails b) {
    return a.qty < b.qty;
}

class ItemRecords {
    public:
    vector<itemDetails> pd;
    int currentId = 0;
    void insertRecords(int count) {
        string name, tele, dob;
        int id;
        for (int i = 0; i < count; i++) {
            itemDetails d;
            cout<<"\n===============";
            cout<<"\nName: ";
            cin>>d.name;
            cout<<"\nQuantity: ";
            cin>>d.qty;
            cout<<"\nCost: ";
            cin>>d.cost;
            cout<<"\nCode: ";
            cin>>d.code;
            pd.push_back(d);
        }
    }

    void printMenu() {
        cout<<"\nMENU";
        cout<<"\n1. Display all records";
        cout<<"\n2. Search record by Code";
        cout<<"\n3. Sort records by Code";
        cout<<"\n4. Sort record by name";
        cout<<"\n5. Sort record by Cost";
        cout<<"\n6. Sort record by Quantity";
        cout<<"\n7. EXIT";
    }

    void displayAllRecords() {
        vector<itemDetails>::iterator i = pd.begin();

        while(i != pd.end()) {
            cout<<"\n================";
            cout<<"\nName: "<<i->name;
            cout<<"\nQuantity: "<<i->qty;
            cout<<"\nCost: "<<i->cost;
            cout<<"\nCode: "<<i->code;
            cout<<"\n===============";
            i++;
        }
    }

    void searchDataById(string code) {
        vector<itemDetails>::iterator i = pd.begin();

        while(i != pd.end()) {
            if(i->code == code){
                cout<<"\n================";
                cout<<"\nName: "<<i->name;
                cout<<"\nQuantity: "<<i->qty;
                cout<<"\nCost: "<<i->cost;
                cout<<"\nCode: "<<i->code;
                cout<<"\n===============";
                return;
            }
            i++;
        }
        cout<<"\nRecord Not Found";
    }

    void sortRecords(string filter) {
        if(filter == "code") {
            sort(pd.begin(), pd.end(), compareById);
        }
        else if(filter == "name") {
            sort(pd.begin(), pd.end(), compareByName);
        }
        else if(filter == "cost") {
            sort(pd.begin(), pd.end(), compareByCost);
        }
        else if(filter == "qty") {
            sort(pd.begin(), pd.end(), compareByQty);
        }
        displayAllRecords();
    }

    void execute() {
        int ch;
        bool isExit;
        cout<<"Enter no of records you want to insert: ";
        int n;
        cin>>n;
        string code;
        insertRecords(n);
        while(!isExit) {
            printMenu();
            cout<<"\nEnter your choice: ";
            cin>>ch;
            switch(ch) {
                case 1:
                    displayAllRecords();
                    break;
                case 2:
                    cout<<"\nEnter item code to search: ";
                    cin>>code;
                    searchDataById(code);
                    break;
                case 3:
                    sortRecords("id");
                    break;
                case 4:
                    sortRecords("name");
                    break;
                case 5:
                    sortRecords("cost");
                    break;
                case 6:
                    sortRecords("qty");
                    break;
                case 7:
                    isExit = true;
            }
        }
    }
};

int main() {
    // ItemRecords::currentId = 101;
    ItemRecords pr;
    pr.execute();
    return 0;
}
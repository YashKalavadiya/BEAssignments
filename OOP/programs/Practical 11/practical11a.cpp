#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct personalDetails {
    string name, telephone, DOB;
    int _id;
};

bool compareById(personalDetails a, personalDetails b) {
    return a._id > b._id;
}
bool compareByName(personalDetails a, personalDetails b) {
    return a.name[0] > b.name[0];
}

class PersonalRecords {
    public:
    vector<personalDetails> pd;
    int currentId = 0;
    void insertRecords(int count) {
        string name, tele, dob;
        int id;
        for (int i = 0; i < count; i++) {
            personalDetails d;
            cout<<"\n===============";
            cout<<"\nName: ";
            cin>>d.name;
            cout<<"\nPhoneNo: ";
            cin>>d.telephone;
            cout<<"\nDate of birth: ";
            cin>>d.DOB;
            d._id = currentId;
            currentId += 1;
            pd.push_back(d);
        }
    }

    void printMenu() {
        cout<<"\nMENU";
        cout<<"\n1. Display all records";
        cout<<"\n2. Search record by ID";
        cout<<"\n3. Sort records by ID";
        cout<<"\n4. Sort record by name";
        cout<<"\n5. EXIT";
    }

    void displayAllRecords() {
        vector<personalDetails>::iterator i = pd.begin();

        while(i != pd.end()) {
            cout<<"\n================";
            cout<<"\nName: "<<i->name;
            cout<<"\nDOB: "<<i->DOB;
            cout<<"\nPhone No: "<<i->telephone;
            cout<<"\nID: "<<i->_id;
            cout<<"\n===============";
            i++;
        }
    }

    void searchDataById(int id) {
        vector<personalDetails>::iterator i = pd.begin();

        while(i != pd.end()) {
            if(i->_id == id){
                cout<<"\n================";
                cout<<"\nFound Record: ";
                cout<<"\nName: "<<i->name;
                cout<<"\nDOB: "<<i->DOB;
                cout<<"\nPhone No: "<<i->telephone;
                cout<<"\nID: "<<i->_id;
                cout<<"\n===============";
                return;
            }
            i++;
        }
        cout<<"\nRecord Not Found";
    }

    void sortRecords(string filter) {
        if(filter == "id") {
            sort(pd.begin(), pd.end(), compareById);
        }
        else if(filter == "name") {
            sort(pd.begin(), pd.end(), compareByName);
        }
        displayAllRecords();
    }

    void execute() {
        int ch;
        bool isExit;
        cout<<"Enter no of records you want to insert: ";
        int n;
        cin>>n;
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
                    int id;
                    cout<<"\nEnter ID to search: ";
                    cin>>id;
                    searchDataById(id);
                    break;
                case 3:
                    sortRecords("id");
                    break;
                case 4:
                    sortRecords("name");
                    break;
                case 5:
                    isExit = true;
            }
        }
    }
};

int main() {
    // PersonalRecords::currentId = 101;
    PersonalRecords pr;
    pr.execute();
    return 0;
}
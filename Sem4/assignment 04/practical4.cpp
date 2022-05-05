#include "iostream"

using namespace std;

struct record {
    string name;
    long phone;
    int chain = -1;
};

class HashMap {
    record *bookWithReplacement;
    record *bookWithoutReplacement;
    int size;
    public:

    HashMap(int n) {
        bookWithReplacement = new record[n];
        bookWithoutReplacement = new record[n];
        this->size = n;
    }

    int generateHash(long phone) {
        return phone%size;
    }

    void insertWithReplacement(record rec, int loc) {
        if(bookWithReplacement[loc].name == ""){
            bookWithReplacement[loc] = rec;
        }
        else {
            int tempLoc = loc;
            bool isPlaced = false;

            if (generateHash(bookWithReplacement[loc].phone) == loc){
                for (int i = tempLoc+1; i < size; i++) {
                    if (bookWithReplacement[i].name == "") {
                        bookWithReplacement[i] = rec;
                        isPlaced = true;
                        break;
                    }
                }
                if(!isPlaced) {
                    for (int i = 0; i < size; i++) {
                        if (bookWithReplacement[i].name == "") {
                            bookWithReplacement[i] = rec;
                            isPlaced = true;
                            break;
                        }
                    }
                }
            }
            else {
                for (int i = tempLoc+1; i < size; i++) {
                    if (bookWithReplacement[i].name == "") {
                        bookWithReplacement[i] = bookWithReplacement[loc];
                        bookWithReplacement[loc] = rec;
                        isPlaced = true;
                        break;
                    }
                }
                if(!isPlaced) { 
                    for (int i = 0; i < size; i++) {
                        if (bookWithReplacement[i].name == "") {
                            bookWithReplacement[i] = rec;
                            isPlaced = true;
                            break;
                        }
                    }
                }
            }
        }
    }

    void insertWithoutReplacement(record rec, int loc) {
        if(bookWithoutReplacement[loc].name == ""){
            bookWithoutReplacement[loc] = rec;
        }
        else {
            int tempLoc = loc;
            bool isPlaced = false;
                for (int i = tempLoc+1; i < size; i++) {
                    if (bookWithoutReplacement[i].name == "") {
                        bookWithoutReplacement[i] = rec;
                        isPlaced = true;
                        break;
                    }
                }
                if(!isPlaced) {
                    for (int i = 0; i < size; i++) {
                        if (bookWithoutReplacement[i].name == "") {
                            bookWithoutReplacement[i] = rec;
                            isPlaced = true;
                            break;
                        }
                    }
                }
        }
    }

    void searchWithReplacement(long phone, int hash) {
        int comparisons = 1;
        if(bookWithReplacement[hash].phone == phone) {
            cout<<"\n============With Replacement==========";
            cout<<"\n\tRecord Found at : "<<hash<<" and name is: "<<bookWithReplacement[hash].name<<"\nComparisons: "<<comparisons;
            cout<<"\n=========================================";
        }
        else if(bookWithReplacement[hash].phone == 0) {
            cout<<"\n============With Replacement==========";
            cout<<"\n\tRecord not found";
            cout<<"\n=========================================";
        }
        else {
            for(int i = hash+1; i < size; i++) {
                comparisons += 1;
                if(bookWithReplacement[i].phone == phone) {
                    cout<<"\n============With Replacement==========";
                    cout<<"\n\tRecord Found at : "<<i<<" and name is: "<<bookWithReplacement[i].name<<"\nComparisons: "<<comparisons;
                    cout<<"\n=========================================";
                }
            }
        }
    }

    void searchWithoutReplacement(long phone, int hash) {
        int comparisons = 1;
        if(bookWithoutReplacement[hash].phone == phone) {
            cout<<"\n============Without Replacement==========";
            cout<<"\n\tRecord Found at : "<<hash<<" and name is: "<<bookWithoutReplacement[hash].name<<"\nComparisons: "<<comparisons;
            cout<<"\n=========================================";
        }
        else if(bookWithoutReplacement[hash].phone == 0) {
            cout<<"\n============Without Replacement==========";
            cout<<"\n\tRecord not found";
            cout<<"\n=========================================";
        }
        else {
            for(int i = hash+1; i < size; i++) {
                comparisons += 1;
                if(bookWithoutReplacement[i].phone == phone) {
                    cout<<"\n============Without Replacement==========";
                    cout<<"\n\tRecord Found at : "<<i<<" and name is: "<<bookWithoutReplacement[i].name<<"\nComparisons: "<<comparisons;;
                    cout<<"\n=========================================";
                }
            }
        }
    }

    void search(long phone) {
        int hash = generateHash(phone);
        searchWithoutReplacement(phone, hash);
        searchWithReplacement(phone, hash);
    }

    void insertRecord(record rec) {
        int hash = generateHash(rec.phone);
        insertWithoutReplacement(rec, hash);
        insertWithReplacement(rec, hash); 
    }

    void printHashMap() {
        cout<<"\n============Without Replacement=================";
        for (int i = 0; i < size; i++) {
            if(bookWithoutReplacement[i].phone != 0) {
                cout<<"\n\tName: "<<bookWithoutReplacement[i].name;
                cout<<"\n\tPhone: "<<bookWithoutReplacement[i].phone;
            }
        }
        cout<<"\n============With Replacement=================";
        for (int i = 0; i < size; i++) {
            if(bookWithReplacement[i].phone != 0) {
                cout<<"\n\tName: "<<bookWithReplacement[i].name;
                cout<<"\n\tPhone: "<<bookWithReplacement[i].phone;
            }
        }
    }

    void printMenu() {
        cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout<<"\n               MENU              ";
        cout<<"\n1. Insert record";
        cout<<"\n2. Search Record";
        cout<<"\n3. Print HashMap";
        cout<<"\n4. Exit";
        cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    }
    void exec() {
        bool exit = false;
        while (!exit) {
            printMenu();
            int ch;
            cout<<"\nEnter your choice: ";
            cin>>ch;
            switch(ch) {
                case 1: {
                    long phone;
                    string name;
                    cout<<"\nEnter Name: ";
                    cin>>name;
                    cout<<"\nEnter phone no: ";
                    cin>>phone;
                    record rec = {name, phone, -1};
                    insertRecord(rec);
                    break;
                }
                case 2: {
                    cout<<"\nEnter Phone no to search: ";
                    long phone;
                    cin>>phone;
                    search(phone);
                    break;
                }
                case 3: {
                    printHashMap();
                    break;
                }
                case 4:
                    exit = true;
                    break;
                default:
                    cout<<"\nINVALID CHOICE";
            }
        }
    }
};

int main() {
    int n;
    cout<<"\nEnter Size of hashmap: ";
    cin>>n;
    HashMap map(n);
    map.exec();
    return 0;
}
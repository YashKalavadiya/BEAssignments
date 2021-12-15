#include<iostream>
#include<fstream>

using namespace std;

class FileHandeler{
    public:
    ofstream  wfile;
    ifstream rfile;

    void writeToFile(string name){
        wfile.open("data.txt", ios::out);
        wfile<<name<<"\n"<<endl;
    }

    void readDataFromFile(){
        rfile.open("data.txt", ios::in);
        string op;
        rfile>>op;
        cout<<op;
    }

    ~FileHandeler(){
        wfile.close();
        rfile.close();
    }
};
int main() {

    bool isExit = false;

    FileHandeler fhldr;

    while(!isExit){
        int choice;
        cout<<"\nMENU";
        cout<<"\n1.Write to a file";
        cout<<"\n2. Read File";
        cout<<"\n3. Exit";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        string name;

        switch(choice){
            case 1:
            cout<<"\nEnter name to save in file: ";
            cin>>name;
            fhldr.writeToFile(name);
            break;
            case 2:
            fhldr.readDataFromFile();
            break;
            case 3:
            isExit = true;
            break;
            default:
            cout<<"\nInvalid Choice";
        }
    }

    return 0;
}
#include<iostream>
using namespace std;

#define max 100

class Publication {
    public:
    string title;
    float  price;

    Publication(){
        this->title="";
        this->price = 0.0;
    }

    Publication(string title, float price){
        this->title = title;
        this->price = price;
    }

    void setPub(string title, float price){
        this->title = title;
        this->price = price;
    }
};

class Book: public Publication {
    public:
    int pageCount;
    void setData(int pageCount){
        this->pageCount = pageCount;
    }
};

class Tape: public Publication {
    public:
    float playingTime;
    void setData(float playingTime){
        this->playingTime = playingTime;
    }
};

int main() {
    int count;
    cout<<"Enter No of Entries: ";
    cin>>count;

    // Tape tobj = new Tape[count];
    // Book bobj= new Book[count];
    Book *b = new Book[count];
    Tape *t = new Tape[count];

    for(int i = 0; i < count; i++) {
        float price, playTime;
        string title;
        int pageCount;
        try{
            cout<<"\nFor Record: "<<i+1<<endl;
            cout<<"\nTitle: ";
            cin>>title;
            cout<<"\nPrice: ";
            cin>>price;
            cout<<"\nPage Count: ";
            cin>>pageCount;
            cout<<"\nPlaying Time: ";
            cin>>playTime;
            if(pageCount <= 0){
                throw 1;
            }
        }
        catch(int e){
            price = 0.0;
            title="No Title";
            pageCount = 0;
            playTime = 0.0;

            b[i].setData(pageCount);
        b[i].setPub(title, price);
        t[i].setData(playTime);
        t[i].setPub(title, price);
        }
        
        b[i].setData(pageCount);
        b[i].setPub(title, price);
        t[i].setData(playTime);
        t[i].setPub(title, price);
    }

    for(int i = 0; i < count; i++) {
        cout<<"\n===============================";
        cout<<"\nTitle is: "<<b[i].title;
        cout<<"\nPrice of Book is: "<<b[i].price;
        cout<<"\nPage COunt is: "<<b[i].pageCount;
        cout<<"\nPlaytime is: "<<t[i].playingTime;
        cout<<"\n===============================";
    }
    return 0;
}
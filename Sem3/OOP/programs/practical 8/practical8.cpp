#include<iostream>
using namespace std;

class Sort {
    public:
    template <typename T>
    void sortArr(T arr[], int len){
        for(int i = 0; i < len; i++) {
            int min = i;
            for (int j = i+1; j < len; j++){
                if (arr[min] > arr[j]){
                    min = j;
                }
            }

            T temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
        for (int i = 0; i < len; i++){
            cout<<"arr["<<i<<"]:"<<arr[i]<<endl;
        }
    }

    void exec(){
        cout<<"Enter length of array(for both float and int):"<<endl;
        int len;
        cin>>len;
        int iarr[len];
        float farr[len];
        bool isExit = false;
        cout<<"\nEnter elements for int array: "<<endl;
        for (int i = 0; i < len; i++) {
            cin>>iarr[i];
        }
        cout<<"\nEnter elements for float array: "<<endl;
        for(int i = 0; i < len; i++) {
            cin>>farr[i];
        }
        
        while(!isExit){
            int ch;
            cout<<"MENU\n";
            cout<<"1. Sort INT array"<<endl;
            cout<<"2. sort FLOAT array"<<endl;
            cout<<"3. EXIT"<<endl;
            cout<<"Enter your choice: ";
            cin>>ch;
            switch(ch){
                case 1:
                this->sortArr(iarr, len);
                break;
                case 2:
                this->sortArr(farr, len);
                break;
                case 3:
                isExit = true;
            }
        }
    }
};

int main() {

    Sort s;
    s.exec();
    return 0;
}
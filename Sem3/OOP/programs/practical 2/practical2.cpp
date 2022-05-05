#include<iostream>
#include<string>
using namespace std;
#define max 100

class personal_info {
    string license, DOB, bloodG;
    public:
    personal_info();
    personal_info(personal_info &);
    ~personal_info(){
        cout<<"Object destroyed";
    }
    friend class Student;
};

class Student{
    string name, address, year;
    char div;
    int rollNo;
    long mob;
    static int cnt;
    public:
    void create(personal_info &);
    void display(personal_info &);

    inline static void showcnt(){
        cout<<"\nTotal No of Records: "<<cnt;
    }
    inline static void inccnt(){
      cnt++;
    }

    Student();
    Student(Student &);
    ~Student(){
        cout<<"Destroyed Record";
    }
};
int Student::cnt;

Student::Student(){
    name="Jon Doe";
    address = "43rd Ave, NYC, NY";
    year="SE COMP";
    div='C';
    rollNo=21379;
    mob=1234567890;
}

personal_info::personal_info(){
    license = "MH50123421";
    DOB="10/10/2002";
    bloodG = "z-";
}

Student::Student(Student &obj){
    this->name = obj.name;
    this->address = obj.address;
    this->year = obj.year;
    this->div = obj.div;
    this->rollNo = obj.rollNo;
    this->mob = obj.mob;
}

personal_info::personal_info(personal_info &obj){
    license = obj.license;
    DOB = obj.DOB;
    bloodG = obj.bloodG;
}

void Student::create(personal_info &obj){
    cout<<"\nName: "<<endl;
    cin>>name;
    cout<<"\nAddress:"<<endl;
    cin>>address;
    cout<<"\nDate Of Birth:"<<endl;
    cin>>obj.DOB;
    cout<<"\nYear:"<<endl;
    cin>>year;
    cout<<"\nDivision: "<<endl;
    cin>>div;
    cout<<"\nRoll no:"<<endl;
    cin>>rollNo;
    cout<<"Blood Group: "<<endl;
    cin>>obj.bloodG;
    cout<<"\nLicense:"<<endl;
    cin>>obj.license;
    cout<<"\nPhone No:"<<endl;
    cin>>mob;
}

void Student::display(personal_info &obj){
    cout<<"\n==============================="<<endl;
    cout<<"\nName Of Student: "<<name;
    cout<<"\nAddress: "<<address;
    cout<<"\nDOB:"<<obj.DOB;
    cout<<"\nYear:"<<year;
    cout<<"\nDiv: "<<div;
    cout<<"\nRoll: "<<rollNo;
    cout<<"\nBlood Group: "<<obj.bloodG;
    cout<<"\nLicense: "<<obj.license;
    cout<<"\nPhone: "<<mob;
    cout<<"\n===========================";
}

int main() {
    int n;
    int ch;
    char ans='y';

    cout<<"\nEnter No of students: ";
    cin>>n;
    cout<<"\n================================";
    Student *sobj = new Student[n];
    personal_info *pobj = new personal_info[n];

    do {
        cout<<"\nMenu\n1. Create DB\n 2. Display DB\n 3. Copy Constructor\n 4. Default Constructor\n5. Delete (Destructor)";
        cout<<"\nEnter Choice: ";
        cin>>ch;
        switch(ch){
            case 1:{
            for (int i = 0; i < n; i++) {
                sobj[i].create(pobj[i]);
                sobj[i].inccnt();
            }
            }
            break;
            case 2:{
                sobj[0].showcnt();
                for (int i = 0; i < n; i++){
                    sobj[i].display(pobj[i]);
                }
            }
            break;
            case 3:{
                Student obj1;
                personal_info obj2;
                obj1.create(obj2);
                Student obj3(obj1);

                personal_info obj4(obj2);
                cout<<"Data Copied";
                obj3.display(obj4);
            }
            break;
            case 4:{
                Student obj1;
                personal_info obj2;
                cout<<"\nDefault Constructor is called";
                obj1.display(obj2);
            }
            break;
            case 5:
                delete [] sobj;
                delete [] pobj;
        }
        cout<<"\nDo you want to continue? (y/n)";
        cin>>ans;
    }while(ans=='y');

return 0;
}
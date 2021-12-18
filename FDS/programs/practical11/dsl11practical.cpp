#include<iostream>
#include<conio>
#define MAX 10
using namespace std;
int data[MAX],rear, front;
void initialize();
int empty();
int full();
void insertion();
void deletion();
void print();
int main()
{
 int ch;
 initialize();
 do
 {
 cout<<"\n ***QUEUE OPERATIONS";
 cout<<"\n 1. Insertion";
  cout<<"\n 2. Deletion";
  cout<<"\n 3. Print";
  cout<<"\n 4. EXIT";
  cout<<"\n Enter your choice: ";
  cin>>ch;

switch (ch)
 {
 case 1: if(full()==0)
 {
 insertion();
 }
 else
 {
  cout<<"\nQueue is Full!!!";
 }
 break;
 case 2: if(empty()==0)
 {
 deletion();
 }
 else
 {
  cout<<"\nQueue is Empty!!!";
 }
 break;
case 3: print();
 break;
 case 4: break;
 default:
  cout<<"Invalid choice";
 }
 } while(ch!=4);
 return 0;
}
void initialize()
{
 rear=front=-1;
}
int full()
{
 if(rear==MAX-1)
 return(1);
 else
 return(0);
}
int empty()
{
 if(rear==-1)
 return(1);
 else
 return(0);
}
void insertion()
{
int x;
  cout<<"Enter data to be insert: ";
 cin>>x;
 if(rear==-1)
 {
 rear=front=0;
 data[rear]=x;
 }
 else
 {
 rear=rear+1;
 data[rear]=x;
 }
}
 void deletion()
{
 int x;
 x=data[front];
 if(front==rear)
 {
 rear=front=-1;
 }
 else
 {
 front=front+1;
 }
 cout<<"\nDeleted data="<<x;
}
void print()
{
 int i;
 if(front==-1)
 {
  cout<<"\nQueue is Empty!!!";
 }
 else
 {
  cout<<"\nQueue data: ";
 for(i=front;i<=rear;i++)
 {
  cout<<"\t"<<data[i];
 }
 }
}

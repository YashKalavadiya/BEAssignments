#include<bits/stdc++.h>
using namespace std;
class node
 {					//Declaring elements of a node
  public:
  int seat_no;
  char status;
  node *prev,*next;
 };
 class ticket
 {
  public:			
  node *head[10],*last[10];			//10 elements representing no. of rows
  ticket()
  {
   for(int i=0;i<10;i++)
   {
    head[i]=NULL;					//initially,assigning head and last node to NULL
    last[i]=NULL;
   }
  }
  public:
  void  viewchart();
  void display();
  void booking();
  void cancle_booking();
 };
 void ticket::viewchart()
 {
  cout<<"(F represents Free seats and B represents Booked seats)"<<endl<<endl;
  int i,j;
  for(i=0;i<10;i++)
  {
   for(j=0;j<7;j++)
   {
    node *ptr;				//creating a node for each seat...included in a loop
    ptr=new node();
    ptr->prev=ptr->next=NULL;
    ptr->seat_no=j+1;
    ptr->status='F';
    if(head[i]==NULL)
    {
     head[i]=ptr;		//if element is null then assign the pointer to the single element
     last[i]=ptr;
    }
    else
    {
     last[i]->next=ptr; 		//else move the pointer to the next node and store the same
     ptr->prev=last[i];
     ptr->next=head[i];
     last[i]=ptr;
    }
   }
   head[i]->prev=last[i];     //assigning the last node's address to the head's previous...
  }
 }
 void ticket::display()
 {
  node *temp;
  for(int i=0;i<10;i++)		//to display the seats which are booked as well as which are free
  {
   temp=head[i];
   cout<<"ROW NO"<<" "<<i+1<<"->"<<"\t";
   do
   {
    cout<<temp->seat_no<<","<<temp->status<<"\t";
    temp=temp->next;
   }while(temp!=head[i]);
   cout<<"\n";
   }
 }
 void ticket::booking()
 {
//  int flag =0;
  int row,seatno,count=0;
  node *temp;
  cout<<"ENTER THE ROW NO";
  cin>>row;
  cout<<"Enter the no of seats";
  cin>>seatno;
  temp=head[row-1];
  do
  {
   if(temp->status=='F')
    {
     count++;
    }
   else if(temp->status=='B')
    {
     count=0;
    }
   if(count==seatno)
     {
      temp=head[row-1];
      if(temp->status!='F')
      {
        while(temp->status!='F')
        {
         temp=temp->next;
        }
        for(int i=0;i<seatno;i++)
        {
         temp->status='B';
         temp=temp->next;
        }
       }
      else
      {
       for(int i=0;i<seatno;i++)
       {
        temp->status='B';
        temp=temp->next;
       }
      }
    }
    temp=temp->next;
   }while(temp!=head[row-1]);
 }
 void ticket::cancle_booking()
 {
  int row,seatno,loc;
  node *temp;
  cout<<"Enter the row from where you want to cancle booking"<<endl;
  cin>>row;
  cout<<"Enter the location for cancling booking"<<endl;
  cin>>loc;
  cout<<"Enter the no of seats are to be cancled"<<endl;
  cin>>seatno;
  temp=head[row-1];
  for(int i=0;i<loc-1;i++)
  {
   temp=temp->next;
  }
  for(int i=0;i<seatno;i++)
  {
   temp->status='F';
   temp=temp->next;
  }
 }
int main()
{
 int ch;
 ticket c;
 do
 {
 cout<<"ENTER YOUR CHOICE:\n1.View seating chart\n2.Display\n3.Booking\n4.Cancel booking\n5.Exit\n";
 cin>>ch;
 
 switch (ch)
 {
  case 1:
        c.viewchart();
        c.display();
        break;
  case 2:
        c.display();
        break;
  case 3:
        c.booking();
        c.display();
        break;
  case 4:
        c.cancle_booking();
        c.display();
        break;
  case 5:
      
       break;
 }
 }while(ch!=5);
 
 return 0;
}

 



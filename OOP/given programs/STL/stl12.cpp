#include<iostream>
#include<set>
using namespace std;
int main()
{
    set < int > s;
  
    // inserting elements in random order .
    s.insert( 60 ) ;
    s.insert( 10 ) ;
    s.insert( 20 ) ;
    s.insert( 20 ) ;
    s.insert( 40 ) ;
    s.insert( 50 ) ;
	s.insert( 50 ) ;
     
    // printing set s
    //initialising the iterator, iterating to the beginning of the set.
 
    set<int >::iterator it ;
    cout << "The element of set s are : \n";
    for (it = s.begin() ; it != s.end() ; it++ ) 
    {
        cout << *it<<" ";
    }
    cout << endl;
     
    cout<< "The size of set : " << s.size() <<endl ;
    return 0 ;
}
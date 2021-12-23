#include <iostream>     // std::cout  
#include <algorithm>    // std::minmax  
  
using namespace std;  
  
int main () 
{  
  auto result = minmax({2,3,1,4,5});  
  
  cout << "The minimum value obtained is : ";   
  cout << result.first<<endl;   
  cout << "\nThe maximum value obtained is : ";   
  cout << result.second <<endl;  
  return 0;  
}  
#include <iostream>     // std::cout
#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>       // std::vector
using namespace std;

int main ()
 {
  vector<int> v{10,20,30,5,15};
  int i;
  
  cout << "\n Initial Vector Elements :";
  for (i=0; i<v.size(); i++)
    cout << ' ' << v[i];
  
  make_heap (v.begin(),v.end());
  
  cout << "\n Vector Elements after make_heap :";
  for (i=0; i<v.size(); i++)
    cout << ' ' << v[i];
  
  cout << "\n Initial max heap   : " << v.front() << '\n';

  pop_heap (v.begin(),v.end()); 
  
  cout << "\n Vector Elements after pop_heap:";
  for (i=0; i<v.size(); i++)
    cout << ' ' << v[i];
  
  v.pop_back();
  
  cout << "\n Vector Elements after pop_back:";
  for (i=0; i<v.size(); i++)
    cout << ' ' << v[i];
  
  cout << "\n max heap after pop_back : " << v.front() << '\n';

  v.push_back(40); 
  
  cout << "\n Vector Elements after push_back:";
  for (i=0; i<v.size(); i++)
    cout << ' ' << v[i];
  
  push_heap (v.begin(),v.end());
  
  cout << "\n Vector Elements after push_heap:";
  for (i=0; i<v.size(); i++)
    cout << ' ' << v[i];
  
  cout << "\n max heap after push: " << v.front() << '\n';

  sort_heap (v.begin(),v.end());

  cout << "\n final sorted range :";
  for (i=0; i<v.size(); i++)
    cout << ' ' << v[i];

  cout << '\n';

  return 0;
}
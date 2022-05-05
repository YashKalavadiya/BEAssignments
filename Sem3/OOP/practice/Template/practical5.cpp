#include "iostream"
#include "climits"

using namespace std;

template<typename T>
class SortingAlgo {
public:
	T *arr;
	int len;
	SortingAlgo(int n) {
		arr = new T(n);
		len = n;
	}
//	template<class T1>
	void getElements() {
		for(int i = 0; i < len; i++) {
			cout<<"\n"<<i+1<<": ";
			cin>>arr[i];
			cout<<"\n"<<arr[i];
		}
	}
//	template<typename T1>
	void sortArray() {
		for(int i = 0; i < len; i++) {
			int min = i;
			for(int j = i+1; j < len; j++) {
				if(arr[j] < arr[min]) {
					min = j;
				}
			}
			if(min != i) {
				T temp = arr[min];
				arr[min] = arr[i];
				arr[i] = temp;
			}
		}
	}

//	template<typename T1>
	void display() {
		for (int i = 0; i < len; i++) {
			cout<<"\n"<<i+1<<": "<<arr[i];
		}
	}
};

void printMenu() {
	cout<<"\nMENU";
	cout<<"\n1. sort float array";
	cout<<"\n2. sort int array";
	cout<<"\n3. display int array";
	cout<<"\n4. Display float array";
}
int main() {
	cout<<"\nEnter no of elements you want in both array: ";
	int n;
	cin>>n;
	SortingAlgo<int> iarr(n);
	SortingAlgo<float> farr(n);

	cout<<"\nEnter elements for int array: ";
//	iarr.getElements<int>();
	iarr.getElements();
	cout<<"\nEnter elements for float array: ";
//	farr.getElements<float>();
	farr.getElements();

	bool isExit = false;

	while(!isExit){
		printMenu();
		cout<<"\nEnter your choice: ";
		cin.clear();
		cin.ignore(INT_MAX,'\n');
		int ch;
		cin>>ch;
		switch(ch) {
		case 1:
			break;
		case 2:
//			farr.sortArray<float>();
//			iarr.sortArray<int>();
			farr.sortArray();
			iarr.sortArray();
			break;
		case 3:
//			iarr.display<int>();
			iarr.display();
			break;
		case 4:
//			farr.display<float>();
			farr.display();
			break;
		}
	}
	return 0;
}

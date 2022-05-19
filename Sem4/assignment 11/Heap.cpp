#include<iostream>

using namespace std;

class Heap {
	int *heapArr;
	int size;
	int capacity;
	int *sorted;
public:
	Heap(int size){
		heapArr = new int[size];
		sorted = new int[size];
		this->size = size;
		this->capacity = size;
	}

	int heapify(int idx) {
		if(idx > capacity) {
			return -1;
		}
		int left = heapify(2*idx);
		int right = heapify(2*idx + 1);
		if (left > right and left > heapArr[idx]) {
			int temp = heapArr[idx];
			heapArr[idx] = heapArr[2*idx];
			heapArr[2*idx] = temp;
		}
		else if(right > left and right > heapArr[idx]){
			int temp = heapArr[idx];
			heapArr[idx] = heapArr[idx*2 + 1];
			heapArr[idx*2 + 1] = temp;
		}
		return heapArr[idx];
	}

	void heapSort() {
		while(capacity > 0){
			int temp = heapArr[1];
			heapArr[1] = heapArr[capacity];
			heapArr[capacity] = temp;
			sorted[capacity] = heapArr[capacity];
			capacity -= 1;
			heapify(1);
		}
	}



	void input() {
		cout<<"\nEnter "<<this->size<<" elements: ";
		for(int i = 1; i <= size; i++) {
			cin>>heapArr[i];
		}
		heapify(1);
	}

	void displayHeap() {
		cout<<"\nRaw Heap Content: ";
		for(int i = 1; i <= size; i++){
			cout<<"\t"<<heapArr[i];
		}
	}

	void displaySorted() {
		cout<<"\nSorted Heap: ";
		for(int i = 1; i <= size; i++){
			cout<<"\t"<<sorted[i];
		}
	}
};

int main() {
	int size;
	cout<<"\nEnter size of heap: ";
	cin>>size;
	Heap *h = new Heap(size);
	h->input();
	h->displayHeap();

	h->heapSort();

	cout<<"\nSorted Heap: ";
	h->displaySorted();
	return 0;
}

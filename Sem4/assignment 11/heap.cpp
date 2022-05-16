#include<iostream>

using namespace std;

class Heap {
	public:

	int *heap, size;

	int lastIndex = 0;

	Heap(int size) {
		heap = new int[size];
		this->size = size;
		// heap[0] = -1;
	}

	void insert(int ele) {
		lastIndex += 1;
		heap[lastIndex] = ele;
		int parent = (lastIndex)/2;
		int child = lastIndex;

		while(parent > 0) {
			if(heap[parent] < heap[child]) {
				int temp = heap[parent];
				heap[parent] = heap[child];
				heap[child] = temp;

				child = parent;
				parent = parent / 2;
			}
			else {
				parent = -1;
			}
		}
		cout<<" ";
		// cout<<heap[lastIndex];
		// cout<<"sdfdfsfsd\n";
	}

	void printHeap() {
		for(int i = 1; i <= lastIndex; i++) {
			cout<<"\n"<<heap[i];
		}
	}

};

int main() {
	Heap *h = new Heap(10);

	h->insert(49);
	h->insert(32);
	h->insert(10);
	h->insert(50);
	h->insert(12);
	h->insert(55);
	h->insert(23);
	h->insert(11);
	h->insert(5);
	h->insert(43);

	h->printHeap();
	return 0;
}

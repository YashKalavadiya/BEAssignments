public class Heap {

	public int heap[], size;

	Heap(int size) {
		heap = new int[size];
		this.size = size;
		this.heap[0] = -1;
	}

	public void insertElement(int ele) {
		heap[heap.length] = ele;
		int parent = (heap.length)/2;
		while (parent >= 0) {
			if (heap[parent] < ele) {
				heap[parent] = ele;
				heap[]
			}
		}
	}

	public static void main(String ar[]){

	}
}

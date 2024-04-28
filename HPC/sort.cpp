#include<bits/stdc++.h>
#include<omp.h>

using namespace std;


void seqBubble(int array[], int size) {
    int arr[size];
    for(int i = 0; i < size; i++) {
        arr[i] = array[i];
    }


    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout<<"Sequential Bubble Sorted Elements: "<<endl;
    for(int i = 0; i < size; i++) {
        cout<<arr[i]<< " ";
    }
    cout<<endl;
}


void parallelBubble(int array[], int size) {
    int arr[size];
    for(int i = 0; i < size; i++) {
        arr[i] = array[i];
    }


    for(int i = 0; i < size - 1; i++) {
        if(i % 2 == 0) {
            #pragma omp parallel for
            for(int j = 1; j < size - 1; j += 2) {
                if(arr[j] > arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                }
            }
        }
        else {
            #pragma omp parallel for
            for(int j = 0; j < size - 1; j += 2) {
                if(arr[j] > arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                }
            }
        }
    }

    cout<<"Parallel Bubble Sorted Elements: "<<endl;
    for(int i = 0; i < size; i++) {
        cout<<arr[i]<< " ";
    }
    cout<<endl;
}

void merge(int arr[], int low, int mid, int high, int size) {

    int res[size];
    int i = low;
    int j = mid + 1;
    int k = 0;
    while((i <= mid) and (j <= high)) {
        if(arr[i] < arr[j]) {
            res[k] = arr[i];
            i += 1;
            k += 1;
        }
        else {
            res[k] = arr[j];
            j += 1;
            k += 1;
        }
    }

    while(j <= high) {
        res[k] = arr[j];
        j += 1;
        k += 1;
    }

    while(i <= mid) {
        res[k] = arr[i];
        i += 1;
        k += 1;
    }

    k = 0;
    for(int i = low; i <= high; i++) {
        arr[i] = res[k];
        k += 1;
    }
}


void mergesort(int arr[], int size, int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        mergesort(arr, size, low, mid);
        mergesort(arr, size, mid + 1, high);
        merge(arr, low, mid, high, size);
    }
}

void p_mergesort(int arr[], int size, int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        #pragma omp parallel sections
        {
            #pragma omp section
                p_mergesort(arr, size, low, mid);
            #pragma omp section
                p_mergesort(arr, size, mid + 1, high);
        }
        merge(arr, low, mid, high, size);
    }
}
void seqMergeSort(int arr[], int size) {
    int copy[size];
    for(int i = 0; i < size; i++) {
        copy[i] = arr[i];
    }

    mergesort(copy, size, 0, size - 1);

    cout<<"MERGE Sort reult: "<<endl;
    for(int i = 0; i < size; i++) {
        cout<<copy[i]<<" ";
    }
    cout<<endl;
}

void parallelMergeSort(int arr[], int size) {
    int copy[size];
    for(int i = 0; i < size; i++) {
        copy[i] = arr[i];
    }

    p_mergesort(copy, size, 0, size - 1);
    cout<<"Parallel Merge Sort Result: "<<endl;
    for(int i = 0; i < size; i++) {
        cout<<copy[i]<<" ";
    }
    cout<<endl;
}

int main() {

    int size;
    int maxEle = 1000;
    cout<<"Enter size of arr: ";
    cin>>size;
    int arr[size];
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % maxEle;
    }
    cout<<"Initial Elements of arr: "<<endl;
    for(int i = 0; i < size; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<endl;

    auto start = chrono::high_resolution_clock::now();
    seqBubble(arr, size);
    auto end = chrono::high_resolution_clock::now();
    cout<<"Execution Time (micros): "<<chrono::duration_cast<chrono::microseconds>(end - start).count()<<endl;
    cout<<endl;


    start = chrono::high_resolution_clock::now();
    seqMergeSort(arr, size);
    end = chrono::high_resolution_clock::now();
    cout<<"Execution Time (micros): "<<chrono::duration_cast<chrono::microseconds>(end - start).count()<<endl;
    cout<<endl;


    start = chrono::high_resolution_clock::now();
    parallelBubble(arr, size);
    end = chrono::high_resolution_clock::now();
    cout<<"Execution Time (micros): "<<chrono::duration_cast<chrono::microseconds>(end - start).count()<<endl;
    cout<<endl;


    start = chrono::high_resolution_clock::now();
    parallelMergeSort(arr, size);
    end = chrono::high_resolution_clock::now();
    cout<<"Execution Time (micros): "<<chrono::duration_cast<chrono::microseconds>(end - start).count()<<endl;


    return 0;
}

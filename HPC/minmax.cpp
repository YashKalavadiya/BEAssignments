#include<bits/stdc++.h>
#include<omp.h>


using namespace std;

void minval(int arr[], int size) {
    int minval = arr[0];

    #pragma omp parallel for reduction(min: minval)
    for(int i = 1; i < size; i++) {
        if(minval > arr[i]) minval = arr[i];
    }
    cout<<"Minimum value: "<<minval<<endl;
}

void maxval(int arr[], int size) {
    int maxval = arr[0];

    #pragma omp parallel for reduction(max: maxval)
    for(int i = 1; i < size; i++) {
        if(maxval < arr[i]) maxval = arr[i];
    }

    cout<<"Max Value: "<<maxval<<endl;
}

int sum(int arr[], int size) {

    int sum = 0;

    #pragma omp parallel for reduction(+ : sum)
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }

    cout<<"Sum of elements: "<<sum<<endl;
    return sum;
}

void avg(int arr[], int size) {
    double avg = (double)sum(arr, size) / size;

    cout<<"Average: "<<avg<<endl;
}

int main() {

    int maxele = 10;
    int size;
    cout<<"Enter arr size: ";
    cin>>size;

    int arr[size];
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % maxele;
    }

    cout<<"Array Elements: "<<endl;
    for(int ele: arr) {
        cout<<ele<<" ";
    }
    cout<<endl;
    minval(arr, size);
    maxval(arr, size);
    sum(arr, size);
    avg(arr, size);

    return 0;
}

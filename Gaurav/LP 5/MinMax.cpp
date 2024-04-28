/*
  Windows does not support user defined reductions.
  This program may not run on MVSC++ compilers for Windows.
  Please use Linux Environment.[You can try using "windows subsystem for linux"]
*/

#include<iostream>
#include<omp.h>
#include<bits/stdc++.h>

using namespace std;

int seqminval(int arr[], int n){
  int minval = arr[0];
    for(int i = 0; i < n; i++){
      if(arr[i] < minval) minval = arr[i];
    }
  return minval;
}

int minval(int arr[], int n){
  int minval = arr[0];
  #pragma omp parallel for reduction(min : minval)
    for(int i = 0; i < n; i++){
      if(arr[i] < minval) minval = arr[i];
    }
  return minval;
}

int maxval(int arr[], int n){
  int maxval = arr[0];
  #pragma omp parallel for reduction(max : maxval)
    for(int i = 0; i < n; i++){
      if(arr[i] > maxval) maxval = arr[i];
    }
  return maxval;
}

int sum(int arr[], int n){
  int sum = 0;
  #pragma omp parallel for reduction(+ : sum)
    for(int i = 0; i < n; i++){
      sum += arr[i];
    }
  return sum;
}

int average(int arr[], int n){
  return (double)sum(arr, n) / n;
}

int main(){
  int n = 5;
  int arr[] = {1,2,3,4,5};

  auto start = chrono::high_resolution_clock::now();
  cout << "The minimum value is: " << seqminval(arr, n) << '\n';
    cout << endl;
    auto end = chrono::high_resolution_clock::now();
    cout << "Time taken: "<< chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

   start = chrono::high_resolution_clock::now();
  cout << "The minimum value is: " << minval(arr, n) << '\n';
    cout << endl;
    end = chrono::high_resolution_clock::now();
    cout << "Time taken: "<< chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

  
  
  
  cout << "The maximum value is: " << maxval(arr, n) << '\n';
  cout << "The summation is: " << sum(arr, n) << '\n';
  cout << "The average is: " << average(arr, n) << '\n';
  return 0;
}
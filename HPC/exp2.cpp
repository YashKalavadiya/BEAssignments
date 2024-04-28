#include <bits/stdc++.h>
#include <chrono>
#include <random>

using namespace std;

void bbl_srt_seq(vector<int> &arr) {
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr.size() - i; j++) {
			if  (arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
			}
		}
	}
	auto end = chrono::high_resolution_clock::now();
	cout << "time required " << chrono::duration_cast<chrono::microseconds>(end - start).count() << endl;
	for (int i = 0; i < 100; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


void bbl_srt_par(vector<int> &arr) {
	auto start = chrono::high_resolution_clock::now();
	for (int i = 0; i < arr.size(); i++) {
		int first = i % 2;
		#pragma omp parallel for default(none),shared(arr, first)
		for (int j = first; j < arr.size() - 1; j+=2) {
			if  (arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
			}
		}
	}
	auto end = chrono::high_resolution_clock::now();
	cout << "time required " << chrono::duration_cast<chrono::microseconds>(end - start).count() << endl; 
	for (int i = 0; i < 100; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

}

void merge(vector<int> &arr, int l, int m, int r) {
	int i = l, j = m + 1;
	vector<int> temp;
	while (i <= m && j <= r) {
		if (arr[i] < arr[j]) {
			temp.push_back(arr[i++]);
		} else {
			temp.push_back(arr[j++]);
		}
	}
	while (i <= m) {
		temp.push_back(arr[i++]);
	}
	while (j <= r) {
		temp.push_back(arr[j++]);
	}

	for (int i = 0; i < temp.size(); i++) {
		arr[i + l] = temp[i];
	}
}

void mergeSort(vector<int> &arr, int l, int r) {
	if (l >= r) {
		return;
	}
	int m = (l + r) / 2;
	mergeSort(arr, l, m);
	mergeSort(arr, m+1, r);
	merge(arr, l, m, r);
}

void parallelMergeSort(vector<int> &arr, int l, int r) {
	if (l >= r) {
		return;
	}
	int m = (l + r) / 2;
	#pragma omp task
	mergeSort(arr, l, m);
	#pragma omp task
	mergeSort(arr, m+1, r);

	#pragma omp taskwait
	merge(arr, l, m, r);
}

int main() {
	int len = 1000000;
	vector<int> a(len);
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(1, 1000000);
	for (int i = 0; i < len; i++) {
		a[i] = dist(gen);
	}

	vector<int> b(a.begin(), a.end());
	vector<int> c(a.begin(), a.end());
	vector<int> d(a.begin(), a.end());

	// bbl_srt_seq(a);
	// bbl_srt_par(b);


	auto start = chrono::high_resolution_clock::now();
	mergeSort(c, 0, len - 1);
	auto end = chrono::high_resolution_clock::now();
	cout << "time required: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << endl;
	for (int i = 0; i < 100; i++) {
		cout << c[i] << " ";
	}
	cout << endl;


	start = chrono::high_resolution_clock::now();
	parallelMergeSort(d, 0, len - 1);
	end = chrono::high_resolution_clock::now();
	cout << "time required: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << endl;
	for (int i = 0; i < 100; i++) {
		cout << c[i] << " ";
	}
	cout << endl;

}

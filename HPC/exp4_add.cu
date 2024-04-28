#include <iostream>
#include <random>
#include <cuda.h>

using namespace std;

__global__ void add(int *a, int *b, int *c, int size) {
	int index = blockIdx.x * blockDim.x + threadIdx.x;
	if (index < size) {
		c[index] = a[index] + b[index];
	}
}


int main() {

	int n;

	cout << "Enter size of vector: ";
	cin >> n;

	int *a = new int[n];
	int *b = new int[n];
	int *c = new int[n];

	cout << "Enter vector 1: " << endl;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << "Enter vector 2: " << endl;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	int *x, *y, *z;

	cudaMalloc(&x, n * sizeof(int));
	cudaMalloc(&y, n * sizeof(int));
	cudaMalloc(&z, n * sizeof(int));

	cudaMemcpy(x, a, n * sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(y, b, n * sizeof(int), cudaMemcpyHostToDevice);
	add<<<n, 1>>>(x, y, z, n);
	cudaMemcpy(c, z, n * sizeof(int), cudaMemcpyDeviceToHost);

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << b[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << c[i] << " ";
	}
	cout << endl;
	delete[] a;
	delete[] b;
	delete[] c;

	cudaFree(x);
	cudaFree(y);
	cudaFree(z);

	return 0;
}

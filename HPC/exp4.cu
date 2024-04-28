#include <iostream>
#include <random>
#include <cuda.h>

using namespace std;

__global__ void mult(int *a, int *b, int *c, int m1_r, int m1_c, int m2_r, int m2_c) {
	int x = blockIdx.x;
	int y = blockIdx.y;
	c[x*m2_c + y] = 0;
	for (int i = 0; i < m1_c; i++) {
		c[x*m2_c + y] += a[m1_c*x + i] * b[m2_c*i + y];
	}
}


int main() {

	int m1_r, m1_c, m2_r, m2_c;

	cout << "Enter row col for matrix 1: ";
	cin >> m1_r >> m1_c;

	cout << "Enter row col for matrix 2: ";
	cin >> m2_r >> m2_c;

	if (m1_c != m2_r) {
		cout << "mat mul not possible" << endl;
		return 0;
	}

	int *a = new int[m1_r * m1_c];
	int *b = new int[m2_r * m2_c];
	int *c = new int[m1_r * m2_c];

	cout << "Enter matrix 1: " << endl;
	for (int i = 0; i < m1_r; i++) {
		for (int j = 0; j < m1_c; j++) {
			cin >> a[i*m1_c + j];
		}
	}

	cout << "Enter matrix 2: " << endl;
	for (int i = 0; i < m2_r; i++) {
		for (int j = 0; j < m2_c; j++) {
			cin >> b[i*m2_c + j];
		}
	}

	int *x, *y, *z;

	cudaMalloc(&x, m1_r * m1_c * sizeof(int));
	cudaMalloc(&y, m2_r * m2_c * sizeof(int));
	cudaMalloc(&z, m1_r * m2_c * sizeof(int));

	cudaMemcpy(x, a, m1_r * m1_c * sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(y, b, m2_r * m2_c * sizeof(int), cudaMemcpyHostToDevice);
	dim3 blocks(m1_r, m2_c);
	mult<<<blocks, 1>>>(x, y, z, m1_r, m1_c, m2_r, m2_c);
	cudaMemcpy(c, z, m1_r * m2_c * sizeof(int), cudaMemcpyDeviceToHost);

	for (int i = 0; i < m1_r * m1_c; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < m2_r * m2_c; i++) {
		cout << b[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < m1_r * m2_c; i++) {
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

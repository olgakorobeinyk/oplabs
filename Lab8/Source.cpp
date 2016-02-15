
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;


int** fillData(int* n) {
	int** matrix = new int*[*n];
	for (int i = 0; i<*n; i++) {
		matrix[i] = new int[*n];
		for (int j = 0; j < *n; j++) {
			matrix[i][j] = rand() - RAND_MAX / 2;
		}
	}
	return matrix;
}

int main()
{
	int n;
	cout << "Enter number of rows in matrix" << endl;
	cin >> n;
	int** matrix = fillData(&n);

	double* sum = new double[n];
	for (int i = 0; i < n; i++) {
		sum[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		if (matrix[i][i] < 0) {
			int j = 0;
			while (matrix[i][j] >= 0) {
				sum[i] += matrix[i][j];
				j++;
			}
		}
		else {
			int j = 0;
			for (; j < n; j++) {
				if (matrix[i][j] > 0) {
					break;
				}
			}
			for (; j < n; j++) {
				sum[i] += matrix[i][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << *(sum + i) << endl;
	}

	delete matrix;
	getchar();
	return 0;
}
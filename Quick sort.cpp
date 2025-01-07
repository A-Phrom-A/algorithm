#include <iostream>
using namespace std;

int Partition(int A[], int l, int r) {
	int p = A[l];
	int i = l;
	int j = r+1;
	
	while (true) {
		do {
			i++;
		} while (A[i] < p);
	
		do {
			j--;
		} while (A[j] > p);
	
		if (i >= j) {
			break;
		}		
	
		swap(A[i], A[j]);
	}
	
	swap(A[l], A[j]);
	
	return j;
}

void QuickSort(int A[], int l, int r) {
	if (l < r) {
		int s = Partition(A, l, r);
		QuickSort(A, l, s-1);
		QuickSort(A, s+1, r);
	}
}

int main() {
	int n;
	cin >> n;
	int A[n];
	
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	
	QuickSort(A, 0, n-1);
	
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
}

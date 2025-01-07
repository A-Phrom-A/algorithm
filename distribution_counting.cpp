#include <iostream>
using namespace std;

int main() {
	int n, l = 100, u = 0;
	cin >> n;
	int S[n];
	
	int A[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		
		if (A[i] < l) {
			l = A[i];
		}
		if (A[i] > u) {
			u = A[i];
		}
	}
	
	int range = u - l + 1;
	
	int D[range];
	for (int i = 0; i < range; i++) {
		D[i] = 0;
	}
	
	for (int i = 0; i < n; i++) {
		D[A[i] - l]++;
	}
	
	for (int i = 1; i < range; i++) {
		D[i] += D[i-1];
	}
	
	for (int i = n-1; i >= 0; i--) {
		int j = A[i] - l;
		S[D[j]-1] = A[i];
		D[j]--;
	}
	
	for (int i = 0; i < n; i++) {
		cout << S[i] << " ";
	}
}

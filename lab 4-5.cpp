#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	int A[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	
	int B[n];
	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (A[i] == B[j]) {
				cout << A[i] << " ";
			}
		}
	}
	cout << endl;
	
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	
	bool found;
	for (int i = 0; i < n; i++) {
		found = false;
		for (int j = 0; j < n; j++) {
			if (B[i] == A[j]) {
				found = true;
				break;
			}
		}
	if (!found) {
		for (int j = 0; j < i; j++) {
			if (B[j] == B[i]) {
				found = true;
				break;
			}
		}
		
	}
	if (!found) {
		cout << B[i] << " ";
	}
	}
}

#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
	
    int A[n];
    
    for (int i = 0; i < n; i++) {
		cin >> A[i];
    }

    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int Sum = 0;
            for (int k = i; k <= j; k++) {
                Sum += A[k];
            }
            if (Sum > maxSum) {
                maxSum = Sum;
            }
        }
    }
	
	cout << maxSum << endl;
    
	
    return 0;
}


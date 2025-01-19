#include <iostream>
#include <algorithm>
#include <cmath> 
using namespace std;

void Search(int A[], int n, int M, int k) {
    sort(A, A + n);
    
    int i = lower_bound(A, A + n, M) - A;

    if (i > 0 && (abs(A[i - 1] - M) < abs(A[i] - M))) {
        i--;
    }

    int left = i - 1;
    int right = i;

    while (right - left - 1 < k) {
        cout << "left: " << left << ", right: " << right << endl;

        if (left >= 0 && (right >= n || abs(A[left] - M) <= abs(A[right] - M))) {
            left--;
        } else {
            right++;
        }
    }

    cout << "Values within range: ";
    for (int i = left + 1; i < right; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    int A[] = {23, 22, 18, 11, 13}; 
    int n = sizeof(A) / sizeof(A[0]); 
    int M = 16; 
    int k = 3;  

    Search(A, n, M, k);

    return 0;
}


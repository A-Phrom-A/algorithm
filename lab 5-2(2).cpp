#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int binarySearchClosest(int A[], int M, int low, int high) {
    if (low > high) {
        return low; 
    }
    int mid = (low + high) / 2;
    if (A[mid] == M) {
        return mid;
    } else if (A[mid] < M) {
        return binarySearchClosest(A, M, mid + 1, high);
    } else {
        return binarySearchClosest(A, M, low, mid - 1);
    }
}

void findKClosest(int A[], int n, int M, int left, int right, int k, int result[]) {
    int count = 0;
    while (count < k) {
        if (left < 0) {
            result[count++] = A[right++];
        } else if (right >= n) {
            result[count++] = A[left--];
        } else if (abs(A[left] - M) <= abs(A[right] - M)) {
            result[count++] = A[left--];
        } else {
            result[count++] = A[right++];
        }
    }
}

void searchDivideAndConquer(int A[], int n, int M, int k) {
    
    sort(A, A + n);

    
    int i = binarySearchClosest(A, M, 0, n - 1);

    
    int result[k];
    findKClosest(A, n, M, i - 1, i, k, result);

    
    cout << "Closest " << k << " values to " << M << ": ";
    for (int j = 0; j < k; j++) {
        cout << result[j] << " ";
    }
    cout << endl;
}

int main() {
    int A[] = {10, 12, 15, 17, 18, 20, 25}; 
    int n = sizeof(A) / sizeof(A[0]);       
    int M = 8;                              
    int k = 2;                              

    
    searchDivideAndConquer(A, n, M, k);

    return 0;
}


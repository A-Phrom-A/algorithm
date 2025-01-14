#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int A[n], B[n];
    
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    sort(A, A + n);
    sort(B, B + n);

    int i = 0, j = 0;
    bool foundIntersection = false;
    cout << "Intersection: ";
    while (i < n && j < n) {
        if (A[i] == B[j]) {
            cout << A[i] << " ";  
            foundIntersection = true;
            i++;
            j++;
        } else if (A[i] < B[j]) {
            i++;  
        } else {
            j++;  
        }
    }
    cout << endl;

    i = 0, j = 0;
    cout << "Union: ";
    while (i < n && j < n) {
        if (A[i] == B[j]) {
            cout << A[i] << " "; 
            i++;
            j++;
        } else if (A[i] < B[j]) {
            cout << A[i] << " ";  
            i++;
        } else {
            cout << B[j] << " ";  
            j++;
        }
    }

    cout << endl;
    return 0;
}


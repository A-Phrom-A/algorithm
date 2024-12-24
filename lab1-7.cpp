#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    
    if (n < 1 || n > 1000 || k < 1 || k > 1000) {
        return 1; 
    }

    int A[n];
    bool found = false; 

    
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (A[i] < -1000 || A[i] > 1000) {
            return 1; 
        }
    }

    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] + A[j] == k) {
                cout << A[i] << " " << A[j] << " "; 
                found = true;
            }
        }
    }

    
    if (!found) {
        cout << -1 << endl;
    }

    return 0;
}


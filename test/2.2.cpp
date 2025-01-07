#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end()); 

    int L = 0, R = n - 1;
    int minD = INT_MAX;

    while (L < R) {
        int sum = A[L] + A[R];

        if (sum == k) {
            minD = min(minD, abs(A[R] - A[L]));
            L++;
            R--;
        } else if (sum < k) {
            L++;
        } else {
            R--;
        }
    }
        cout << minD << endl;
    return 0;
}


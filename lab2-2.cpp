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

    int left = 0, right = n - 1;
    int minDifference = INT_MAX;

    while (left < right) {
        int sum = A[left] + A[right];

        if (sum == k) {
            minDifference = min(minDifference, abs(A[right] - A[left]));
            left++;
            right--;
        } else if (sum < k) {
            left++;
        } else {
            right--;
        }
    }

    if (minDifference == INT_MAX) {
        cout << -1 << endl; 
    } else {
        cout << minDifference << endl;
    }

    return 0;
}


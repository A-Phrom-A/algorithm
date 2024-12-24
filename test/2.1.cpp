#include <iostream>
#include <vector>
using namespace std;


int inter(vector<int>& A, int low, int high, int k, vector<int>& mid_indices) {
    if (low <= high && k >= A[low] && k <= A[high]) {
        int mid = low + ((k - A[low]) * (high - low) / (A[high] - A[low]));
        mid_indices.push_back(mid);

        if (A[mid] == k) {
            return mid;
        }
        if (A[mid] < k) {
            return inter(A, mid + 1, high, k, mid_indices);
        }
        return inter(A, low, mid - 1, k, mid_indices);
    }
    return -1;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<int> mid;
    int result = inter(A, 0, n - 1, k, mid);

    for (size_t i = 0; i < mid.size(); i++) {
        cout << mid[i] << " ";
    }

    if (result == -1) {
        cout << "\n-1";
    }

    return 0;
}


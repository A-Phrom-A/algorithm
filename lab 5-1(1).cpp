#include <iostream>
#include <algorithm>
using namespace std;

int partition(int arr[], int l, int r) {
    int mid = l + (r - l) / 2;

    if (arr[mid] < arr[l]) swap(arr[mid], arr[l]);
    if (arr[r] < arr[l]) swap(arr[r], arr[l]);
    if (arr[r] < arr[mid]) swap(arr[r], arr[mid]);
   
    int pivot = arr[mid];
    swap(arr[mid], arr[r]); 
    int i = l;

    for (int j = l; j < r; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i; 
}

int quickSelect(int arr[], int low, int high, int k) {
    if (low == high) return arr[low];

    int p = partition(arr, low, high);

    if (p == k - 1) return arr[p]; 
    else if (p > k - 1) return quickSelect(arr, low, p - 1, k);
    else return quickSelect(arr, p + 1, high, k);
}

int main() {
    int n;
	int arr[n]; 
	int k;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> k;
    cout << quickSelect(arr, 0, n - 1, k) << endl;
    return 0;
}


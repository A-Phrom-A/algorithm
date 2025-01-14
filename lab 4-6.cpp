#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;  
    
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];  
    }

    sort(A.begin(), A.end());

    for (int i = 0; i < n; i++) {
        cout << A[i];  
    }
    cout << endl;
    
    vector<int> Keep;
    int max_digit = INT_MIN;

    for (int i = 0; i < n; i++) {
        vector<int> digits;
        int num = A[i];

        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }

        for (int j = digits.size() - 1; j >= 0; j--) {
            if (digits[j] > max_digit) {
                max_digit = digits[j];
            }
            Keep.push_back(digits[j]);
        }
    }

    vector<int> count(max_digit + 1, 0);  
    int max_count = 0;

    for (int i = 0; i < Keep.size(); i++) {
        count[Keep[i]]++;
        if (count[Keep[i]] > max_count) {
            max_count = count[Keep[i]];
        }
    }

    for (int i = 0; i <= max_digit; i++) {
        if (count[i] == max_count) {
            cout << i << " "; 
        }
    }
    cout << endl;

    int temp = -1;
    for (int i = 0; i < Keep.size(); i++) {
        if (temp != Keep[i]) {
            temp = Keep[i];
            cout << Keep[i];  
        }
    }
    cout << endl;

    return 0;
}


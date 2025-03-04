#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> node;
int main() {
    int n;
    cin >> n;

    vector<node> A(n);  

  
    for (int i = 0; i < n; i++) {
        cin >> A[i].first >> A[i].second;
    }

   
    vector<int> sumA;
    for (int i = 0; i < n; i++) {
        sumA.push_back(A[i].first);
        sumA.push_back(A[i].second);
    }
    
    sort(sumA.rbegin(), sumA.rend());

   
    int set1 = 0, set2 = 0;
    for (int i = 0; i < sumA.size(); i++) {
        if (set1 <= set2) {
            set1 += sumA[i];  
        } else {
            set2 += sumA[i];
        }
    }

   
    cout << abs(set1 - set2) << endl;

    return 0;
}


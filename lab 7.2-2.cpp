#include <bits/stdc++.h>
using namespace std;

long long SMinSquare(long long M, long long N) {
    long long count = 0;
    while (N > 0) {
        count += M / N;  
        M %= N;          
        swap(M, N);      
    }
    return count;
}

int main() {
    long long m, n;
    cin >> m >> n;
    cout << SMinSquare(max(m, n), min(m, n)) << endl;
}


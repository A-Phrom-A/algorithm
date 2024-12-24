#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    const int MAX = 100000; 
    vector<int> diff(MAX + 2, 0);

    for (int i = 0; i < n; i++) {
        int A,B ;
        cin >> A >> B;
        diff[A] += 1;        
        diff[B + 1] -= 1;      
    }

    int maxU = 0;
    int U = 0;
    int maxA = -1, maxB = -1;

    bool C = false; 

    for (int i = 0; i <= MAX; i++) {
        U += diff[i]; 

        if (U > maxU) {
            maxU = U;
            maxA = i;
            C = true;
        }

        if (U < maxU && C) {
            maxU = i - 1;
            C = false;
        }
    }

    cout << maxA << " " << maxB << " " << maxU << endl;

    return 0;
}


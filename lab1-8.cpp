#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool c = true;
	
	if(n < 1 || n > 1000){
		c = false;
	}
	
	if(c){
    int A[n];
    for (int i = 0; i < n; i++) {
		cin >> A[i];
    }
	
	
	
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int currentSum = 0;
            for (int k = i; k <= j; k++) {
                currentSum += A[k];
            }
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }
    }
	
	if(maxSum == INT_MIN){
		return 0;
	}else{
		cout << maxSum << endl;
	}
    
	}
    return 0;
}


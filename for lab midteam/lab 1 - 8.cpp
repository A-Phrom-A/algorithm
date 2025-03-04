#include <iostream>
using namespace std;


int main() {
    int n;
    
    cin >> n;
    int A[n];
    int x[n] = {0};

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
	int maxV = 0;
	
	for(int i = 0;i < n;i++){
		for(int j = i ;j < n;j++){
			int sumV = 0;
			for(int k = i;k <= j;k++){
				sumV += A[k];
			}
			if(sumV > maxV){
				maxV = sumV;
				
			}
		}
	}
	
	cout << maxV;

    return 0;
}


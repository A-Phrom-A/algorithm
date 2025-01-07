#include <iostream>
#include <climits>
using namespace std;

int main(){
	int n ,x;
	
	cin >> n ;
	cin >> x;
	int A[n];
	for(int i =0;i<n;i++){
		cin >> A[i];
	}
	
	M_Sum = INT_MIN;
	
	for(int i =0;i<n;i++){
		for(int j = i ; j<n ;j++){
			int Sum = 0;
			for(int k = i; k <= j ;k++){
				Sum += A[k];
			}
			if(Sum > M_Sum){
					M_Sum = Sum;
				}
		}
	}
	cout << M_Sum;
	return 0;
}

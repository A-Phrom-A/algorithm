#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k,p;
	cin >> n >> k ;
	
	vector<int> A(1000000,0);
	int B[n] ;
	
	for(int i = 0;i < n;i++){
		cin >> p;
		A[p] +=1;
	}
	
	int j = 0;
	for(int i = 1000000;i > 0;i--){
		while(A[i] > 0){
			B[j++] = i;
			A[i]--;
		}
	}
	float max = 0;
	for(int i = 0;i < k;i++){
		max += B[i];
	}
	
	printf("%.2f", max / k);
	
	return 0;
	
}

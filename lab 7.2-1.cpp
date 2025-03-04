#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> A(n);
	for(int i = 0;i < n;i++){
		cin >> A[i];
	}
	
	sort(A.rbegin(),A.rend());
	
	
	

	
	int R = n-1;
	int L = 0;
	int sum1 = 0,sum2 = 0;
	vector<int> set1(n,-1);
	vector<int> set2(n,-1);
	
	for(int i = 0; i < n;i++){
		
			if(sum1 < sum2){
				sum1 += A[i];
				set1[i] = A[i];
			}else{
				sum2 += A[i];
				set2[i] = A[i];
			}
	}
	
	cout << abs(sum1 - sum2) << "\n";
	for(int i = 0; i < n ;i++){
		if(set1[i] != -1){
			cout << set1[i] << " ";
		}
	}
	cout << "\n";
	for(int i = 0; i < n ;i++){
		if(set2[i] != -1){
			cout << set2[i] << " ";
		}
	}
	
}

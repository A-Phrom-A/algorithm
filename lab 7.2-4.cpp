#include <bits/stdc++.h>
using namespace std;

int main(){
	int m,n,K;
	
	
	cin >> m;
	
	for(int i = 0;i < m;i++){
		cin >> n;
		vector<int> A(n);
		vector<int> B(n);
		for(int j = 0;j < n;j++){
			cin >> A[j];
		}
		for(int j = 0;j < n;j++){
			cin >> B[j];
		}
		cin >> K;
		sort(A.begin(), A.end());     
        sort(B.rbegin(), B.rend());
        bool check = true;
        
		for(int j = 0; j < (n-1) ; j++){
			if((A[i] + B[i]) < K){
				check = false;	
				break;
			}
			
		}
		if(check){
			cout << "YES" << "\n";
		}else{
			cout << "No" << "\n";
		}
	}
}

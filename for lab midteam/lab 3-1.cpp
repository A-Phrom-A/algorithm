#include <bits/stdc++.h>
using namespace std;
int A[10000];


int  D(int l,int r,int k){
	if(l > r){
		return 0;
	}
	
	if(l==r){
		if(A[l] == k){
			return 1;
		}else{
			return 0;
		}
	}else{
		int m = l+(r-l)/3;
		int m2 = l+2*(r-l)/3;
		int L = D(l,m,k);
		int M = D(m+1,m2,k);
		int R = D(m2+1,r,k);
		
		return L+M+R;
		}
	}

int main(){
	  int n, k;
    cin >> n >> k;
    
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    int result = D(0, n - 1, k);  
    
    if (result == 0) {
        cout << -1 << endl;  
    } else {
        cout << result << endl;  
    }
    
    return 0;
	
}

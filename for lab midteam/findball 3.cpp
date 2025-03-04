#include <bits/stdc++.h>
using namespace std;
int A[10000];

int D1(int l,int r){
	int S = r-l+1;
	if(S == 1){
		return l;
	}
	if(S == 2){
		if(A[l] == A[r]){
			return -1;
		}else if(A[l] < A[r]){
			return r;
		}else {
			return l;
		}
	}
	
	if(S == 3 ){
		if(A[l] == A[l+1] && A[l] != A[r]){
			return r;
		}else if(A[l] == A[r] && A[l] != A[l+1]){
			return l+1;
		}else{
			return l;
		}
	}
	
	int S1 = l+(S/3)-1;
	int S2 = S1+(S/3);
	int S3 = S2+(S/3);
	
	int F1 = D1(l,S1);
	int F2 = D1(S1+1,S2);
	int F3 = D1(S2+1,r);
	
	if(A[F1] == A[F2] && A[F1] != A[F3]){
		return F3;
	}else if(A[F1] == A[F3] && A[F1] != A[F2]){
		return F2;
	}else {
		return F1;
	}
}
int main (){
	int n ;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> A[i];
	}
	
	int R = D1(0,n-1);
	cout << R;
}

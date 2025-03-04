#include <iostream>
using namespace std;

int binary (int A[],int x,int l,int r){
	if(r<l){
		return -1;
	}else{
		int m = l+((x-A[l])-(r-l)/(A[r]-A[l]));
		if(A[m] == x){
			return m;
		}else if(A[m] < x){
			return binary(A,x,m+1,r);
		}else{
			return binary(A,x,l,m-1);
		}
	}
	
}

int main() {
	int n , k;
    cin >> n >> k;
    int A[n];

	for(int i = 0;i < n;i++){
		cin >> A[i];
	}
	
	cout << binary(A,k,0,n)+1;
	
    return 0;
}


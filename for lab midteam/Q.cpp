#include<bits/stdc++.h>
using namespace std;

int par(int A[], int l, int r) {
	int p = A[l];
	int i = l;
	int j = r+1;
	
	while (true) {
		do {
			i++;
		} while (i <= r && A[i] < p);
	
		do {
			j--;
		} while (j >= l && A[j] > p);
	
		if (i >= j) {
			break;
		}		
	
		swap(A[i], A[j]);
	}
	
	swap(A[l], A[j]);
	
	return j;
}
int Qs(int A[], int l,int h,int k){
	if(l == h){
		return A[l];
	}
	int P = par(A,l,h);
	if(P == k-1)return A[P];
	else if( P > k-1)return Qs(A,l,P-1,k);
	else return Qs(A,P+1,h,k);
}

int main() {
    int n;
	 
	int k;
    cin >> n;
    int A[n];
    
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cin >> k;
    
    cout << Qs(A, 0, n - 1, k) << endl;
    return 0;
}
/*
void Q(int A[] ,int l ,int h){
    if(l<h){
        int s = Par(A , l , h);
        Q(A,l,s-1);
        Q(A,s+1,h);
    }
    

}*/
/*
int par(int A[],int l ,int r){
	int m = l+(r-l)/2;
	
	if(A[m] < A[l]){
		swap(A[m],A[l]);
	}
	if(A[r] < A[l]){
		swap(A[r],A[l]);
	}
	if(A[r] < A[m]){
		swap(A[r],A[m]);
	}
	
	int P=A[m];
	swap(A[m],A[r]);
	int i = l;
	for(int j = l;j < r;j++){
        if (A[j] < P) {
            swap(A[i], A[j]);
            i++;
        }
	}
	swap(A[i],A[r]);
	return i;
}*/

/*
void Q(int A[] ,int l,int r){
	if(l < r){
		int s = par(A,l,r);
		Q(A,l,s-1);
		Q(A,s+1,r);
	}
}*/

/*
int main(){
    int n = 8;
    int A[] = {16,25,2,54,36,9,12,66};
    Q(A,0,n-1);
    for(int i = 0 ; i < n ; i++){
        cout << A[i] << " ";
    }

    return 0;
}*/


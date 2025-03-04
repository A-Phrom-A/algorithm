#include <bits/stdc++.h>

using namespace std;

int par(int l,int r,int A[]){
	int p = A[l];
	int i = l;
	int j = r;
	while(i < j){
		while(i <= r && A[i] <=p){i++;}
		while(j >= l && A[j] > p){j--;}
		if(i < j){
			swap(A[i],A[j]);
		}
	}
	swap(A[l],A[j]);
	return j;
	
}

int parM(int l,int r,int A[]){
	int m = l +(r-l)/2;
	
	if(A[m] < A[l])swap(A[m],A[l]);
	if(A[r] < A[l])swap(A[r],A[l]);
	if(A[m] < A[r])swap(A[r],A[m]);
	
	int p = A[m];
	swap(A[m],A[r]);
	int i = l;
	for(int j = l;j < r;j++){
		if(A[j] < p){
			swap(A[i],A[j]);
			i++;
		}
	}
	swap(A[i],A[r]);
	return i;
}

void Q(int l,int r,int A[]){
	if(l < r){
		int p = par(l,r,A);
		Q(l,p-1,A);
		Q(p+1,r,A);
	}
}

int Qs(int l,int r,int k ,int A[]){
	if(l == r)return A[l];
	
	int p = parM(l,r,A);
	if(p == k-1)return A[p];
	else if(p > k-1)return Qs(l,p-1,k,A);
	else return Qs(p+1,r,k,A);
}

int main() {
    int A[] = {7, 8, 6, 4, 2, 5, 9, 7, 5, 10, 4, 8, 7, 13, 1, 5, 4, 6};
    int n = sizeof(A) / sizeof(A[0]);
    int k = 5;

   cout << "The " << k << "-th smallest element is: " << Qs(0, n - 1, k, A) << endl;


    Q(0, n - 1, A);

  
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}


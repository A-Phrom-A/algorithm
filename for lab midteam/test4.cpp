#include <bits/stdc++.h>
using namespace std;

int A[100000];  // ???????????????????????????

int par(int l,int r){
	int p =A[l];
	int i = l;
	int j = r;
	while(i < j){
		while(i <= r && A[i] <= p)i++;
		while(j >= l && A[j] > p)j--;
		if(i < j){
			swap(A[i],A[j]);
		}
	}
	swap(A[l],A[j]);
	return j;
}

int parM (int l,int r){
	int m= l+(r-l)/2;
	
	if(A[m] < A[l])swap(A[m],A[l]);
	if(A[r] < A[m])swap(A[r],A[m]);
	if(A[r] < A[l])swap(A[r],A[l]);
	
	int p = A[m];
	swap (A[m],A[p]);
	
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

void Q(int l,int r){
	if(l < r){
		int p = parM(l,r);
		Q(l,p-1);
		Q(p+1,r);
	}
}

int Qs(int l,int r,int k){
	if(l == r){
		return A[l];
	}
	
	int p =parM(l,r);
	if(p == k-1){
		return A[p];
	}else if (p > k-1){
		return Qs(l,p-1,k);
	}else{
		return Qs(p+1,r,k);
	}
}
int main() {
    int A_input[] = {7, 8, 6, 4, 2, 5, 9, 7, 5, 10, 4, 8, 7, 13, 1, 5, 4, 6};
    int n = sizeof(A_input) / sizeof(A_input[0]);
    int k = 5;

    // ?????????????????????? `A`
    copy(A_input, A_input + n, A);

    cout << "The " << k << "-th smallest element is: " << Qs(0, n - 1, k - 1) << endl;

    // ??????????????????
    Q(0, n - 1);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}


#include <bits/stdc++.h>
#include <vector>

using namespace std;

void mg (int l,int m,int r,int A[]){
	int i ,j, k;
	int n1 = m-l+1;
	int n2 = r-m;
	int a[n1],b[n2];
	
	for(i = 0;i < n1;i++){
		a[i] = A[l+i];
	}
	for(j = 0;j <n2;j++){
		b[j] = A[m+1+j];
	}
	
	i = 0;j =0;k =l;
	while(i < n1 && j < n2){
		if(a[i] < b[j]){
			A[k] = a[i];
			i++;
		}else{
			A[k] = b[j];
			j++;
		}
		k++;
	}
	while(i < n1){
		A[k] = a[i];
		i++;k++;
	}
	while(j < n2){
		A[k] = b[j];
		j++;k++;
	}
}

void mgS(int l,int r,int A[]){
	if(l < r){
		int m = l+(r-l)/2;
		mgS(l,m,A);
		mgS(m+1,r,A);
		mg(l,m,r,A);
	}
}

int find (int A[],int k,int n){
	
	int l = 0;
	int r = n-1;
	int minDiff = INT_MAX;
	
	while(l < r){
		int sum = A[l] + A[r];
		
		if(sum == k){
			int diff = abs(A[l]-A[r]);
			if(diff < minDiff){
				minDiff = diff;
			}
			l++;
			r--;
			
		}else if(sum < k){
			l++;
		}else{
			r--;
		}
	}
	
	return minDiff;
	

}

int main() {
	int n ,k ;
	cin >> n >> k;
	 int A[n];
	
	for(int i = 0;i < n;i++){
		cin >> A[i];
	}
	
	mgS(0,n-1,A);
	
	for(int i = 0;i < n;i++){
		cout << A[i];
	}
	cout << "\n";
	
	
	cout << find(A,k,n);
    return 0;
}


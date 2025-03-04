#include <bits/stdc++.h>
using namespace std;

void mg (int l,int m,int r,int A[]){
	int i,j,k;
	int n1 = m-l+1;
	int n2 = r-m;
	int a[n1],b[n2];
	for(i = 0;i < n1;i++){
		a[i] = A[l+i];
	}
	for(j = 0;j < n2;j++){
		b[j] = A[m+1+j];
	}
	i = 0;j = 0;k = l;
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

int main() {
	int n;
	cin >> n;
	int A[n];
	
    for(int p = 0;p<n;p++){
		cin >> A[p] ;
	}

    mgS(0,n-1,A);

	int i = 0;
	int num = 0;
	for(int j = 1;i < n;j++){
		if((A[i] - A[j]) == 0){
			i++;
		}
		else if((A[i] - A[j]) != -1){
			num++;	i++;
		}else{
			i++;
		}
	}
	
	cout << num;

    return 0;
}

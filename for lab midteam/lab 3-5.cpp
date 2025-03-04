#include <bits/stdc++.h>
using namespace std;
vector<int> A(100000,0);
int num = 0;

void mg(int l,int m,int r){
	int n1 = m-l+1;
	int n2 = r-m;
	int a[n1],b[n2];
	
	for(int p = 0;p < n1;p++){
		a[p] = A[l+p];
	}
	for(int p = 0;p < n2;p++){
		b[p] = A[m+1+p];
	}
	int i =0,j=0,k=l;
	while(i < n1 && j < n2){
		if(a[i] <= b[j]){
			A[k] = a[i];
			i++;
		}else{
			A[k] = b[j];
			num += (n1 -i);
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

void mgS(int l,int r){
	if(l >= r){
		return;
	}
	int m = l+(r-l)/2;
	mgS(l,m);
	mgS(m+1,r);
	mg(l,m,r);
}



int main() {
	int n ;
	cin >> n;
	for(int i =0;i < n;i++){
		cin >> A[i];
	}
	mgS(0,n-1);
	cout << num;
	
	
}

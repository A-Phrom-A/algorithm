#include<bits/stdc++.h>
using namespace std;
int A[100000][2];
int status[100000];


void mg(int l,int m,int r){
	int i , j ,k;
	int n1= m-l+1;
	int n2= r-m;
	int a[n1][2],b[n2][2];
	for(int p = 0; p < n1;p++){
		a[p][0] = A[l+p][0];
		a[p][1] = A[l+p][1];
	}
	for(int p = 0;p < n2;p++){
		b[p][0] = A[m+1+p][0];
		b[p][1] = A[m+1+p][1];
	}
	i = 0;j = 0;k = l;
	while(i < n1 && j < n2){
		if(a[i][0] < b[j][0]){
			A[k][0] = a[i][0];
			A[k][1] = a[i][1];
			i++;
		}else{
			A[k][0] = b[j][0];
			A[k][1] = b[j][1];
			j++;
		}
		k++;
	}
	
	while(i < n1){
		A[k][0] = a[i][0];
		A[k][1] = a[i][1];
		i++;k++;
	}
	while(j < n2){
		A[k][0] = b[j][0];
		A[k][1] = b[j][1];
		j++;k++;
	}
}

void mgS(int l,int r){
	if(l < r){
		int m = l+(r-l)/2;
		mgS(l,m);
		mgS(m+1,r);
		mg(l,m,r);
	}
}

void xima(int l,int m,int r){
	int k;
	for(int i = m+1; i <r;i++){
		if(status[i] == 1){
			k = i;
			break;
		}
	}
	for(int i = l;i <= m;i++){
		if(status[i] == 1 && A[i][1] < A[k][1]){
			status[i] =0;
		}
	}
}

void maxima(int l,int r){
	if(l < r){
		int m = l+(r-l)/2;
		maxima(l,m);
		maxima(m+1,r);
		xima(l,m,r);
	}
}

int main(){
	int n;
	cin >> n ;
	for (int i =0;i <n;i++){
		cin >> A[i][0] >> A[i][1];
	}
	mgS(0,n-1);
	for (int i =0;i <n;i++){
		cout <<  A[i][0] << " " << A[i][1];
	}
	cout << "\n";
	
	for (int i =0;i <100000;i++){
		status[i] = 1;
	}
	
	maxima(0,n-1);
	
	for (int i =0;i <n;i++){
		if(status[i] == 1){
			cout <<  A[i][0] << " " << A[i][1] << " |";
		}
	}
	return 0;
	
	
	
}

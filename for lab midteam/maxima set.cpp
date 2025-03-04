#include <bits/stdc++.h>
using namespace std;

int ar[100000][2];
int status[1000000];

void mg(int l,int m, int r);

void mgsort(int l ,int r){
	if(l<r){
		int m = l+(r-l)/2;
		mgsort(l,m);
		mgsort(m+1,r);
		mg(l,m,r);
	}
}

void mg(int l,int m,int r){
	int i,j,k;
	int n1 = m-l+1;
	int n2 = r-m;
	int a[n1][2];int b[n2][2];
	for(int p = 0 ; p < n1 ; p++ ){
		a[p][0] = ar[l+p][0];
		a[p][1] = ar[l+p][1];
	}
	for(int p = 0 ; p < n2 ; p ++ ){
		b[p][0] = ar[m+1+p][0];
		b[p][1] = ar[m+1+p][1];
	}
	i = 0 ;j = 0;k = l;
	while(i < n1 && j < n2){
		if(a[i][0] < b[j][0]){
			ar[k][0] = a[i][0];
			ar[k][1] = a[i][1];
			i++;
		}else{
			ar[k][0] = b[j][0];
			ar[k][1] = b[j][1];
			j++; 
		}
		k++;
	}
	
	while(i < n1){
		ar[k][0] = a[i][0];
		ar[k][1] = a[i][1];
		i++;k++;
	}
	
	while(j < n2 ){
		ar[k][0] = b[j][0];
		ar[k][1] = b[j][1];
		j++;k++;
	}
}

void conq(int l,int m ,int r){
	int k;
	for(int i = m+1 ; i<r;i++){ // find first of right
		if(status[i] == 1){
			k = i;
			break;
		}
	}
	
	for(int i = l;i<=m;i++){
		if(status[i] == 1 && ar[i][1] < ar[k][1]){
			status[i] = 0;
		}
	}
}

int maxima(int l,int r){
	if(l < r){
		int m = l+(r-l)/2;
		maxima(l,m);
		maxima(m+1,r);
		conq(l,m,r);
	}
}

int main(){
	int n;
	cin>>n;
	
	for(int i = 0 ;i<n;i++){
		cin>>ar[i][0]>>ar[i][1];
	}
	mgsort(0,n-1);
	/*for(int i = 0 ; i < n ;i++){
		cout<<ar[i][0]<<ar[i][1]<<" ";
	}*/
	
	for(int i = 0 ; i < 1000000 ;i++){
		status[i] = 1;
	}
	maxima(0,n-1);
	for(int i = 0 ;i< n;i++){
		if(status[i] ==1){
			cout<<ar[i][0]<<ar[i][1]<<" ";
		}
	}
	return 0;
}

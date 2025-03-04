#include<bits/stdc++.h>
using namespace std;

int c[100000];
int ca[100000];
int cb[100000];


int main(){
	int n;
	cin >> n;
	
	int a[n],b[n];
	for(int i = 0;i < n;i++){
		cin >> a[i];
		c[a[i]] += 1;
		ca[a[i]] += 1;
	}
	for(int i = 0;i < n;i++){
		cin >> b[i];
		c[b[i]] += 1;
		cb[b[i]] += 1;
		if(c)
		
	}
	
	for(int i = 0;i < 100000;i++){
		if(ca[i] >0){
			c[i] += 1;
		}
		if(cb[i] > 0){
			c[i] += 1;
		}	
	}
	
	//uni
	for(int i = 0;i < n ;i++){
		if(c[a[i]]==2){
			cout << a[i] << " ";
		}
	}
	cout << "\n";
	
	for(int i = 0;i < n;i++){
		cout << a[i] ;
	}
	for(int i = 0;i < n ;i++){
		if(b[i] != a[i]){
			cout << b[i] << " ";
		}
	}
	return 0;
}

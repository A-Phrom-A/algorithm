#include<bits/stdc++.h>
using namespace std;

int ar[10000];

int main(){
	int n,tmp,maxF=0,maxV = 0,minF = INT_MIN;
	cin >> n;
	
	for(int i = 0; i < n;i++){
		cin >> tmp;
		ar[tmp] += 1;
		if(ar[tmp] > maxF){
			maxF = ar[tmp];
			
		}
		if(tmp > maxV){
			maxV = tmp;
		}
	}
	
	for(int i =0;i < n;i++){
		if(minF > ar[i] && ar[i] > 0){
			minF =ar[i];
		}
	}
	
	cout << maxF-minF;
	

	
	return 0;
}

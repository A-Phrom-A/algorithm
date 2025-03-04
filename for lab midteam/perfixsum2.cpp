#include<bits/stdc++.h>
using namespace std;
vector<int> T(1000000);
int main(){
	int n,k,maxV;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> k;
		T[k] +=1;
	}
	for(int i = 0;i < n;i++){
		cin >> k;
		T[k+1] -= 1;
		if(k > maxV){
			maxV = k;
		}
	}
	
	for(int i = 1;i < maxV;i++){
		T[i] += T[i-1];
	}
	
	int maxT =0,st,et;
	
	for(int i = 0;i <= maxV;i++){
		if(T[i] > maxT){
			maxT = T[i];
			st = i;
			et = i;
		}
		if(T[i] == maxT && i == et+1){
			et = i;
		}  
	}
	
	cout << st << " " << et << " " << maxT;
	
	
	}

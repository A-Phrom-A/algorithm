#include <bits/stdc++.h>
using namespace std;

int T[100000];

int main(){
	int n,maxV=0,k;
	cin >> n;
	for(int i = 0;i <n ;i++){
		cin >> k;
		T[k] += 1;
	}
	for(int i = 0;i <n ;i++){
		cin >> k;
		T[k+1] -= 1;
		if(k > maxV){
			maxV = k;
		}
	}
	
	for(int i =1;i <= maxV;i++){
		T[i] += T[i-1];
	}
	
	int maxT=0,S,E;
	for(int i =0 ; i <= maxV;i++){
		if(T[i] > maxT){
			maxT = T[i];
			S=i;
			E=i;
		}
		if(T[i] == maxT && i == E+1){
			E = i;
			
		}
	}
	cout << S << " " << E << " " << maxT;
 	
	return 0;
}

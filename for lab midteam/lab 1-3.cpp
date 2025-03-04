#include<bits/stdc++.h>
using namespace std;

int timeS[100000];

int main(){
	int n ,maxV,k;
	cin >> n;
	for(int i =0 ;i <n ;i++){
		cin >> k;
		timeS[k] += 1;
	}
	
	for(int i =0 ;i <n ;i++){
		cin >> k;
		timeS[k+1] -=1;
		if(k > maxV){
			maxV = k;
		}
		
	}
	
	for(int i =0;i <= maxV;i++){
		timeS[i] += timeS[i-1];
	}
	
	int maxT = 0,S,E;
	
	for(int i =0;i <= maxV;i++){
		if(timeS[i] > maxT){
			maxT = timeS[i];
			S = i;E = i;
		}
		if(timeS[i] == maxT && i == E+1){
			E = i;
		}
	}
	
	cout << S << " " << E << " " << maxT;
	
	return 0;
}

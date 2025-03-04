#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
	int n,sT,eT;
	cin >> n;
	vector<int> T(1000001,0);
	
	for(int i =0;i < n;i++){
		cin >> sT ;
		T[sT] += 1;	
	}
	
	for(int i =0;i < n;i++){
		cin  >> eT;
		
		T[eT+1] -= 1;		
	}
	
	int S= -1,E = -1,maxT =0,indexT = 0;
	for(int i=0 ;i <= 1000000;i++){
		indexT += T[i];
		if(indexT > maxT){
			maxT = indexT;
			S=i;
			E=i;
		}
		if(indexT == maxT && i == E+1){
			E = i;
		}
	}
	
	cout << S << " " << E << " " << maxT;
}

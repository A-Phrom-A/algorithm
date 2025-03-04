#include<bits/stdc++.h>
using namespace std;

int par(int l,int r,int A[]){
	int p = A[l];
	int i = l;
	int j = r+1;
	
	while(true){
		do{
			i++;
		}while(i <= r && A[i] < p);
		do{
			j--;
		}while(j >= l && A[j] > p);
		if(i > j){
			break;
		}
		swap(A[i],A[j]);
	}
	swap(A[l],A[j]);
	return j;
}

void Q(int l,int r,int A[]){
	if(l < r){
		int P = par(l,r,A);
		Q(l,P-1,A);
		Q(P+1,r,A);
		
	}
}
int main(){
	int A[] = {10,8,6,7,3,3,3,5,4,2,1,9,5,45};
	int n = 12;
	
	Q(0 , n-1 ,A);
	
	for(int i =0;i <n;i++){
		cout << A[i] << " ";
	}
	
	return 0;
}

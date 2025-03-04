#include <iostream>
using namespace std;


void print(int x[],int n,int A[],int y){
	int sumA = 0;
	for(int i = 1; 1 <= n ;i++){
		if(x[i] == 1){
			sumA += A[i];
		}
	
	}
	
		if(sumA == y){
			for(int i = 1; 1 <= n ;i++){
				if(x[i] == 1){
					cout << A[i] << " ";
				}
			}
		}
	
	cout << "\n";
}

void subset(int x[] , int l,int r,int A[], int y){
	if(l == r){
		print(x,r,A,y);
	}else {
		x[l + 1] = 1;
		subset(x,l+1,r,A,y);
		x[l + 1 ] = 0;;
		subset(x,l+1,r,A,y);
	}
}
int main(){
	int n , y;
	cin >> n;
	int A[n];
	int x[n+1] = {0};
	cin >> y;
	
	for(int i = 0;i < n;i++){
		cin >> A[i] ;
	}
	
	subset(x,0,n,A,y);
	
	
}

#include<bits/stdc++.h>
using namespace std;

int minA = INT_MAX;

void print_sol(vector<int> &x, int n, vector<int> &A, vector<int> &B) {
	int sumA = 0;
	int sumB = 0;
	
   for(int i =0;i < n;i++){
   		if(x[i]){
   			sumA += A[i];
   			sumB += B[i];
		   }
		if(!x[i]){
			sumA += B[i];
			sumB += A[i];
		}
   }
   int sumAll = abs(sumA - sumB);
   if(sumAll < minA){
   		minA = sumAll;
   		
   	
   }
   
}

void subset1(vector<int> &x, int l, int r,vector<int> &A,vector<int> &B) {
    if (l == r) {
        print_sol(x, r, A, B);
        //bt
    } else {
        x[l + 1] = 0;
        
        //bt
        subset1(x, l + 1, r, A, B);
        x[l + 1] = 1;
        
        // bt
        subset1(x, l + 1, r, A, B);
    }
}

int main() {
    int n ;           
    cin >> n;
    
    vector<int> A(n);
    vector<int> B(n);
    vector<int> C(n);
    
    
	for(int i =0;i < n ;i++){
		cin >> A[i] >> B[i] ;
		C[i] = A[i];
	}       

    subset1(C, 0, n, A, B);
    
    cout << minA;
	
    return 0;
}

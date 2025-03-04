#include<bits/stdc++.h>
using namespace std;
vector<int> final(1000000,0);
int maxsum = 0;
bool chack = false;
void print_sol(vector<int> &A,vector<int> &y , int n,int target) {
 	int sum = 0;

    for (int i = 0; i < n; i++) {  
        if(A[i]){
        	sum += y[i];
		}
    }
    
    
 
    if(sum > maxsum && sum <= target){
    	maxsum = sum;
    	chack = true;
    	for (int i = 0; i < n; i++) { 
			final[i] = 0; 
        	if(A[i]){
        		
        		final[i] = y[i];

			}
     		
   		 }
	}
    
   
    
   
}

void subset1(vector<int> &x,vector<int> &y, int l, int r,int M) {
    if (l == r) {
        print_sol(x, y, r, M);
    } else {
        x[l ] = 0;
        subset1(x, y, l + 1, r, M);
        x[l ] = 1;
        subset1(x, y, l + 1, r, M);
    }
}

int main(){
	int N,M;
	cin >> N >> M;
	vector<int> A(N);
	vector<int> B(N,0);
	
	for(int i = 0;i < N ;i++){
		cin >> A[i];
		B[i] = A[i];
	}
	
	subset1(A, B, 0, N, M);
	cout << "\n";
	
	if(chack){
		for (int i = 0; i < N; i++) {  
       	if(A[i]){
       		if(final[i] != 0){
       			cout << final[i] << "\n";
			   }
    		

		}
     		
   	}
	}else{
		for(int i = 0;i < 3;i++){
			cout << " 0" << "\n";
		}
	}
	
	
	

}

#include <bits/stdc++.h>
using namespace std;
int A[] = {25,10,9,2,1};
int k = 12;


void print_sol(int x[], int n) {

    
	    for (int i = 1; i <= n; i++) {
	        
			if(x[i] == 1){
	        	cout << A[i-1] << " ";
				
			}
	    }
	
	cout << "\n";
	
    
}

void subset1(int x[], int l, int r,int sum) {
	if (sum == k) {
        print_sol(x, r);
        return;
    } 
	
	if(l == r){
		return;
	}
	if(sum < k) {
        x[l + 1] = 0;
        
        subset1(x, l + 1, r,sum);
        x[l + 1] = 1;
        sum += A[l];
        subset1(x, l + 1, r,sum);
    }else{
    	return;
	}
}

int main() {
    int n = 5;            
    int x[n + 1];        

    subset1(x, 0, n,0);

    return 0;
}

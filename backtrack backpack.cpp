#include <bits/stdc++.h>
using namespace std;

int V[] = {10,20,25,8};
int W[] = {5,3,8,4};

int maxV = 0;
int maxW = 0;


void print_sol(int x[], int n) {
	    for (int i = 1; i <= n; i++) {
			
			if(x[i] == 1){
	        	cout << V[i-1] << " ";

					
			}
	    }
	cout << "maxV"<<maxV << " " << maxW << " ";	
	cout << "\n";
}

void subset1(int x[], int l, int r,int sumV,int sumW) {
	if (l == r && sumW <= 13) {
        
		if(sumV > maxV){
	        	    maxV = sumV;
	                maxW = sumW;
			}
		print_sol(x,r);
		return;
    }		

	if(sumW < 13 ){
	
		
        x[l + 1] = 0;
        subset1(x, l + 1, r,sumV,sumW);
        
		x[l + 1] = 1;
        sumV += V[l];
        sumW += W[l];
        
        subset1(x, l + 1, r,sumV,sumW);
    }else{
    	return;
	}
	

}

int main() {
    int n = 4;            // Number of elements
    int x[n + 1];        // Array to store subset

    subset1(x, 0, n,0,0);

	
    

    return 0;
}

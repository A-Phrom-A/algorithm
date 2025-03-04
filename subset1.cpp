#include <stdio.h>

int V[] = {10,20,25,8};
int W[] = {5,3,8,4};
int A[] = {0,0,0,0};
int maxV = 0;
int maxW = 0;


void print_sol(int x[], int n) {
    int sumV = 0;  
    int sumW = 0;  

    for (int i = 0; i < n; i++) {  
        
		if(x[i] == 1) {
        	
            sumV += V[i];
            sumW += W[i];
        }
        
    }
    
    if(sumV > maxV && sumW <= 13 ){
    	maxV = sumV;
    	maxW = sumW;
    	for (int i = 0; i < n; i++){
    		A[i] = x[i];
		}
    }
    
   
}

void subset1(int x[], int l, int r) {
    if (l == r) {
        print_sol(x, r);
    } else {
        x[l + 1] = 0;
        subset1(x, l + 1, r);
        x[l + 1] = 1;
        subset1(x, l + 1, r);
    }
}

int main() {
    int n = 4;            // Number of elements
    int x[n + 1];        // Array to store subset

    subset1(x, 0, n);
	 printf(" -> maxV: %d, maxW: %d\n", maxV, maxW);
	
	 for (int i = 0; i < n; i++) {
        if (A[i] == 1) {
            printf("%d ", i + 1); 
        }
    }

    return 0;
}

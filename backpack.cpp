#include <stdio.h>

int V[] = {0,25,10,9,2};
int A[] = {0,0,0,0};
int maxV = 0;
bool c = false;


void print_sol(int x[], int n) {
    int sumV = 0;  
      

    for (int i = 1; i <= n; i++) {  
            if(x[i] == 1){
            	sumV += V[i];
			}
//        	printf("%d" , x[i]);
    }
//    printf(" : %d \n",sumV);
    if(sumV == 36  ){
    	maxV = sumV;
//    	printf("555");
    	
    	for (int i = 1; i <= n; i++){
//    		A[i] = x[i];

			if(x[i] == 1){
				printf("%d ",V[i]);
			}
		}
		
		printf("\n");
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
    int n = 4;            
    int x[n + 1];        

    subset1(x, 0, n);
	 printf(" -> maxV: %d \n", maxV);
	
	 for (int i = 0; i < n; i++) {
        if (A[i] == 1) {
            printf("%d ", i + 1); 
        }
    }

    return 0;
}

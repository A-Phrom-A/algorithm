#include <bits/stdc++.h>
using namespace std;

int H ;
int c = 0;


void subset1(int x[], int l, int r,int sum) {
    if(sum == H){
    	c++;
    	
    	return;
	}
	
	
	if (l == r) {
    	return;
        
    } else {
        x[l + 1] = 0;
        subset1(x, l + 1, r,sum);
        x[l + 1] = 1;
        sum += 1;
        subset1(x, l + 1, r,sum);
    }
}

int main() {
    int n ;  
	cin >> n >> H;
    int x[n + 1];        // Array to store subset

    subset1(x, 0, n,0);
	cout << c;
    return 0;
}

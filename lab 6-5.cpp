#include <bits/stdc++.h>
using namespace std;
int maxV = 0;
void print_sol(vector<int> &x, vector<int> &y,int n) {
	int sum = 0;
	
    for (int i = 1; i <= n;i+=2) {  
 
		if(y[i] == 1) {
        	sum += x[i];
        	
        }
        
    }
  
  	if(sum > maxV){
  		for(int i = 1;i <= n;i++){
  			if(y[i] == 1){
  				cout << x[i] << " ";
			  }
		  }
  		maxV = sum;
	  }
    cout << " \n";
}

void subset1(vector<int> &x, vector<int> &y, int l, int r) {
    if (l == r) {
    	
        print_sol(x,y,r);
    } else {
        y[l ] = 0;
        subset1(x, y,l + 1, r);
        
        if(l+1 < r){
        	y[l] = 1;
     	   subset1(x, y,l + 2, r);
		}

    }
}

int main() {
    int n ;     
	cin >> n;       
	vector<int> x(n);  
	
	for(int i =0; i < n ;i++){
		cin >> x[i];
	}
	vector<int> y(n, 0);
	subset1(x, y, 0, n);
	
	cout << maxV;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int num =0;
void print_sol(vector<int> &x,int n) {
	int p =-1;
	bool c = true;
	
    for (int i = x.size(); i > 0; i--) {  
        p++;
		if(x[i] == 1) {
        	cout << p;
        	c = false;
        }
        
    }
    if(c) cout << "0";
    cout << " \n";
}

void subset1(vector<int> &x, int l, int r) {
    if (l == r) {
    	num++;
        print_sol(x,r);
    } else {
        x[l+1 ] = 0;
        subset1(x, l + 1, r);
        
		x[l+1 ] = 1;
        subset1(x, l + 1, r);
    }
}

int main() {
    int n ;     
	cin >> n;       
	vector<int> x(n+1);  
	subset1(x, 0, n);
	
	cout << num;
    return 0;
}


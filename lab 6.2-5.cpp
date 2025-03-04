#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int num=0;

bool check(int x){
	if(x < 2) return false;
	
	for(int i = 2 ;i*i <= x;i++){
		if(x%i == 0)return false;
	}
	return true;
}

void permute(vector<int> &x, int S, int E){
	if(S == E){
		bool C = true;
        for (int i = 0; i < E; i++) {
           		//cout << x[i] << " ";
           		if(!check(x[i ] + x[i + 1])){
           			C = false;
           			break;
				   }
            }
        if(!check(x[0] + x[E])) C=false;
        
        if(C){
        	num++;
		}	
		return;
	}
	
	
	for(int i =S;i <= E;i++){
		swap(x[S],x[i]);
		permute(x,S + 1 ,E);
		swap(x[S],x[i]);
	}
}

int main() {
	int n ;
	cin >> n;
	vector<int> x(n);
	
	for(int i =0 ; i <= n ;i++ ){
		x[i] = i+1;
	}
	
	
	permute(x, 1 ,n-1);
	
	cout << num;
	
	return 0;
}

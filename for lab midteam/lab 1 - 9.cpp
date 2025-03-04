#include<bits/stdc++.h>
using namespace std;

int countv = 0;

void b(int n){
	if(n <= 0){
		return;
	}
	
	if(n%2 == 1){
		countv ++;
		b(n/2);
	}else{
		b(n/2);
	}
	
}



int main(){
	int n;
	cin >> n;
	
	b(n);
	cout << countv;
	return 0;
}

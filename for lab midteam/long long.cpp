#include<bits/stdc++.h>
using namespace std;
//#define ll long long 

long long F( long long n){
	if(n == 1){
		return 1;
	}
	return n*F(n-1);
}
int main(){
	long long n;
	cin >> n;
	
	cout << F(n);
	
	return 0;
}

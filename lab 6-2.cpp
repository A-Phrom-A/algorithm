#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

int num = 0;

void permute(vector<int> &A , vector<int> &B, vector<bool> &use,int x){
if(B.size() == x){
       
		for(int i =0; i < B.size() ;i++){
					cout << B[i] << " "  ;
	
		}
       cout << "\n";
       num++;
		
		return;
	}
	
	for(int i =0;i <A.size() ;i++){
		
		if( !use[i]){
			use[i] = true;
			B.push_back(A[i]);
			permute(A,B,use ,x);
			B.pop_back();
			use[i] = false;
		}

	}
}

int main() {
	int n,x;

	cin >> n;
	cin >> x;
	
	vector<int> A(n);

	for(int i = 0;i < n;i++){
		A[i] = i+1;
	}

	
	sort(A.begin(), A.end());
	
	vector<int> B;
	vector<bool> use(n,false);
	
	permute(A, B ,use ,x);
	
	cout << num;

	return 0;
}

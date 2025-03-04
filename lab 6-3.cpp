#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

int num = 0;

void permute(vector<int> &A , vector<int> &B,int x, int index){
if(B.size() == x){
       
		for(int i =0; i < B.size() ;i++){
					cout << B[i] << " "  ;
	
		}
       cout << "\n";
       num++;
		
		return;
	}
	
	for(int i =index ;i <A.size() ;i++){
		
	
			B.push_back(A[i]);
			permute(A,B , x,i+1);
			B.pop_back();


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

	
	permute(A, B ,x, 0);
	
	cout << num++;

	return 0;
}

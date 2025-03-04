#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



void permute(vector<char> &A , int L, int R){
if(L == R){
       
		for(int i =0; i < A.size() ;i++){
			cout << A[i] << " ";
		}
       cout << "\n";
		
		return;
	}
	
	for(int i =L;i <= R;i++){
		swap(A[L],A[i]);
		permute(A,L + 1 ,R);
		swap(A[L],A[i]);
	}
}

int main() {
	int n;
	char c;
	cin >> n;
	
	vector<char> A(n);

	for(int i = 0 ;i < n;i++){
		cin >> A[i] ;
		
	}
	
	sort(A.begin(), A.end());
	
	permute(A, 0 ,n-1);

	return 0;
}

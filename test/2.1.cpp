#include <iostream>
#include <vector>
using namespace std;

int inter(vector<int>& A, int L,int H,int K,vector<int>& M){
	if(L <= H && k >= A[L] && k <= A[H]){
		int mid = L + ((k -A[L]) * (H - L) / (A[H] - A[L]));
		M.push_back(mid);
		
		if(A[mid] == k){
			return mid;
		}
		if (A[mid] < k){
			return inter(A,mid+1,H,k,M);
		}else{
			return inter(A,L,mid-1,k,M);
		}
	}
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<int> mid;
    int result = inter(A, 0, n - 1, k, mid);

    for (size_t i = 0; i < mid.size(); i++) {
        cout << mid[i] << " ";
    }

    if (result == -1) {
        cout << "\n-1";
    }

    return 0;
}


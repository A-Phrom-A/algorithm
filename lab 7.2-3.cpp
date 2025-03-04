#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> A(n,0);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
	int sum = 0;
	
   for(int i =0; i < n;i+=2){
   	if(A[i] > A[i+1] && A[i] > A[i+2]){
   		if(i < n){
   			sum += A[i];
	   		cout << A[i] << " ";
			A[i] = 0;
		   }
		   
   		
	   }else if(A[i+1] > A[i] && A[i+1] > A[i+2]){
	   	if(i+1 < n){
	   		sum += A[i+1];
		   	cout << A[i+1] << " ";
			A[i+1] = 0;
		   }
		   
	   	
	   }else{
	   	if(i+2 < n){
	   		sum += A[i+2];
		   	cout << A[i+2] << " ";
			A[i+2] = 0;
			i++;
		   }
		   	   	
	   }
   }
   
   cout << "\n" <<sum;
    return 0;
}


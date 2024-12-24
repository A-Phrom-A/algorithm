void shell_Sort (int *A, int n){
	int k,i,j,temp;
	for(k = n/2 ;k >= 0; k/=2){
		
		for(i = k;i < n;i++){
			temp = A[i];
			for(j = i;j >= k && A[j - k] > temp; j -= k){
				A[j] = A[j - k];
				A[j] = temp;
		}
			
			
		}
	
	}
}

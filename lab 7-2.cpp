#include <bits/stdc++.h>
using namespace std;
typedef pair<float,float> node;

int main(){
	int n;
	cin >> n;
	vector<int> V(n);
	
	for(int i =0;i < n;i++){
		cin >> V[i];
	}
	priority_queue< node , vector<node> , greater<node> > pq_pair;
	
	for(int i = 0;i < n;i++){
		pq_pair.push({V[i],i});
	}
	
	float sumV = 0;
	int sum = 0;
	
	while(!pq_pair.empty() ){
			node A = pq_pair.top();
			pq_pair.pop();
			sum += A.first;
			
			sumV += sum;
			//cout << A.first << " ";
	}
	
	float r = sumV/n ;
	
	printf("%.2f" , r)	;
}

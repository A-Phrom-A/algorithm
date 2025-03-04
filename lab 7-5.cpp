#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> node;

int main(){
	int n ;
	cin >> n;
	vector<int> V1(n);
	vector<int> V2(n);
	
	priority_queue< node , vector<node> , greater<node> > pq_pair;
	
	for(int i =0;i < n;i++){
		cin >> V1[i] >> V2[i];
		pq_pair.push({V1[i] , V2[i]});
	}
	int x1,x2;
	cin >> x1 >> x2;
	
	vector<node> V_pair;
	int max_L = x1,max_R = x1;
	
	while(!pq_pair.empty() && max_L < x2){
		int xj = -1;
		
		while(!pq_pair.empty() && pq_pair.top().first <= max_L){
			xj = max(xj,pq_pair.top().second);
			pq_pair.pop();
		}
		
		V_pair.push_back({max_L,xj});
		max_L = xj-1;
	}
	
	cout << V_pair.size() << "\n";
	
	for(int i = 0;i <V_pair.size();i++){
		cout << V_pair[i].first<< " " << V_pair[i].second << "\n";
	}
	
}


#include<bits/stdc++.h>
using namespace std;
//      t_in - t_out / t_in / T_out
typedef pair<int,pair<int,int> > node;
typedef pair<bool,int>  node2;

int main(){
	int n = 10;
	vector<int> T_in = {1,3,0,5,3,5,6,8,8,2};
	vector<int> T_out = {4,5,6,7,8,9,10,11,12,13};
	
	priority_queue<node, vector<node> > pq_pair;
	
	for(int i = 0; i < n ;i++){
		pq_pair.push({ T_out[i]-T_in[i] , {T_in[i] , T_out[i] }});
	}
	
	vector<node2> cpu_keep_use ;
	

	
	while(!pq_pair.empty()){
		node A = pq_pair.top();
		pq_pair.pop();
		cout << A.first << "\t" << A.second.first << "\t" << A.second.second << "\n";

		int S_T = A.second.first;
		int E_T = A.second.second;
		bool running = false;
		
		for(int i = 0; i < cpu_keep_use.size(); i++){
			if(!cpu_keep_use[i].first || cpu_keep_use[i].second <= S_T){
				cpu_keep_use[i].first = true;
				cpu_keep_use[i].second = E_T;
				running = true;
				break;
			}
		}
		
		if(!running){
			cpu_keep_use.push_back({true, E_T});
		}
		
		
	}
	
	cout << cpu_keep_use.size() << "\n";
}

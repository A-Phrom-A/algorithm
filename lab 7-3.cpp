#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> node;

int main(){
	int n;
	cin >> n;
	
	vector<float> T_IN(n);
	vector<float> T_out(n);
	vector<int> M_in(n);
	vector<int> M_out(n);
	
	vector<node> pq_pair;
	
	for(int i =0;i < n;i++){
		cin >> T_IN[i] >> T_out[i];
	
	int H_in = floor( T_IN[i] );
	int m_in = round( (T_IN[i] - H_in)*100 );
	M_in[i] = (H_in * 60) + m_in;
	
	int H_out = floor( T_out[i] );
	int m_out = round( (T_out[i] - H_out)*100 );
	M_out[i] = (H_out * 60) + m_out;
	
	if(M_in[i] < M_out[i]){
		pq_pair.push_back({ M_in[i] , +1 });
		pq_pair.push_back({ M_out[i] , -1});
	}else{
		return -1;
		}
	}
	sort(pq_pair.begin(), pq_pair.end(), [](node a,node b) {
		if(a.first == b.second){
			return a.second < b.second;
		}else{
			return a.first < b.first;
		}
	});
	
	cout << "Train Schedule (in minutes):" << endl;
	int p = 0;
	int max_P = 0;
	
   /* while (!pq_pair.empty()) {
        node A = pq_pair.top();
        pq_pair.pop();
        p += A.second;
        if(p > max_P){
        	max_P = p;
		}
	}*/
	for(int i = 0;i < pq_pair.size();i++){
		p += pq_pair[i].second;
		if(p > max_P){
			max_P = p;
		}
	}
	cout << max_P;

}

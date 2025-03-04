#include<bits/stdc++.h>
using namespace std;
//           avg =  v/W      W           V    index
typedef pair<float,pair<float,pair<float,int> > > node;

int main(){
	int n,K;
	cin >> n >> K;
	
	vector<float> W(n);
	vector<float> V(n);
	
	for(int i = 0;i < n;i++){
		cin >> W[i];	
	}
	for(int i = 0;i < n;i++){
		cin >> V[i];
	}
	
	priority_queue<node , vector<node> > pq_pair3;
	
	for(int i = 0 ; i < n;i++){
		pq_pair3.push( {V[i]/W[i] ,{W[i] , {V[i] , i}}});
	}
	
	float sumV= 0,sumW = 0;
	vector<float> use(n,0);
	
	while(!pq_pair3.empty()){
		node A = pq_pair3.top();
		pq_pair3.pop();
		//cout << A.first << " " << A.second.first << " " << A.second.second.first << "\n";
		if(sumW + A.second.first <= K){
			sumW += A.second.first;
			sumV += A.second.second.first;
			use[A.second.second.second] = 1;
		}else{
			float space_not_use = K - sumW;
			sumV += A.first * space_not_use;
			
			use[A.second.second.second] = space_not_use / A.second.first ;
			//cout << space_not_use << " "<< A.second.first << " " << A.second.second.second << " "<< use[0]<<"\n";
			sumW += space_not_use;
			break;
		}
	}

    for (int i = 0; i < n; i++) {
        printf("%.2f ", use[i]);  
    }
    
    printf("\n%.2f", sumV);  
    return 0;
	
}

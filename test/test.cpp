#include<bits/stdc++.h>

using namespace std;

// first,second
typedef pair<int,int> node;
// duration,<start,end>
typedef pair<int,pair<int,int > > node2;

struct item{
	int W;
	int V;
	double ratio;
	
	item (int v,int w){
		this->V =v;
		this->W = w;
		this->ratio = (double) v/w; 
	}
};

struct compair{
	bool operator()(const item &item1 , const item &item2){
		return item1.ratio < item2.ratio;
	}
};


int main(){
/*	vector<node> v1;
	v1.push_back({0,10});
	cout << v1[0].first << " " << v1.second;*/
/*	
	priority_queue<int,vector<int> ,greater<int>/*sort.first*/ /*>  pq;
	
	
	pq.push(9);
	pq.push(10);
	pq.push(5);
	pq.push(4);
	pq.push(8);
	
	while(!pq.empty()){
		int A = pq.top();
		cout << A << " ";
		pq.pop();
	}
	cout << "\n";
	priority_queue<node, vector<node> , greater<node> > pq_node;
	priority_queue<node2, vector<node2> > pq_node2;
	
	pq_node.push({3,6});
	pq_node.push({9,10});
	
	while(!pq_node.empty()){
		node A = pq_node.top();
		//cout << A.first << " " << A.second << " \n";
		pq_node2.push({A.second - A.first , {A.first,A.second} } );
		pq_node.pop();
	}
	
	while(!pq_node2.empty()){
		node2 A = pq_node2.top();
		//      duration            start                      end
		cout << A.first << " " << A.second.first << " " << A.second.second <<" \n";
	//	pq_node2.push({A.second - A.first , {A.first,A.second} } );
		pq_node2.pop();
	}*/
	
	priority_queue<item , vector<item> , compair > pq_struct;
	pq_struct.push(item(10,20));
	pq_struct.push(item(5,2));
	pq_struct.push(item(20,3));
	
	while(!pq_struct.empty()){
		item A = pq_struct.top();
		pq_struct.pop();
		
		cout << A.ratio << " | " << A.V << " " << A.W << " \n";
	}
}
	

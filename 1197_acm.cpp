#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#define SWS ios_base::sync_with_stdio(false)
#define CT cin.tie(0)
#define CO cout.tie(0)
#define SORT sort(v.begin(),v.end())

using namespace std;

int parent[10001];

class Edge{
	
public:
	int start, end, cost;		
	Edge(int s, int e, int c): start(s),end(e),cost(c){
		
	}
	Edge() {}
	
	bool operator < (const Edge& other) const{
		
		return this->cost < other.cost;
		
	}
	
};

int Find(int x){
	
	if(parent[x]==x) return x;
	
	return parent[x] = Find(parent[x]);
	
}

void Union(int x, int y){
	
	int x1 = Find(x);
	int y1 = Find(y);
	if(x1<y1){
		
		parent[y1] = x1;
		Find(y);
		
	}
	else if(y1<x1){
		
		parent[x1] = y1;
		Find(x);
		
	}
	
}


int main(){
	
	SWS;
	CT;
	CO;
	
	vector<Edge> v;
	
	int V, E;
	int sum = 0;
	cin>>V>>E;
	int start, end, cost;
	
	for(int i=1;i<=V;i++) parent[i] = i;
	
	for(int i=0;i<E;i++){
		
		cin>>start>>end>>cost;
		v.push_back(Edge(start, end, cost));
		
	}
	
	SORT;
	
	for(auto& p:v){
		
		int x = Find(p.start);
		int y = Find(p.end);
		if(x != y){
			
			Union(p.start, p.end);
			sum += p.cost;
			
		}
		
	}
	cout<<sum<<'\n';
	return 0;
}

#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<memory.h>
#define INF 100000000
#define IOS ios_base::sync_with_stdio(0)
#define CI cin.tie(0)

using namespace std;

bool check[20001];
int dist[20001];

class Edge{
	
public:
	int from, to, cost;
	Edge(){}		
	Edge(int f, int t, int c): from(f),to(t),cost(c){}

};


bool comp(Edge& a, Edge& b){

	if(a.cost < b.cost) return true; 
	return false;

}

vector<Edge> v[20001];

int main(){
	
	IOS;
	CI;
	
	memset(check,false,sizeof(check));
	priority_queue<pair<int,int>> q;
	
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
	
		dist[i] = INF;	
		
	} 
	
	int start;
	cin>>start;
	dist[start] = 0;
	q.push(make_pair(-dist[start],start));
	
	for(int i=0;i<m;i++){
		
		int from, to, cost;
		cin>>from>>to>>cost;
		Edge E = Edge(from,to,cost);
		v[from].push_back(E);
		
	}
	
	for(int i=1;i<=n;i++){
		
		sort(v[i].begin(),v[i].end(),comp);
		
	}
	
	
	for(int k=0; k<n-1; k++){
		
		int x = -1;
		
		while(!q.empty()){
			
			auto p = q.top();
			q.pop();
			if(!check[p.second]){
				x = p.second;
				break;
			}
			
		}
		
		check[x] = true;
		
		for(auto &p:v[x]){
			
			int y = p.to;
			if(dist[x] + p.cost < dist[y]){
				
				dist[y] = dist[x] + p.cost;
				q.push(make_pair(-dist[y],y));
				
			}
			
		}
		
	}
	for(int i=1;i<=n;i++){
		if(dist[i] == INF){
			
			cout<<"INF"<<'\n';
			
		}
		else{
			
			cout<<dist[i]<<'\n';
			
		}
	}
	
	return 0;
}

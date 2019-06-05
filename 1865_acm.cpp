#include<iostream>
#include<vector>
#include<memory.h>
#define INF 99999999
#define IOS ios_base::sync_with_stdio(false)

using namespace std;

class Edge{
	
	public:
		int start, end, cost;
		Edge(int s, int e, int c){
			
			start = s;
			end = e;
			cost = c;
		}
};

int dist[501] = {0};

int main(){
	
	IOS;
	
	int TC;
	int n,m,w;
	cin>>TC;
	while(TC--){
		
		cin>>n>>m>>w;
		int start, end, cost;	
		vector<Edge> v;
		
		bool negative = false;
		
		for(int i=0; i<m; i++){
			
			cin>>start>>end>>cost;
			v.push_back(Edge(start,end,cost));
			v.push_back(Edge(end,start,cost));
			
		}
		for(int i=0; i<w; i++){
			
			cin>>start>>end>>cost;
			v.push_back(Edge(start,end,-cost));
			
		}
		
		for(int i=1; i<=n; i++){
			
			dist[i] = INF;
			
		}
		
		dist[1] = 0;
		
		for(int i=1;i<=n;i++){
			
			for(auto &p:v){
				
				int x = p.start;
				int y = p.end;
				int z = p.cost;
				
				if(dist[x] != INF && dist[y] > dist[x] + z){
					
					dist[y] = dist[x] + z;
					if(i==n){
						
						negative = true;
						
					}
						
				}
				
			}
			
		}
		if(negative){
			
			cout<<"YES"<<'\n';
			
		}
		else{
			
			cout<<"NO"<<'\n';
			
		}
		
	}
	
	return 0;
	
}

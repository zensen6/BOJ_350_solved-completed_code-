#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<memory.h>

using namespace std;

bool check[40001];
int depth[40001];
int parent[40001];
int dist[40001]; // parent 로 부터의 cost
 
int LCAdist(int x, int y){
	
	int sum = 0;
	if(depth[x]!=depth[y]){
		
		if(depth[x]>depth[y]){
		
			while(depth[x]!=depth[y]){
				
				sum+=dist[x];
				x = parent[x];
				
			}	
			
		}
		else{
			
			while(depth[x]!=depth[y]){
				
				sum+=dist[y];
				y = parent[y];
				
			}
				
		}
		
	}
	while(x!=y){
		
		sum+=dist[x];
		sum+=dist[y];
		x = parent[x];
		y = parent[y];
		
	}
	return sum;
	
	
} 
 
 
int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N,M;
	int start,end,cost;
	cin>>N;
	vector<pair<int,int>> vp[N+1];
	N--;
	
	while(N--){
		
		cin>>start>>end>>cost;
		vp[start].push_back(make_pair(end,cost));
		vp[end].push_back(make_pair(start,cost));
		
	}
	queue<int> q;
	q.push(1);
	parent[1] = 1;
	check[1] = true;
	depth[1] = 0;
	while(!q.empty()){
		
		int next = q.front(); 	
		q.pop();
		for(auto a: vp[next]){
			
			if(!check[a.first]){
				
				parent[a.first] = next;
				depth[a.first] = depth[next] + 1;
				dist[a.first] = a.second;
				check[a.first] = true;	
				q.push(a.first);		
				
			}
			
		}
		
	}
	
	cin>>M;
	while(M--){
		
		int x,y;
		cin>>x>>y;
		cout<<LCAdist(x,y)<<'\n';
		
	}
	
	return 0;
}

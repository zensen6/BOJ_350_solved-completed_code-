#include<iostream>
#include<memory.h>
#include<algorithm>
#include<vector>

// MST = Prim + Kruscal
// ¿©±â¼± Kruscal 

using namespace std;

int parent[10001];


class Edge{
	public:
	int start;
	int edge;
	int end;
	Edge(int s, int e, int ed):start(s),end(e),edge(ed){}
	Edge(){
	}
	bool operator < (const Edge& other){
		
		return edge< other.edge;
			
	}
	
};

vector<Edge> e;

int Find(int x){
	
	if(parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
	
}

void Union(int x, int y){
	
	int x1 = Find(x);
	int y1 = Find(y);
	if(x1!=y1){
		
		if(x1>y1){
			parent[x1] = y1;
			Find(x);
			
		}
		else{
			parent[y1] = x1;
			Find(y);
		
		}
		
	}
	
}

int main(){


	int V, M;
	int start, edge, end;
	int sum=0;
	cin>>V>>M;
	for(int i=1;i<=V;i++) parent[i] = i;
	for(int i=0;i<M;i++){
		
		cin>>start>>end>>edge;
		Edge j(start, end, edge);
		e.push_back(j);
		
	}
	sort(e.begin(),e.end());
		
	for(int i=0;i<M;i++){
		
		Edge k=e[i];
		int x= Find(k.start);
		int y= Find(k.end);
		if(x!=y){
			
			Union(k.start,k.end);
			sum+=k.edge;
			
		}
		
	}

	
	cout<<sum<<'\n';
	return 0;
	
}

#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>
#include <algorithm>

using namespace std;

bool check[1001] = {false};
vector<int> v[1001];

void dfs(int x){
	
	if(check[x]==false){
		check[x]=true;
		
		cout<<x<<' ';
	}
	if(v[x].size()==0){
		return;
	}
	for(int i=0;i<v[x].size();i++){
		
		int y=v[x][i];
		if(check[y]==false){
			
			dfs(y);
			
		}
		
		
	}
	
	
}

void bfs(int x){
	queue<int> q;
	
	memset(check,0,sizeof(check));
	check[x]=true;

	q.push(x);
	while(!q.empty()){
		
		int node = q.front();
		q.pop();
		cout<<node<<' ';
		for(int i=0;i<v[node].size();i++){
			
			if(check[v[node][i]]==false){
			
				check[v[node][i]]=true;
				//cout<<v[node][i]<<' ';
				q.push(v[node][i]);
			}
		}	
		
	}
	
}


int main(){
	
	int N;
	int M;
	int V;
	int data1;
	int data2;
	cin>>N>>M>>V;
	
	
	int **yes = new int*[N+1];
	for(int i=1;i<=N;i++){
		yes[i]=new int[N+1];
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			
			yes[i][j]=0;
		}
		
	}
	
	
	for(int i=0;i<M;i++){
		
		cin>>data1>>data2;
		if(yes[data1][data2]!=1){
			v[data1].push_back(data2);
			v[data2].push_back(data1);
			yes[data1][data2]=1;
			yes[data2][data1]=1;			
		}

	}
	for(int i=1;i<=N;i++){
		sort(v[i].begin(),v[i].end());
		
	}
	dfs(V);
	cout<<'\n';
	bfs(V);
	cout<<'\n';
	
	return 0;
}

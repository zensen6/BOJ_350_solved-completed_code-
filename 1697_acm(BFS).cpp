#include <iostream>
#include <queue>
#include <vector>

//간선이 가중치가 1인 그래프로 변경가능하며 이걸 BFS로 풀면된다. 

using namespace std;

int N,K;

vector<int> v[200001]; 
const int MAX=100002;

int minprice[200001];
bool visited[200001]={false};

void bfs(int N, int K){
	
	queue<int> q;
	q.push(N);
	visited[N]=true;
	minprice[N]=0;
	while(!q.empty() && minprice[K]==0){
		
		int c = q.front();
		q.pop();
		for(int i=0;i<v[c].size();i++){
			int y=v[c][i];
			if(visited[y]==false){
				
				q.push(y);
				minprice[y] = minprice[c]+1;
				visited[y]=true;
				
				
			}
			
		}
			
	}
	
}


int main(){
	
	cin>>N>>K;
	v[0].push_back(1);
	for(int i=1;i<=MAX;i++){
		
		if(i*2>=MAX){
			v[i].push_back(i+1);
			v[i].push_back(i-1);
		}
		else{
			v[i].push_back(i+1);
			v[i].push_back(i-1);
			v[i].push_back(i*2);		
		}
	
	}
	
	
	bfs(N, K);
	cout<<minprice[K]<<'\n';

	return 0;
	
}

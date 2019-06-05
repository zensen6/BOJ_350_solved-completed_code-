#include <iostream>
#include <vector>
#include <queue>

int vertex[20001];
int edge[200001];
bool visited[20001]={false};


using namespace std;

int cnt=0;

vector<int> v[20000];
vector<int> odd;
vector<int> even;


void push_(int x){
	
	if(cnt%2==0){
		even.push_back_back(x);
	}
	else{
		odd.push_back(x);
	}
}


void bfs(int x){
	
	queue<int> q;
	q.push(x);
	visited[x] = true;
	cnt++;
	push_(x);
	
	while(!q.empty()){
		
		int y=q.front(); 			
		q.pop();
		
		for(int i=0;i<v[y].size();i++){
			
			if(!visited[v[y][i]]){
				
				visited[v[y][i]] = true;
				cnt++;
				push_(v[y][i]);
			}
			
		}
			
		
	}

}


int main(){
	

	int T;
	int V,E;
	int from,to;
	cin>>T;
	while(T--){
		
		v.clear();
		cin>>V>>E;	
		for(int i=0;i<E;i++){
			cin>>from>>to;
			v[from].push_back(to);
			v[to].push_back(from);
		}
		
		
	}
	
	
}

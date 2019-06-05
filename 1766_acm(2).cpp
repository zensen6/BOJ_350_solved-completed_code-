#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int idg[32001] = {0};
	
int main(){
	
	int n, m;
	int from, to;
	vector<int> v[32001];
	cin>>n>>m;
	priority_queue<int> q;
	for(int i=1;i<=m;i++){
		
		cin>>from>>to;
		v[from].push_back(to);
		idg[to]++;
		
	}
	int begin;
	for(begin=1; begin<=n; begin++){
		
		if(!idg[begin]){
			
			q.push(-begin);
			
		}
		
	}
	
	while(!q.empty()){
		
		int x = q.top();
		q.pop();
		x*=-1;
		cout<<x<<' ';
		for(auto &p: v[x]){
			
			idg[p]--;
			if(!idg[p]){
				
				q.push(-p);
				
			}
			
		}
		
	}
	
	return 0;
}

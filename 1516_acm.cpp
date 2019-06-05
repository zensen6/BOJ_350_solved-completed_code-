#include<iostream>
#include<vector>
#include<memory.h>
#include<queue>
using namespace std;

int ind[501];
int price[501];
int d[501];


int main(){
	
	int N;
	cin>>N;
	queue<int>q;
	int x,y,c;
	memset(ind,0,sizeof(ind));
	memset(price,0,sizeof(ind));
	memset(d,0,sizeof(d));
	vector<int> v[501];
	for(int i=1;i<=N;i++){
		
		cin>>x;
		price[i]=x;
		while(1){
			
			cin>>y;
			if(y==-1) break;
			else{
				
				ind[i]++;
				v[y].push_back(i);
			}
			
		}
		
	}
	for(int i=1;i<=N;i++){
		
		if(ind[i]==0){
			
			d[i]=price[i];
			q.push(i);
			
		}
		
	}
	for(int i=1;i<=N;i++){
		
		x=q.front();
		q.pop();
		for(int k=0;k<v[x].size();k++){
			
			y=v[x][k];
			ind[y]--;
			if(price[y]+d[x]>d[y]) d[y]=price[y]+d[x];	
			if(ind[y]==0) q.push(y);
			
		}
		
	}
	for(int i=1;i<=N;i++){
		
		cout<<d[i]<<'\n';
		
	}
	
	
	return 0;
	
}

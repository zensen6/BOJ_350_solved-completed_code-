#include<iostream>
#include<stack>

using namespace std;

int a[1000001];
int parent[1000001];
bool check;

int Find(int x){
	
	if(parent[x] == x) return x;
	int y = Find(parent[x]);
	parent[x] = y;
	return y;
}

void Union(int x, int y){
	
	x= Find(x);
	y= Find(y);
	 
	if(x!=y){
		
		parent[y] = x;	
			
	}
	
}

int main(){
	
	int N,M;
	int x,y;
	cin>>N>>M;
		
	for(int i=0;i<=N;i++) parent[i] = i;
	for(int i=1;i<=M;i++){
		
		cin>>check>>x>>y;
		if(!check){
			
			Union(x,y);
			
		}else{
			
			x= Find(x);
			y= Find(y);
			if(x==y)cout<<"YES"<<'\n';
			else cout<<"NO"<<'\n';
		}
		
	}
	///////////////////////////////////////

	return 0;
}

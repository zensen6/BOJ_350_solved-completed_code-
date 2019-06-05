#include<iostream>
#include<memory.h>
#define IOS ios_base::sync_with_stdio(false)
#define CI cin.tie(0)
#define INF 1000000000
#define FOR1 for(int i=1;i<=N;i++)
#define FOR2 for(int j=1;j<=N;j++)

using namespace std;

int cost[1001][1001]; // 인접리스트 

bool check[1001];
int dist[1001];

int main(){
	
	IOS;
	CI;
	
	memset(check,false,sizeof(check));
	
	int N,M;
	int x,y,z;
	cin>>N;
	cin>>M;
	
	FOR1{
		FOR2{
			
			cost[i][j] = INF;
			
		}
	}
	FOR1 dist[i] = INF;
	
	for(int i=0;i<M;i++){
		
		cin>>x>>y>>z;
		if(cost[x][y] > z){
			
			cost[x][y] = z;
			
		}
		
	}
	int start, target;
	
	cin>>start>>target;
	
	int a = start;
	dist[start] = 0;
	FOR1{
		
		int max0 = INF+1;
		
		FOR2{
			
			if(dist[a] + cost[a][j] < dist[j]){
				
				dist[j] = dist[a] + cost[a][j];
				
			}
			
		}
		
		FOR2{
			
			if(!check[j] && dist[j] < max0){
				
				max0 = dist[j];
				a = j;
				
			}
			
		}
		check[a] = true;
		
	}
	
	cout<<dist[target]<<'\n';
	
	return 0;
}

#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

int map[101][101];
int check[101][101];
int price[101][101];

int dy[4]={-1,0,0,1};
int dx[4]={0,-1,1,0};

bool inrange(int y, int x, int M, int N){
	
	if(y>M || x>N || y<=0 || x<=0) return false;
	else return true;
	
}

void bfs(int M, int N, int y, int x){

	int min=0;
	queue< pair<int,int> > q;
	queue< pair<int,int> > nq;
	q.push(make_pair(y,x));
	check[y][x]=true;
	price[y][x]=0;
	while(check[M][N]==false){
		
		int fy = q.front().first;
		int fx = q.front().second;
		q.pop();
		int ny,nx;
		for(int i=0;i<4;i++){
			
			ny = fy + dy[i];
			nx = fx + dx[i];
			if(inrange(ny,nx,M,N) && !check[ny][nx]){
				
				if(map[ny][nx]==1){
					
					nq.push(make_pair(ny,nx));
					check[ny][nx]=true;
					price[ny][nx]=price[fy][fx]+1;
				}
				else{
					
					q.push(make_pair(ny,nx));
					check[ny][nx]=true;
					price[ny][nx]=price[fy][fx];
					
				}
			}
			
		}
		if(q.empty()){
			
			q = nq;
			nq=queue< pair<int,int> >();
			
		}
		
	}
	
	
}

int main(){
	
	int N,M;
	scanf("%d %d",&N,&M);
	for(int i=1;i<=M;i++){
		for(int j=1;j<=N;j++){
			scanf("%1d",&map[i][j]);
			
		}
	}
	
	bfs(M,N,1,1);
	printf("%d\n",price[M][N]);
	
	return 0;
	
}

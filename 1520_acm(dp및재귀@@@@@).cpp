#include<cstdio>
#include<memory.h>
using namespace std;

int map[500][500] = {0,};
long long d[500][500];


int dx[] = {0,-1,1,0};
int dy[] = {-1,0,0,1};

bool inrange(int y, int x, int n, int m){
	
	if(y<0||x<0||y>=n||x>=m) return false;
	return true;
	
}

long long go(int y, int x, int n, int m){
	
	
	if(y==n-1 && x==m-1){
		return 1;
	}
	if(d[y][x]!=-1) return d[y][x];
	long long &ans=d[y][x];
	ans =0;
	for(int i=0;i<4;i++){
		int ny,nx;
		ny=y+dy[i];
		nx=x+dx[i];
		if(inrange(ny,nx,n,m) && map[ny][nx]<map[y][x]){
			
			ans+=go(ny,nx,n,m);
			
		}
		
	}
	return ans;
	
}


int main(){
	
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			
			scanf("%d",&map[i][j]);
		}
	}
	memset(d,-1,sizeof(d));
	printf("%lld\n",go(0,0,n,m));
	
	return 0;
}

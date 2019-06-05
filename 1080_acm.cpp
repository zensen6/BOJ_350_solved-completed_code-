#include<cstdio>

int A[50][50];
int B[50][50];


int reverse(int N){
	if(N) return 0;
	else return 1;
}

void flip(int y, int x){
	
	for(int i=y; i<y+3;i++){
		for(int j=x;j<x+3;j++){
			
			A[i][j] = reverse(A[i][j]);
			
		}
	}
}


int main(){
	
	int N,M;
	int cnt=0;
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			
			scanf("%1d",&A[i][j]);
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			
			scanf("%1d",&B[i][j]);
		}
	}
	for(int i=0;i<=N-3;i++){
		for(int j=0;j<=M-3;j++){
			
			if(A[i][j]!=B[i][j]){
				
				flip(i,j);	
				cnt++;
				
			} 
			
		}
	}
	bool c =true;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(A[i][j]!=B[i][j]) c=false;
		}
	}
	if(c) printf("%d\n",cnt);
	else printf("%d\n",-1);
	
	return 0;
}

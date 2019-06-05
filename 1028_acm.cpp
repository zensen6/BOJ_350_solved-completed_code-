#include<cstdio>

using namespace std;

int cave[755][755];

int minconvert(int a, int b){
	
	int min = a<=b? a:b;
	return (min+1)/2;
	
}

int main(){
	
	int N,M;
	scanf("%d %d",&N,&M);	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			
			scanf("%1d",&cave[i][j]);
			
		}
		
	}
	int n;
	int i,j;
	bool yes = true;
	bool nodia = true;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			
			if(cave[i][j]==1) nodia = false;
			
		}
		
	}
	if(nodia){
		
		printf("%d\n",0);
		return 0;
		
	}
	
	for(n=minconvert(N,M);n>=1;n--){
	//	

		for(int row=1;row<=N-2*n+2;row++){
			for(int col=1;col<=M-2*n+2;col++){
				yes = true;				
				for(i=row,j=col+n-1;i<=row+n-1,j>=col;i++,j--){
			
					if(cave[i][j]==0) yes=false;
			
			
				}			
				for(i=row+n-1,j=col;i<=row+2*n-2,j<=col+n-1;i++,j++){
			
					if(cave[i][j]==0) yes=false;
			
			
				}	
				for(i=row+2*n-2,j=col+n-1;i>=row+n-1,j<=col+2*n-2;i--,j++){
			
					if(cave[i][j]==0) yes=false;
			
			
				}	
				for(i=row+n-1,j=col+2*n-2;i>=row,j>=col+n-1;i--,j--){
			
					if(cave[i][j]==0) yes=false;
			
			
				}	
				if(yes){
					printf("%d\n",n);
					return 0;
				}		
			}
				
		}
		
		
		
	}
	
}

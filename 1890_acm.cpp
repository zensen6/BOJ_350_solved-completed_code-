#include<iostream>
#include<queue>
using namespace std;

int arr[101][101];
long long path[101][101] = {0};


void dp(int N){    //(1,1)->(N,N)
  	
  	path[1][1] = 1;
	for(int i=2;i<=N;i++){   // 青何 磐(x,1) 
		
		for(int j=1;j<i;j++){
			
			if(i==j+arr[j][1]) path[i][1]+=path[j][1];
			
		}
		
		
	}
	for(int i=2;i<=N;i++){   // 青何 磐(1,x) 
		
		for(int j=1;j<i;j++){
			
			if(i==j+arr[1][j]) path[1][i]+=path[1][j];
			
		}
		
		
	}
	for(int i=2;i<=N;i++){
		for(int j=2;j<=N;j++){
			
			for(int row=1;row<i;row++){
			
				if(i==row+arr[row][j]) path[i][j]+=path[row][j];
			
			}
			for(int col=1;col<j;col++){
					
				if(j==col+arr[i][col]) path[i][j]+=path[i][col];
					
			}
				
				
			
		}
			
	}
	
	
	
}

int main(){
	
	int N;
	cin>>N;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			
			cin>>arr[i][j];
				
		}
		
	}
	dp(N);
	cout<<path[N][N]<<'\n';	
	
	return 0;
}

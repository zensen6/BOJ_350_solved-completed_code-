#include<stdio.h>
#include<stdlib.h>
using namespace std;

int abs0(int a, int b){
	
	if(a>=b) return a-b;
	else return b-a;
}

int main(){
	
	int N,M;
	int min=999999;
	char x;
	int ans0=0;
	int ans1=0;
	int arr0[8][8];
	int arr1[8][8];
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if((i+j)%2==0) arr0[i][j]=0;
			else arr0[i][j]=1;
		}
	}
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if((i+j)%2==1) arr1[i][j]=0;
			else arr1[i][j]=1;
		}
	}
	
	
	
	scanf("%d %d",&N,&M);
	int** arr=(int**)malloc(N*sizeof(int*));
	for(int i=0;i<N;i++){
		arr[i]=(int*)malloc(M*sizeof(int));
	}
	getchar();
	
	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			//scanf("%1c",&x);
			x=getchar();	
			if(x=='W'){
				arr[i][j] = 0;
			}else if(x=='B'){
				arr[i][j] = 1;
			}
		}
		getchar();
				
	}

	for(int i=0;i<=N-8;i++){
		for(int j=0;j<=M-8;j++){
			ans0=0;
			ans1=0;
			for(int k=i;k<i+8;k++){
				for(int l=j;l<j+8;l++){
					
					ans0+=abs0(arr[k][l],arr0[k%8][l%8]);
					ans1+=abs0(arr[k][l],arr1[k%8][l%8]);
					
				}
				
				
			}
			
			if(ans0<=min) min=ans0;
			if(ans1<=min) min=ans1;
		
		}
		
		
	}
	printf("%d\n",min);
	
	/*	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			printf("%d",arr1[i][j]);
		}
		printf("\n");
	}
	*/	
	
	
	return 0;
}

#include<cstdio>

char arr[101][101];

int row=0;
int col=0;

int main(){
	
	int n;
	int dot=0;
	
	char line[101];
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			
			arr[i][j] = getchar();			
			
		}
		getchar();	
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){ // .: dot+=1/ *: dot=0,if dot>=2 row+=1;
			if(arr[i][j]=='.'){
				dot+=1;	
				if(j == n-1){
					
					if(dot>=2) row+=1;
					dot = 0;
					
				}
				
			} 
			else{
				
				if(dot>=2) row+=1;
				dot = 0;
			}	
					
			
		}
	
	}
	dot = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){ // .: dot+=1/ *: dot=0,if dot>=2 row+=1;
			if(arr[j][i]=='.'){
				 dot+=1;	
				if(j == n-1){
					
					if(dot>=2) col+=1;
					dot = 0;
					
				}
				
			}
			else{
				
				if(dot>=2) col+=1;
				dot = 0;
			}	
					
			
		}
	
	}

	printf("%d %d\n",row,col);
	
	return 0;
}

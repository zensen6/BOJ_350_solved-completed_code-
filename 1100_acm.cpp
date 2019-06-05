#include<cstdio>
using namespace std;

int ans=0;

int main(){
	
	char arr[8][8];
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			
			arr[i][j] = getchar();
			
		}
		getchar();
		
	}
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			
			if((i+j)%2==0 && arr[i][j]=='F') ans+=1;
			
		}
			
	}
	
	printf("%d\n",ans);
	return 0;
}

#include"StarWars.h"

int pre;
int num[10];
void go(int N){
	
	int i=1;
	while(N>0){
			
		int now = N % 10; 
		N /= 10;
		int j=0;
		while(j<now){
			
			num[j] += (N*i + i);
			j++;
		}
		
		j = now+1;
		num[now] += N*i + pre + 1;
		
		while(j<10){
			
			num[j] += N*i;
			j++;
		}
		
		pre += now*i;
		num[0] -= i;
		i*=10;
	}
	pre = 0;	
	
}


int main() {

	int N;
	int T;
	
	scanf("%d", &T);
	while(T--){
		
		memset(num,0,sizeof(num));
		scanf("%d", &N);
		go(N);	
		for (int i = 0; i < 10; i++) printf("%d ", num[i]);	
		printf("\n");
		
	}
	
	return 0;
}

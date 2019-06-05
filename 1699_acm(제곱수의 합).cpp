#include<iostream>
#include<math.h>
const int MAX=99999;

using namespace std;


int d[100001];
int check[100001]={0};

int dp(int N){
	
	int min=1;

	d[1]=1;       //1^2~1 ±îÁö j=1
	d[2]=2;       
	d[3]=3;

	for(int i=2;i<=(int)sqrt(N);i++){

		d[i*i]=1;
		check[i*i]=1;
	}
	check[1]=1;
	check[2]=1;
	check[3]=1;
	int i;
	int j;
	for(i=2;i<=N;i++){
		if(check[i]==0){
			min=MAX;
			for(j=1;j<=(int)sqrt(i);j++){	
				if(d[i-(j*j)]+1<=min) min = d[i-(j*j)]+1;
					
			}
			check[i]=1;
			d[i]=min;
		}
	}
	return d[N];
	
}


int main(){
	
	int N;
	cin>>N;
	cout<<dp(N)<<'\n';
	return 0;
	
	
}

#include<iostream>
using namespace std;

int d[41][2] ={0};

long long fibo(int N){
	
	d[0][0] = 1;
	d[0][1] = 0;
	d[1][0] = 0;
	d[1][1] = 1;
	for(int i=2;i<=N;i++){
		
		d[i][0] = d[i-1][0]+d[i-2][0];
		d[i][1] = d[i-1][1]+d[i-2][1];
		
	}
	
}


int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	int N;
	cin>>T;
	fibo(40);
	while(T--){
		cin>>N;
		cout<<d[N][0]<<' '<<d[N][1]<<'\n';
		
	}
	
	return 0;
}

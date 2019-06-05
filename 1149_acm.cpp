#include<iostream>
using namespace std;

int arr[1001][3];
int dd[1001][3];

int mini(int a, int b){
	
	return a<=b? a:b;
	
}


int dp(int N){
	
	int min=9876543;
	for(int i=0;i<3;i++){
		
		dd[0][i] = arr[0][i];
	}
	for(int i=1;i<N;i++){
		for(int j=0;j<3;j++){	
			dd[i][j] = mini(dd[i-1][(j+1)%3],dd[i-1][(j+2)%3])+arr[i][j];
			
		}
	}
	for(int i=0;i<3;i++){
		if(dd[N-1][i]<min) min=dd[N-1][i];
		
	}
	return min;	
}


int main(){

	int N;	
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<3;j++){
			
			cin>>arr[i][j];	
		}
	}
	
	cout<<dp(N)<<'\n';
	
	return 0;
	
}

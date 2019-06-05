#include <iostream>
using namespace std;

int makeit2n(int X){
	
	int k=0;
	while(1<<(k+1)<=X) k++;
	return k;
	
}


int main(){
	
	int X;
	cin>>X;
	int sum=0;
	while(X>=1){
		
		int r=makeit2n(X);
		sum+=X/(1<<r);
		X-=(X/(1<<r))*(1<<r);
		
	}
	cout<<sum<<'\n';
	return 0;
	
}

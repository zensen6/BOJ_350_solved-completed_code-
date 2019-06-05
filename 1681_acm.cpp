#include<iostream>

using namespace std;

bool isin(int N, int L){
	
	while(N>0){
		
		if(L==(N%10)) return true;
		N/=10;
		
	}
	return false;
	
}


int main(){
	
	int N,L;
	cin>>N>>L;
	int cnt=0;
	int i=1;
	while(cnt<N){
		
		
		if(isin(i++,L)) continue;
		else{
			
			cnt++;
		}
		
	}
	
	cout<<i-1<<'\n';

	return 0;
}

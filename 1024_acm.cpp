#include<iostream>

using namespace std;

int main(){
	
	int N,L;
	cin>>N>>L;
	int x,i;
	bool yes = false;
	for(i=L;i<=100;i++){
		
		if((N-(i*i-i)/2)%i==0 && (N-(i*i-i)/2)/i>=0){
			
			x = (N-(i*i-i)/2)/i;
			yes = true;
			break;
			
		}
		
		
	}
	if(!yes){
		
		cout<<-1<<'\n';
		
	}
	else{
		for(int k=x;k<x+i;k++){
			cout<<k<<' ';
		}
		cout<<'\n';
	}

	return 0;
}

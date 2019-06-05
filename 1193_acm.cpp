#include<iostream>

using namespace std;

int main(){
	
	int X;
	cin>>X;
	int i;
	for(i=1;(i+1)*(i+2)/2<=X;i++){}
	//cout<<i<<'\n';
	if(i*(i+1)/2==X){
		
		if(i%2==0){
			
			cout<<i<<'/'<<1<<'\n';
			
		}
		else{
			
			cout<<1<<'/'<<i<<'\n';
			
		}
	}
	else{
		
		int r=i*(i+1)/2;
		if(i%2==0){
			
			cout<<i-(X-r)+2<<'/'<<X-r<<'\n';
			
		}
		else{
			
			cout<<X-r<<'/'<<i-(X-r)+2<<'\n';
			
		}
		
	}
	
	return 0;
}

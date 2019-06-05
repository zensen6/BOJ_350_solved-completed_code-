#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	
	int height,width;
	cin>>height>>width;
	if(height==1){
		
		cout<<1<<'\n';
	}
	else if(height==2){
		
		cout<<min(4,(width+1)/2)<<'\n';
		
	}
	else{
		
		if(width>=7){
			
			cout<<width-2<<'\n';
			
		}
		else{
			
			cout<<min(4,width)<<'\n';
			
		}
		
	}
	
	return 0;
}

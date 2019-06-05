#include<iostream>
using namespace std;

int get(int x1, int y1, int r1, int x2, int y2, int r2){
	
	int dsq = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
	int r = r1+r2;
	if(r*r == dsq) return 1;
	else if(r*r>dsq){
		if((r2-r1)*(r2-r1) == dsq){
			
			if(r2!=r1) return 1;
			else return -1;	
			
		}	
		else if((r2-r1)*(r2-r1) > dsq) return 0;
		else return 2;
		
	}
	else{
		
		return 0;
		
	}
	
}


int main(){
	
	int T;
	cin>>T;
	int x1,y1,r1,x2,y2,r2;
	while(T--){
		
		cin>>x1>>y1>>r1>>x2>>y2>>r2;
		cout<<get(x1,y1,r1,x2,y2,r2)<<'\n';
		
	}
	
	return 0;
}

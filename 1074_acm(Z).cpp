#include <iostream>

using namespace std;

int cnt=0;
int res;

void ZZZ(int N, int y, int x, int r, int c){
	
	if(N==2){
		
		for(int i=y;i<y+N;i++){
			for(int j=x;j<x+N;j++){
				if(i==r && j==c){
					
					res = cnt;
					return;
					
				}
				cnt++;
			}
		}
		return;
	}
	
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			
			ZZZ(N/2,y+i*(N/2),x+j*(N/2),r,c);
			
		}
		
	}
	
	
}


int main(){
	
	int N;
	int r;
	int c;
	
	cin>>N>>r>>c;
	
	int i=1;
	int l=2;
	while(i++<N){	
		l*=2;
	}

	ZZZ(l,0,0,r,c);
	cout<<res;
	return 0;
	
}

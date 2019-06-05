#include<iostream>
#include<math.h>
using namespace std;

int main(){
	
	int T;
	cin>>T;
	int x,y;
	while(T--){
		
		cin>>x>>y;
		int D=y-x;
		int i=(int)sqrt(D);
		
		if(i*i==D) cout<<2*i-1<<'\n';	
		else if(D<=i*(i+1)) cout<<2*i<<'\n';
		else cout<<2*(i+1)-1<<'\n';
		
	}
	
	return 0;
}

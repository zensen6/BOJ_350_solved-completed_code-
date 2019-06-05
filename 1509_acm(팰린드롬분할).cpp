#include<iostream>
#include<memory.h>
using namespace std;

int c[2501][2501];
int d[2501];  //d[i] = i까지 pelandrome의 최소갯수 


int ispelan(int start, int end, string x){
	
	memset(c,0,sizeof(c));
	int min = 2500;
	int len = x.length();
	for(int i=0;i<len; i++) c[i][i] = 1; //substring len==1;
	for(int i=0;i<len-1; i++){
		if(x[i]==x[i+1]) c[i][i+1] = 1;
	}
	for(int k=3;k<=len;k++){  //k=length
		for(int i=0;i<len-k+1;i++){
			if(x[i]==x[i+k-1]){
				
				if(c[i+1][i+k-2]) c[i][i+k-1] = 1;
				else c[i][i+k-1] = 0;
				
			}
			else{
				
				c[i][i+k-1] = 0;
				
			}
			
		}
		
	}
	memset(d,-1,sizeof(d));
	d[0]=1;
	
	for(int i=1;i<len;i++){
		
		for(int j=i;j>=0;j--){
			
			if(c[j][i]){
				
				if(j-1==-1) min=d[i]=1;
				else{
					
					if(d[j-1]+1<=min) min=d[j-1]+1;
					
				}
				
			}
			
		}
		d[i] = min;
		min = 2500;
		
	}
	return d[len-1];
	
	
}


int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string x;
	cin>>x;
	//

	//
	cout<<ispelan(0, x.length(), x)<<'\n';
	
	return 0;
}

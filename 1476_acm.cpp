#include<iostream>

using namespace std;

int arr[16][29][20]={0};

int main(){
	
	
	
	int E;
	int S;
	int M;
	cin>>E>>S>>M;
	int cnt=1;
	int e=1;
	int s=1;
	int m=1;
	
	while(cnt<=7980){
		
		
		if(e==16){
			e%=15;
			
		}
		if(s==29){
			
			s%=28;
		}
		if(m==20){
			
			m%=19;
			
		}
		arr[e++][s++][m++]=cnt++;
		
	}
	cout<<arr[E][S][M]<<endl;
	
	return 0;
	
}

#include<iostream>
using namespace std;

long long building[50];
bool cansee[50][50];
bool already[50][50]={false};

bool cstbuilding(int x, int y, int index, long long H, long long xh, long long yh){
	
	if ((double)H>=((index*(yh-xh)+y*xh-x*yh)/(double)(y-x))) return false;
	else return true;
}


int main(){
	
	int N;
	bool yes = true;
	cin>>N;
	int max=0;
	int cnt=0;
	for(int i=0;i<N;i++) cin>>building[i];
	for(int i=0;i<N-1;i++){
		for(int j=i+1;j<N;j++){
			if(j==i+1){
				cansee[i][j]=cansee[j][i]=true;
				
			}
			else{
				for(int index=i+1;index<j;index++){
				
					if(!cstbuilding(i,j,index,building[index],building[i],building[j])) yes=false;	
				
				}
				if(yes) cansee[i][j]=true;
				cansee[j][i] = cansee[i][j];
				yes = true;				
			}
			
		}
	}
	/*
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(cansee[i][j]) cout<<'1';
			else cout<<'0';
			
		}
		cout<<'\n';
	}
	
	cout<<'\n';
	*/
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(cansee[i][j])cnt++;
		}
		if(cnt>=max)max=cnt;
		cnt=0;
	}
	
	cout<<max<<'\n';
	return 0;
	
}

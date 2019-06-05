#include<iostream>
#include<vector>
using namespace std;

int ans=0;
bool isHan(int X){
	
	vector<int> v;
	bool itishan = true;
	int i=1;
	int d;
	while(i*10<=X){
		
		i*=10;
	}
	while(i>=1){
		
		v.push_back(X/i);
		X-=(X/i)*i;
		i/=10;
		
	}
	if(v.size()>2){
			
		d= v[1]-v[0];
		for(int i=2;i<v.size();i++){
			if(v[i]-v[i-1]!=d) itishan=false;
	
		}
			
	}
	
	return itishan;
}


int main(){
	
	
	int N;
	cin>>N;
	for(int i=1;i<=N;i++){
		
		ans+=isHan(i);
		
	}
	cout<<ans<<'\n';
	return 0;
}

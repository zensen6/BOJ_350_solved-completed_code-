#include<iostream>
#include<memory.h>
#include<vector>

using namespace std;

vector<int> v;
bool c[4000001];

int main(){
	
	memset(c,false,sizeof(c));
	c[1] = true;
	
	int N;	
	cin>>N;
	if(N==1){
		
		cout<<0<<'\n';
		return 0;	
	}
	for(int i=2;i<=N;i++){
		
		for(int j=i*2;j<=N;j+=i){
			
			c[j] = true;
			
		}
		
		
	}

	int count = 0;
	int sum = 0;
	for(int i=1;i<=N;i++){
		
		if(!c[i]) v.push_back(i);
		
	}
	int left = 0 , right = 0;
	sum+=v[left];
	while(left<=right && right<v.size()){
		
		if(sum>N){
			
			sum-=v[left];
			left++;
			
		}
		else{
			
			if(sum==N){
				
				count++;
			}
			right++;
			sum+=v[right];
			
			
		}
		
		
	}
		
	cout<<count<<'\n';
	
	return 0;
}

#include<iostream>
using namespace std;

int makeit(int N){
	
	while(N%10==0){
		
		N/=10;
		
	}
	return N;
	
}

int main(){
	
	int N;
	long long sum=1;
	int cnt=1;
	string str;
	cin>>N;
	
	for(int i=1;i<=N;i++){
		
		sum=(sum*makeit(i));
		while(sum%10==0){
			sum/=10;
			
		}
		sum%=100000;
		
	}
	int i=1;
	while(i*10<=sum){
		
		cnt++;
		i*=10;
	}
	for(int k=0;k<5-cnt;k++){
		
		str+='0';
		
	}
	
	for(int k=5-cnt;k<5;k++){
		
		str+=(sum/i)+'0';
		sum-=(sum/i)*i;
		i/=10;
		
	}
	cout<<str<<'\n';
	return 0;
}

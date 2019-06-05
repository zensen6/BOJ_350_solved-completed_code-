#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

int arr[20];
bool check[10] = {false};
vector<int> v;

long long factorial(int N){
	if (N==0) return 1;
	long long s=1;
	for(int i=1;i<=N;i++){
		s*=i;
	}
	return s;
}

void P1(unsigned long long k, int N){
	
	int cnt=1;
	unsigned long long res;
	int i;
	while(k>=0){
		
		unsigned long long res=factorial((N--)-1);
		cnt = 0;
		for(i=1;i<=9;i++){
			
			while(res*(cnt+1)<k){
				if(check[i]){
					continue;
				}
				else{
					
					cnt++;
				}
			
			
			}
			check[cnt+1]=true;
			v.push_back(cnt+1);
			k-=(cnt+1)*res;
				
		}
		
		
	}
	
	
	
}

unsigned long long P2(int N){
	
	unsigned long long sum=0;
	for(int i=0;i<N;i++){
		
		unsigned long long j=factorial(N-i-1);
		for(int l=1;l<arr[i];l++){
			if(!check[l]){	
				sum+=j;
			}
			
		}
		check[arr[i]] = true;
		
	}
	memset(check,false,sizeof(check));
	return sum+1;
	
}


int main(){
	
	int N;
	int numPro;
	unsigned long long k;
	cin>>N;
	cin>>numPro;
	switch(numPro){
	case 1: cin>>k; 
			P1(k,N);
			for(int i=0;i<v.size();i++) cout<<v[i]<<' ';
			cout<<'\n';
			break;
	case 2: for(int i=0;i<N;i++) cin>>arr[i];
			cout<<P2(N)<<'\n';
			break;
	}

	
	
	return 0;
}

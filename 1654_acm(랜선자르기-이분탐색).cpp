#include <iostream>
#include <vector>
using namespace std;

long long int eachlens[10000];

long long int binarysearch(long long int start, long long int end ,int K, int N){
	
	long long int sum=0;
	long long int max=1;
	vector<long long int> v;
	long long int mid = (start+end)/2;
	while(start<=end){
		
		mid = (start+end)/2;
		
		sum=0;
		for(int i=0;i<K;i++){
			
			sum+=(eachlens[i]/mid);
			
		}
		if(sum>=N){
			
			start = mid+1;
			v.push_back(mid);
			
		}
		else if(sum<N){
			
			end = mid-1;
			
		}
		
	}
	for(unsigned int i=0;i<v.size();i++){
		
		if(max<=v[i]) max=v[i];
		
	}
	return max;
}


int main(){
	
	int K,N;
	int max;
	cin>>K>>N;
	for(int i=0;i<K;i++){
		cin>>eachlens[i];
	}
	max = eachlens[0];
	for(int i=0;i<K;i++){
		if(max<=eachlens[i])max=eachlens[i];
	}
	
	cout<<binarysearch(1,max,K,N)<<'\n';
	return 0;
	
}

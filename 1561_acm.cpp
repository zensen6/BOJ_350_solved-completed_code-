#include<iostream>
#include<vector>

using namespace std;

long long bi(int start, int end, vector<int>& v, int target, int M){
	
	if(target<=M){
		
		return target;
		
	}
	
	while(start<=end){
		long long end_partition = M;
		long long begin_partition = M;
		long long mid = (start+end)/2;
		
		for(int i=0;i<v.size();i++){
			
			end_partition += mid/v[i];
			
		}
		begin_partition = end_partition;
		for(int i=0;i<v.size();i++){
			
			if(mid%v[i]==0) begin_partition--;
			
		}
		
		if(begin_partition > target){
			
			end = mid-1;
			
		}
		else if(end_partition < target){
			
			start = mid+1;		
		}
		else{
			//cout<<begin_partition<<end_partition<<'\n';
			int i;
			for(i=0;i<v.size();i++){
				
				if(begin_partition==target) break;
				if(mid%v[i]==0){
					
					begin_partition++;
				}
				
			}
			return i;
			
			
		}
	
	}
	

}


int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	long long L = 2000000000LL * 300000LL;
	vector<int> v;
	int N,M;
	int max = 0;
	long long sum=0;
	int x;
	cin>>N>>M;
	for(int i=0;i<M;i++){
		cin>>x;
		v.push_back(x);
	}
	int res = bi(0,L,v,N,M);
	cout<<res<<'\n';

	
	return 0;
}

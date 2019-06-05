#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int arr[505];
vector<int> v;
bool match(vector<int>&v, int N, int count){
	
	int last = v.back();
	
	if(count <=0 || N<=0) return false;   // impossible 
	
	if(N>=1 && N<=last && count==1){  //success
		v.push_back(N);
		return true;
	}
	
	for(int i=last;i>=1;i--){
		
		v.push_back(i);
		if(match(v,N-i,count-1)) break;
		v.pop_back();                               //재귀방법은 시간지체가 심하다. 
	}
	
	
}

int main(){
	
	int N,M,K;
	cin>>N>>M>>K;
	int sum=1;
	if(N<M+K-1 || N>M*K) cout<<-1<<'\n';
	else{
		
		for(int i=1;i<=N;i++) arr[i] = i;
		v.push_back(K);
		match(v,N-K,M-1);
		/////////
		for(int i=0;i<v.size();i++) cout<<v[i]<<' ';



		cout<<'\n';
		for(int i=0;i<v.size();i++){
			
			reverse(arr+sum,arr+sum+v[i]);
			sum+=v[i];
		}
		for(int i=1;i<=N;i++) cout<<arr[i]<<' ';
		
		
	}
	
	
	return 0;
}

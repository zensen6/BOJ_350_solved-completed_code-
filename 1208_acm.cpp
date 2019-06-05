#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int arr[40];

void go(int index, int len, vector<int> &v, int sum){
	if(index==len){
		v.push_back(sum);	
		return;
	} 
	go(index+1,len,v,sum+arr[index]);
	go(index+1,len,v,sum);
}

/*
bool binarysearch(int start, int end, int target, vector<int> &v){
	
	
	while(start<=end){
		
		int mid = (start+end)/2;
		if(target<v[mid]){
			
			end = mid-1;
			
		}
		else if(target>v[mid]){
			
			start = mid+1;
		}
		else{
			
			return true;
			
		}
		
	}
	return false;
	
	
}
*/
int main(){
	vector<int> v1;
	vector<int> v2;	

	int count = 0;
	int tmp;
	int N,S;
	long long ans=0;
	cin>>N>>S;
	for(int i=0;i<N;i++){
		
		cin>>arr[i];
		
	}
	int mid = N/2;
	
	go(0,mid,v1,0);
	go(mid,N,v2,0);
	
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
//
	for(int i=0;i<v1.size();i++)cout<<v1[i]<<' ';
	cout<<'\n';
	for(int i=0;i<v2.size();i++)cout<<v2[i]<<' ';
	cout<<'\n';
//

	for(int i=0;i<v1.size();i++){
		
		if(binarysearch(0,v2.size()-1,S-v1[i],v2)){
			
			ans+=1;
			
		}	
		
	}
	if(S==0) ans--;

	cout<<ans<<'\n';
	return 0;
}

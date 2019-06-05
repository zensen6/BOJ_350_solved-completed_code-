#include<iostream>
#include<algorithm>
using namespace std;

int arr[100000];

int main(){
	
	int n,s;
	int sum=0;
	cin>>n>>s;
	for(int i=0;i<n;i++){
		
		cin>>arr[i];
	}
	int minimum = 100001; 
	int left=0,right=0;
	sum+=arr[0];
	while(left<=right && right<n){
		
		if(sum>=s){
			
			minimum = min(minimum,right-left+1);
			sum-=arr[left];
			left++;
			
		}
		else{
			
			right++;
			sum+=arr[right];
			
		}
		
	}
	if(minimum==100001){
		
		cout<<0<<'\n';
	}
	else{
		
		cout<<minimum<<'\n';	
	}
	
	
	return 0;
	
}

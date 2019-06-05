#include<iostream>
#include<memory.h>
using namespace std;

int arr[100];
bool C[2000001];

int main(){
	memset(C,false,sizeof(C));
	int n,m;
	int count=0;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++){
		for(int j=arr[i];j<=m;j+=arr[i]){
			
			if(!C[j]) C[j]=true;
			
		}
		
		
	}
	for(int i=1;i<=m;i++){
		if(C[i]) count++;
		
	}
	cout<<count<<'\n';
	return 0;
	
}

#include<iostream>
#include<vector>

using namespace std;

int arr[1000];

int main(){
	
	vector<int> v;
	int n;
	cin>>n;
	int max = 0;
	int index = 0;
	int cnt = 0;
	bool other = false;
	for(int i=0;i<n;i++){
		cin>>arr[i];	
		if(arr[i]>=max){
			max = arr[i];	
			index = i;
		} 
	} 
	if(n==1) cout<<0<<'\n';
	else{
		
		for(int i=1;i<n;i++){
			
			if(arr[i]>=arr[0]) other=true;
			
		}
		if(!other) cout<<0<<'\n'; 
		else{
			while(arr[0]<=max){
		
				arr[0]++;
				arr[index]--;
				cnt++;
				max=0;
				for(int i=1;i<n;i++){
			
					if(arr[i]>max){
						max = arr[i];	
						index = i;
					} 
	
				}
				if(arr[0]>max) break;
		
			}
			cout<<cnt<<'\n';	
			
		}
		
	}

	return 0;
}

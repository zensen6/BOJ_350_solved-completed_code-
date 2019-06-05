#include<iostream>
#include<vector>
#include<algorithm>

const int SIX=6;

using namespace std;

int arr[50][2];

int main(){
	
	int min = 987654321;
	int N,M;
	cin>>N>>M;
	vector<int> v6;
	vector<int> v1;
	for(int i=0;i<M;i++){
		
		cin>>arr[i][0]>>arr[i][1];
		v6.push_back(arr[i][0]);
		v1.push_back(arr[i][1]);
		
	}
	sort(v6.begin(),v6.end());
	sort(v1.begin(),v1.end());
	
	for(int k=0;k<=N;k++){
		for(int l=0;l<=N;l++){
			if(k*SIX+l>=N && k*v6[0]+l*v1[0]<=min){
				
				min = k*v6[0]+l*v1[0];
			}	
		}
	}
		
	
	cout<<min<<'\n';
	
	return 0;
}

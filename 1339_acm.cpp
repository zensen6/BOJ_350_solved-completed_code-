#include<iostream>
#include<vector>
#include<cstdlib>
#include<memory.h>
#include<cstring>

using namespace std;

bool check[10];
int alpha[26] = {0};

int arr[10] = {0};

vector<string> v;

long long max0 = 0;

void calc(){
	
	long long sum = 0;
	for(auto x:v){
		
		for(int i=0;i<x.length();i++){
			
			x[i] = (char)(arr[alpha[x[i]-'A']]+'0');
			
		}
		//cout<<x<<'\n';
		sum+=stoll(x);
		
	}
	if(sum > max0){
		
		max0 = sum;
		
	}
	
	
}

void permu(int index, int cnt){
	
	if(index==cnt){
		
		calc();
		
		return;
	}
	for(int i=9-cnt+1;i<=9;i++){
		
		if(!check[i]){
			
			arr[index] = i; 
			check[i] = true;
			permu(index+1,cnt);
			check[i] = false;
				
		}
		
	}
	
}

int main(){
	for(int i=0;i<26;i++) alpha[i] = -1;
	memset(check,false,sizeof(check));

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int n;
	string x;
	int cnt = 0;
	cin>>n;
	
	for(int i=0;i<n;i++){
		
		cin>>x;
		v.push_back(x);
		for(auto k:x){
			
			if(alpha[k-'A']==-1){
				
				alpha[k-'A'] = cnt++;		
			}
		}
	}
	
	permu(0,cnt);
	cout<<max0<<'\n';
	return 0;
}

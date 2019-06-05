#include<iostream>
#include<memory.h>

using namespace std;

bool check[26];

int main(){
	
	int n;
	cin>>n;
	string x[100];
	for(int i=0;i<n;i++){
		
		cin>>x[i];
		
	}
	int cnt = 0;
	for(int i=0;i<n;i++){
		memset(check,false,sizeof(check));
		bool yes = true;
		check[x[i][0]-'a'] = true;
		for(int j=1;j<x[i].length();j++){
				
			if(check[x[i][j]-'a'] && x[i][j-1]!=x[i][j]) yes = false;
			check[x[i][j]-'a'] = true;
			
		}	
		if(yes) cnt++;
	}
	cout<<cnt<<'\n';
	return 0;
}

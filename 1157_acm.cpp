#include<iostream>
#include<cstring>
#include<vector>
#include<memory.h>
#include<algorithm>
using namespace std;

bool comp(pair<char,int> &a, pair<char, int> &b){
	
	if(a.second>b.second) return true;
	else return false;
}

int main(){
	
	int a[26];
	memset(a,0,sizeof(a));
	string x;
	vector<pair<char,int>> v;
	cin>>x;
	for(auto i:x){
		
		if(i>='a'&& i<='z') a[i-'a']++;
		else a[i-'A']++;
		
	}
	for(int i=0;i<26;i++){
		
		v.push_back(make_pair((char)('A'+i),a[i]));
		
	}
	sort(v.begin(),v.end(),comp);
	
	if(x.length()>1){
		if(v[0].second==v[1].second){
			cout<<'?'<<'\n';
		
		}
		else{
			cout<<v[0].first<<'\n';
		
		}			
		
		
	}
	else{
		cout<<v[0].first<<'\n';
	
	}
	return 0;
}

#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	
	string x;
	int n,m;
	cin>>n>>m;
	set<string> s;
	vector<string> a;
	for(int i=0;i<n;i++){
		cin>>x;
		s.insert(x);
	}
	for(int i=0;i<m;i++){
		cin>>x;
		if(s.count(x)){
			
			a.push_back(x);

		}
		
		
	}
	
	sort(a.begin(),a.end());
	cout<<a.size()<<'\n'; 
	for(int i=0;i<a.size();i++) cout<<a[i]<<'\n';
	
	return 0;
}

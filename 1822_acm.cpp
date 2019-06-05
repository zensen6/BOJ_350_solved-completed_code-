#include<iostream>
#include<set>

using namespace std;

set<int> s;


int main(){
	
	int na, nb,x;
	cin>>na>>nb;
	int cnt = 0;
	for(int i=0;i<na;i++){
		
		cin>>x;
		s.insert(x);
		
	}

	for(int i=0;i<nb;i++){
		
		cin>>x;
		auto it = s.find(x);
		if(it==s.end()) continue;
		else s.erase(it);
		
	}
	
	cout<<s.size()<<'\n';
	for(auto a:s){
		cout<<a<<' ';
		
	}


	return 0;
}

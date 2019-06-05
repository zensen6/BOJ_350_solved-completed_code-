#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int main(){
	
	int n;
	cin>>n;
	string x;
	int i,j;
	string news="";
	bool all=true;
	vector<string> v;
	
	for(int i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
		
	}

	for(j=0;j<v[0].length();j++){
		all = true;	
		for(i=0;i<v.size()-1;i++){
			
			if(v[i][j]!=v[i+1][j]) all=false;
			
		}
		if(all) news+=v[0][j];
		else news+="?";
	}
	
	
	cout<<news<<'\n';
	return 0;
	
}

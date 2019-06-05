#include<iostream>
#include<vector>

using namespace std;

vector<int> v[101];

int main(){
	
	int T;
	cin>>T;
	int a; int b;
	
	while(T--){
		
		cin>>a>>b;
		int r=1;
		for(int i=1;i<=b;i++){
			
			int res = (r*(a%10))%10;	
			if(!v[a].empty() && res==v[a][0]) break;
			if(res == 0){
				res=10;
			}
			v[a].push_back(res);
			r=r*(a%10);
			r%=10;
			
		}	
		int k= b%v[a].size() ==0? v[a].size()-1:b%v[a].size()-1;
		cout<<v[a][k]<<'\n';
		
	}
	return 0;
	
}

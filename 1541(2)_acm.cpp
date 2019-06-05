#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main(){
	
	string x;
	cin>>x;
	int ans = 0;
	int num = 0;
	vector<int> plus;
	vector<int> minus;
	char save = '+';
	for(auto i:x){
		
		if(i>='0' && i<='9'){
			num*=10;
			num+=(i-'0');	
		}
		else{
			

			if(save=='+') plus.push_back(num);
			else minus.push_back(num);
			if(i=='-') save='-';	
			num = 0;
			
		}
		
	}
	if(save=='+') plus.push_back(num);
	else minus.push_back(num);
	for(auto i:plus) ans+=i;
	for(auto i:minus) ans-=i;
	cout<<ans<<'\n';
	return 0;
}

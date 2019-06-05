#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
bool comp(int a, int b){
	
	return a>=b;
	
}
*/
int main(){
	
	int N;
	int ans=0;
	int zero=0;
	vector<int> plus;
	vector<int> minus;
	
	 
	cin>>N;
	int x;
	for(int i=0;i<N;i++){
		
		cin>>x;
		if(x==1) ans+=1;
		else if(x<0) minus.push_back(x);
		else if(x>0) plus.push_back(x);
		else zero+=1;
	}
	sort(plus.begin(),plus.end());
	reverse(plus.begin(),plus.end());  //comp넣은역순으로했더니 런타임에러가떴다. 
	sort(minus.begin(),minus.end());
	if(plus.size()%2==1){
		
		plus.push_back(1);
		
	}
	if(minus.size()%2==1){
		
		minus.push_back(zero==0? 1:0);
		
	}
	for(int i=0;i<plus.size();i+=2){
		
		ans+=plus[i]*plus[i+1];
	}
	for(int i=0;i<minus.size();i+=2){
		
		ans+=minus[i]*minus[i+1];
		
	}
	
	cout<<ans<<'\n';
	return 0;
}

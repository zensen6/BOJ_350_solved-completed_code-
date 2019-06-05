#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(int a, int b){
	
	return a<=b;

}


int main(){
	
	int na;
	int nb;
	cin>>na>>nb;
	int x;
	vector<int> A;
	vector<int> C;
	for(int i=0;i<na;i++){
		
		cin>>x;
		A.push_back(x);
		
	}
	for(int i=0;i<nb;i++){
		
		cin>>x;
		A.push_back(x);
		
	}
	sort(A.begin(),A.end(),comp);
	
	for(int i=0;i<A.size();i++){
		
		if(i!=0 && A[i]==A[i-1]){
			continue;
			
		}
		else{
			
			C.push_back(A[i]);
			
		}
	}
	int res = na+nb-2*(na+nb-C.size());
	cout<<res;
	return 0;
}

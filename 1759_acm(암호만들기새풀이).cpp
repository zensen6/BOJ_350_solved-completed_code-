#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char arr[15];

bool isalpha(char c){
	
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return true;
	return false;
	
}


bool check(string pass){
	
	int A=0;
	int C=0;
	for(int i=0;i<pass.length();i++){
		
		if(isalpha(pass[i])) A++;
		else C++;
		
	}
	if(A>=1 && C>=2) return true;
	else return false;

}

void go(int n, vector<char>& alpha, string password, int i){
	
	if(password.length()==n){   //correct
		
		if(check(password)){
			
			cout<<password<<'\n';
		}
		return;
	}
	if(i>=alpha.size()) return; //impossible
	go(n,alpha,password+alpha[i],i+1);
	go(n,alpha,password,i+1);
	
}

int main(){
	
	int L,C;
	cin>>L>>C;
	vector<char> v;
	for(int i=0;i<C;i++){
		cin>>arr[i];	
	}
	sort(arr,arr+C);
	for(int i=0;i<C;i++){
		
		v.push_back(arr[i]);	
	}
	
	string str="";
	go(L,v,str,0);
	
	
}

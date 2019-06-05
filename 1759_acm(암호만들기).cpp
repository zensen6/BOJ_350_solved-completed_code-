#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char arr[15];
char al[5];

bool isalpha(char c){
	
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return true;
	return false;
}

bool check(vector<char> &somun){
	
	int A=0;
	int C=0;
	for(int i=0;i<somun.size();i++){
		
		if(isalpha(somun[i])){
			A++;
		}
		else C++;
		
	}
	if(A>=1 && C>=2) return true;
	else return false;
	
}

void go(int L, int C, vector<char>& v, int count, vector<char>& somun){
	
	if(count==L){
		if(!check(somun)) return;
		for(int i=0;i<L;i++) {
			cout<<v[i];	
		}
		cout<<'\n';
		return;
	}
	
	int smallest=0;
	if(!v.empty()){	
		char target = v.back();
		for(smallest=0;smallest<C;smallest++){
			if(arr[smallest]==target) break;
		}
		smallest+=1;
	}
	
	for(int i=smallest;i<C;i++){
		int Yes=0;
		if(isalpha(arr[i])) {
			somun.push_back(arr[i]);
			Yes=1;
		}
		v.push_back(arr[i]);
		go(L,C,v,count+1,somun);
		v.pop_back();
		if(Yes==1){
			somun.pop_back();
			Yes=0;
		}
		
	}
	
	
}


int main(){
	
	vector<char> v;
	vector<char> somun;
	int L,C;
	cin>>L>>C;
	for(int i=0;i<C;i++) cin>>arr[i];
	sort(arr,arr+C); //count =C
	
	int cnt=0;	
	for(int i=0;i<C;i++){
		if(isalpha(arr[i])){
			
			al[cnt++]=arr[i]; //count = cnt
		}
	}
	///////////////

	////////////
	//go(L,C,v,0,somun);
	return 0;
	
}

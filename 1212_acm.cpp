#include<iostream>

using namespace std;

string arr[8]={

	"000","001","010","011","100","101","110","111"

};
string lastarr[8]={

	"0","1","10","11","100","101","110","111"

};

string convert(char x){
	
	return arr[x-'0'];
	
}


int main(){
	
	string x;
	string str="";
	cin>>x;
	if(x.length()==1){
		
		str+=lastarr[x[0]-'0'];
		
	}
	else{
		str+=lastarr[x[0]-'0'];
		for(int i=1;i<x.length();i++){
			
			str+=arr[x[i]-'0'];
			
		}
	}
	cout<<str<<'\n';
	return 0;
}

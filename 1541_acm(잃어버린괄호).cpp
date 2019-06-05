#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

vector<int> P;
vector<int> M;	

bool isnumber(char c){
	
	if(c>='0' && c<='9') return true;
	return false;
	
}

void pushing(int sum, bool signal){
	
	if(signal) P.push_back(sum);
	else M.push_back(sum);
	return;
	
}


int main(){ 
			
	string str;
	cin>>str;
	int sum=0;
	bool signal;   //false:- //true:+
	
	int sumP=0;
	int sumM=0;
	
	stack<int> S;
	for(int i=0;i<str.length();i++){
			
		if(P.empty()){
			
			if(isnumber(str[i])){
					
				S.push(str[i]-'0');
				
			}			

			else{
				int i=1;
				while(!S.empty()){
					sum += (i*S.top());
					S.pop();
					i*=10;
				}
				
				P.push_back(sum);
				cout<<sum<<'\n';
				if(str[i] == '+') signal = true;
				else signal = false;
				sum=0;
				
			}
		
		}
		else{
			
			if(isnumber(str[i])){
				
				S.push(str[i]-'0');
				
			}			

			else{
				
				int i=1;
				while(!S.empty()){
					sum += (i*S.top());	
					S.pop();
					i*=10;
				}
				
				
				cout<<sum<<'\n';
				pushing(sum,signal);
				
				
				cout<<"P:";
				for(int i=0;i<P.size();i++) cout<<P[i]<<' ';
				cout<<'\n';
				cout<<"M:";
				for(int i=0;i<M.size();i++) cout<<M[i]<<' ';
				cout<<'\n';
				
				
				if(str[i]=='+'){
				
					sum=0;			
				}
				else{
					
					signal = !signal;
					sum=0;
				}	
			}	
		}
	}
	
	while(!S.empty()){
		sum*=10;
		sum += S.top();
		S.pop();
	}
	pushing(sum,signal);
	
	for(int i=0;i<P.size();i++){
		
		sumP+=P[i];
		
	}
	for(int i=0;i<M.size();i++){
		
		sumM+=M[i];
		
	}
	
	cout<<"aaaa"<<sumP-sumM<<'\n';
	
	return 0;
}

#include<iostream>
using namespace std;

long long num(long long A, long long B, long long C){
	
	if(B==0) return 1LL; /////////////////////////////////////////
	if(B==1) return A%C;
	if(B&1) return ((A%C)*(num(A,B-1,C)%C))%C;
	else {
		long long tmp = num(A,B/2,C)%C;
		return ((tmp%C)*(tmp%C))%C;
		
	}
}

int main(){
	
	long long A,B,C;
	cin>>A>>B>>C;
	cout<<num(A,B,C)<<'\n';
	return 0;
	
}

#include<iostream>

using namespace std;

int main(){
	
	long long S;
	cin>>S;
	long long i =1;
	while(i*(i+1)/2<=S){
		i++;
	}
	cout<<i-1<<'\n';
	
	return 0;
}

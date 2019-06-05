#include<iostream>
#include<cstring>
using namespace std;

int main(){
	
	int sum=0;
	int min=100;
	string x;
	string y;
	cin>>x>>y;
	int lenx = x.length();
	int leny = y.length();
	
	for(int i=0; i<=leny-lenx;i++){
		for(int j=i;j<i+lenx;j++){
			
			if(y[j]!=x[j-i]) sum+=1;
			
		}
		if(sum<min) min = sum;
		sum=0;
	}
	cout<<min<<'\n';
	
	return 0;
}

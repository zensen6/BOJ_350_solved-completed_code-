#include<iostream>
#define SWAP(X,Y,Z) ((Z=X),(X=Y),(Y=Z))

using namespace std;

int cnt=0;

int two(int x){
	
	int i=0;
	while(x>>i!=1) i++;
	
	return i+1;
	
}


int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	int n,k1,k2;
	cin>>n>>k1>>k2;
	if(k1>k2) SWAP(k1,k2,t);
	
	while(k1!=k2){
		
		if(k1%2==0) k1/=2;
		else k1=(k1+1)/2;
		if(k2%2==0) k2/=2;
		else k2=(k2+1)/2;
		cnt++;
	}
	
	cout<<cnt<<'\n';
	
	
	return 0;
}

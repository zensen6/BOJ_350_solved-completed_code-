#include<iostream>
#include<algorithm>
using namespace std;

int arr[2];

void countof2or5(int x){
	
	int n2=0;
	int n5=0;
	int i2=2;
	int i5=5;
	while(x%i2==0){
		
		i2*=2;
		n2++;
	}
	while(x%i5==0){
		
		i5*=5;
		n5++;
	}
	arr[0] += n2;
	arr[1] += n5;
}

int main(){
	arr[0]=0;
	arr[1]=0;
	int n;
	
	cin>>n;
	for(int i=1;i<=n;i++){
		
		countof2or5(i);
		
	}
	cout<<min(arr[0],arr[1])<<'\n';
	
	return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

int B[50];
int BC[50];
int A[50];
int AC[50];
int C[50];

bool check[50]={false};
int Bi[50];

bool comp(int a, int b){
	
	return a>b;
	
}

int main(){
	
	int index=0;
	int cnt=0;
	int sum=0;
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		
		cin>>A[i];
		AC[i]=A[i];		
	} 
	
	for(int i=0;i<N;i++){
		
		cin>>B[i];
		BC[i]=B[i];
	}
	sort(BC,BC+N);	
	sort(AC,AC+N,comp);
	int i;
	for(cnt=0;cnt<N;cnt++){
		for(i=0;i<N;i++){
			
			if(BC[cnt]==B[i] && check[i]==false){
			
				index=i;
				check[index]=true;
				Bi[index]=cnt;
				C[index]=AC[cnt];
				break;
			}		
			
		}
		
	}
	
	
	
	for(int i=0;i<N;i++){
		
		sum+=(C[i]*B[i]);
		
	}
	cout<<sum;
	return 0;
}

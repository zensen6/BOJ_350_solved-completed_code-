#include<iostream>
using namespace std;

int score[1000];

int main(){
	
	int N;
	double sum=0;
	int max=0;
	cin>>N;
	for(int i=0;i<N;i++){
		 cin>>score[i];
		 if(score[i]>=max) max=score[i];
	}
	
	for(int i=0;i<N;i++){
		
		sum+=((double)score[i]/max)*100;
		
	}
	cout<<sum/N<<'\n';
	
	
	return 0;
	
}

#include <iostream>

using namespace std;

int arr[20];

int go(int N, int sum, int tmp, int index){
	
//correct
	if(tmp ==sum && index==N) return 1; //이미 index를 통해 고를거 다골랐는데 sum찾은경우 
//impossible
	if(index>=N) return 0;  //고를거 다골랐는데 아닌경우 
	return go(N, sum, tmp+arr[index],index+1) + go(N, sum, tmp, index+1);
	
}


int main(){
	
	int N,sum;
	cin>>N>>sum;
	for(int i=0;i<N;i++) cin>>arr[i];
	int res= (sum==0? go(N,sum,0,0)-1:go(N,sum,0,0));
	cout<<res<<'\n';
	return 0;
}

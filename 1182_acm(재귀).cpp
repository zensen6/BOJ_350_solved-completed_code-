#include <iostream>

using namespace std;

int arr[20];

int go(int N, int sum, int tmp, int index){
	
//correct
	if(tmp ==sum && index==N) return 1; //�̹� index�� ���� ���� �ٰ���µ� sumã����� 
//impossible
	if(index>=N) return 0;  //���� �ٰ���µ� �ƴѰ�� 
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

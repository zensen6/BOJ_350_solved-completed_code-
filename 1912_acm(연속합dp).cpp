#include <iostream>
using namespace std;

int arr[100001];
int d1[100001]={0};

int dp(int N){
	int index1=1;
	int index2=1;
	int sum=0;
	d1[1]=arr[1];�� 
	for(int i=2;i<=N;i++){                      //�ǹ̾��� ���ص��� 
		d1[i]=d1[i-1]+arr[i];
	}
		
	int i;
	
	d1[1]=arr[1];
	for(int i=2;i<=N;i++){                      //���� �տ��� �κ������� ���Ѱ� ���ݲ����������� ���ݰŸ�������ũ�� �κ������� ���Ѱű��� ��ġ�°� �̵�  �װԾƴϸ� �����°� �̵�  
		
		if(d1[i-1]+arr[i]<=arr[i]){
			d1[i]=arr[i];
		}
		else{
			d1[i]=d1[i-1]+arr[i];
		}
		
	}
	sum=d1[1];
	for(int i=1;i<=N;i++){
		if(sum<=d1[i]) sum=d1[i];
		
	}
	return sum;
	
}

int main(){
	
	int N;
	cin>>N;
	for(int i=1;i<=N;i++) cin>>arr[i];	
	cout<<dp(N)<<'\n';
	for(int i=1;i<=N;i++){
		
		cout<<d1[i]<<' ';
	}
	cout<<'\n';
	
	return 0;
	
}

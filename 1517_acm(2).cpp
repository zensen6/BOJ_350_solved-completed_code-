#include<iostream>

using namespace std;

int A[500001];
int Du[500001];

long long ans = 0;

void sorting(int start, int end){
	
	int mid = (start+end)/2;	
	int cnt = start;
	int i = start; int j = mid+1;
	while(i<=mid && j<=end){
		
		if(A[i]>A[j]){
			
			Du[cnt] = A[j];
			
			ans +=(j-cnt);
			cnt++;
			j++;
		}
		else{
			
			Du[cnt++] = A[i++];
		}
		
	}
	while(cnt<=end){
		
		if(i<=mid){
			
			Du[cnt++] = A[i++];
			
		}
		else{
			
			Du[cnt] = A[j];
			ans += (j-cnt);
			j++;
			cnt++;
			
		}
		
	}
	for(int i=start;i<=end;i++){
		
		A[i] = Du[i];
		
	}
	
}



void merge(int start, int end){
	
	if(start == end) return;
	int mid = (start+end)/2;
	merge(start, mid);
	merge(mid+1, end);
	sorting(start,end);
	
}


int main(){
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		 cin>>A[i];	
		 Du[i] = A[i];
	}
	merge(1,n);
	
	cout<<ans<<'\n';
	
	return 0;
}

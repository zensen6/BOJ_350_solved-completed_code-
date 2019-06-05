#include<iostream>
#include<vector>

using namespace std;

int M[10];
bool yes[10]={false};

int min0(int a, int b){
	
	return a<=b? a:b;
	
}

bool check(int N){
	
	if(N==0){
		if(yes[0]==true) return false;
		else return true;
	}
	int i=1;
	while(N>0){
		
		if(yes[N%10]==true) return false;
		N/=10;
		
	}

	return true;
	
}

int abs1(int a, int b){
	
	
	if(a>=b) return a-b;
	else return b-a;
	
}

int count10(int N){
	if (N==0){
		return 1;
	}
	int count=1;
	int i=1;
	while(i*10<=N){
		i*=10;
		count++;
	}
	return count;
	
}

int main(){
	
	int N;
	int count;
	int min=2000000;
	int ans=2000000;
	cin>>N;
	cin>>count;
	for(int i=0;i<count;i++){
		
		cin>>M[i];
		yes[M[i]]=true;    // yes = broken
		
	}
	
	ans = abs1(N,100);   // +/-으로만 이동 
	for(int i=0;i<=1000000;i++){
		
		if(check(i) && ((abs1(i,N)+count10(i))<=min)){
			
			min = abs1(i,N)+count10(i);
				
		}
			
	}	

	if(count==10){
		
		
		cout<<ans<<'\n';
		
		return 0;
	}
	else if(count<10){
		
		int r = min<=ans? min:ans;
		cout<<r<<'\n';
		return 0;
		
	}
	
}

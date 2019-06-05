#include<cstdio>
#include<memory.h>
#include<vector>

using namespace std;

int main(){
	
	int alpha[26];
	memset(alpha,0,sizeof(alpha));
	int c;
	int cnt = 0;
	while(1){
		
		c = getchar();
		if(cnt==5000) break;
		alpha[(char)c-'a']++;
		cnt++;
	}
	vector<int> v;
	int ind = 0;
	int max = 0;
	for(int i=0;i<26;i++){
		
		if(alpha[i]>max){
			
			max = alpha[i];
		}
		
	}
	for(int i=0;i<26;i++){
		
		if(alpha[i]==max){
			
			v.push_back(i);
			
		}
		
	}
	for(auto a:v) printf("%c",(char)(a+'a'));
	return 0;
}

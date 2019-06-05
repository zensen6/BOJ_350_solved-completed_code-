#include<stdio.h>

int main(){
	
	int n;
	int yes = 0;
	int alpha[26] ={0};
	char name[32];
	scanf("%d",&n);
	getchar();
	while(n--){
		
		fgets(name,31,stdin);
		//printf("%s\n",name);
		alpha[name[0]-'a']++;
		
	}
	for(int i=0;i<26;i++){
	
		if(alpha[i]>=5){
			
			printf("%c",(i+'a'));
			yes = 1;
		}
	
	}	
	if(!yes) printf("PREDAJA\n");
	
	return 0;
	
}

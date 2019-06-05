#include <stdio.h>
#include <cstring>

using namespace std;

int ohm(char* a, int n){
	
	if(!strcmp(a,"black")){
		
		if (n==0) return 0;
		else return 1;
	}
	else if(!strcmp(a,"brown")){
		
		if (n==0) return 1;
		else return 10;
	}
	else if(!strcmp(a,"red")){
		
		if (n==0) return 2;
		else return 100;
	}
	else if(!strcmp(a,"orange")){
		
		if (n==0) return 3;
		else return 1000;
	}
	else if(!strcmp(a,"yellow")){
		
		if (n==0) return 4;
		else return 10000;
	}
	else if(!strcmp(a,"green")){
		
		if (n==0) return 5;
		else return 100000;
	}
	else if(!strcmp(a,"blue")){
		
		if (n==0) return 6;
		else return 1000000;
	}
	else if(!strcmp(a,"violet")){
		
		if(n==0) return 7;
		else return 10000000;
	}
	else if(!strcmp(a,"grey")){
		
		if(n==0) return 8;
		else return 100000000;
	}
	else{
		
		if(n==0) return 9;
		else return 1000000000;
	}
}


int main(){
	
	long long sum=0;
	char a[20];
	char b[20];
	char c[20];
	scanf("%s",a);
	scanf("%s",b);
	scanf("%s",c);
	sum=ohm(a,0)*10 + ohm(b,0);
	sum*=ohm(c,1);
	printf("%lld\n",sum);
	
	
	return 0;
}

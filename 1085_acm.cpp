#include <iostream>
using namespace std;


int main(){
	
	int x,y,w,h;
	cin>>x>>y>>w>>h;
	int r = w-x<=h-y? w-x:h-y;
	int k = x<=y?x:y;
	
	cout<<(r<=k?r:k);
	
	return 0;
	
	
}

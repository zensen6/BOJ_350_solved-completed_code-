#include<iostream>
#include<vector>

using namespace std;

int main(){
	
	string s;
	vector<int> num;
	vector<int> sig;
	int cn=0;
	int ans = 0;
	
	cin>>s;
	
	sig.push_back(1);
	for(int i=0;i<s.length();i++){
		
		if(s[i]=='+'||s[i]=='-'){
			
			if(s[i]=='+') sig.push_back(1);
			else sig.push_back(-1);
			
			num.push_back(cn);
			cn=0;
		} 
		else{
			
			cn=cn*10+(s[i]-'0');
			
		}
		
	}
	num.push_back(cn);
	
	bool minus = false;
	for(int i=0;i<num.size();i++){            //�Ǿպ��� +�ΰ� �׳� ��� +�ع����� ó������ -�� ���¼������� �ڿ��ִ� +�� ��� -, -�� ��� �׳� �������� ���ֱ⸦�Ѵ�. 
		
		if(sig[i]==-1) minus =true;
			
		if(minus) ans-=num[i];
		else ans+=num[i];
		
	}
	cout<<ans<<'\n';
	
	return 0;
}


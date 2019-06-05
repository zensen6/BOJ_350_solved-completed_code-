#include<bits/stdc++.h>
#include<string>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string x;
    int n;
    cin>>x;
    cin>>n;
    char C;
    int len = x.length();
    list<char> editor(x.begin(),x.end());
    auto cursor = editor.end();

    while(n--){

        cin>>C;
        if(C=='L'){
            if(cursor != editor.begin()) cursor--;
            cout<<"cursor: "<<*cursor<<'\n';
        }
        else if(C=='D'){

            if(cursor != editor.end()) cursor++;
            cout<<"cursor: "<<*cursor<<'\n';
        }
        else if(C=='P'){

           char M;
           cin>>M;
           editor.insert(cursor,M);
           
            for(auto& q: editor){
                cout<<q;
            }
            cout<<"  cursor:"<<*cursor<<'\n';  
           
        }
        else{

            if(cursor!=editor.begin()){

                cursor--;
                editor.erase(cursor);

                for(auto& q: editor){
                    cout<<q;
                }
                cout<<"  cursor:"<<*cursor<<'\n';                   

                //cursor++;

            }


        }



    }
    for(auto& q: editor){
        cout<<q;

    }
    return 0;
}


/*
#include<iostream>
#include<string>
#include<list>
using namespace std;
 
int main(){
    int n; 
    string s; //초기 입력 문자열
 
    cin >> s; //abcd
    cin >> n;
    
    list<char> editor(s.begin(),s.end()); // 문자열을 리스트로  
    auto cursor=editor.end(); // 초기 커서의 위치는 문장의 맨 뒤
    
    while(n--){// 명령의 수 만큼 반복 
        char cmd;
        cin >> cmd; //명령어 입력 
        
        if(cmd=='L'){
            if(cursor!=editor.begin()){
                cursor--;
            }
        } 
        else if(cmd=='D'){
            if(cursor!=editor.end()){
                cursor++;
            }
        }
        else if(cmd=='B'){
            if(cursor!=editor.begin()){
                cursor--;
                editor.erase(cursor);
                cursor++;
            }
        }
        else if(cmd=='P'){
            char x;
            cin >> x;
            editor.insert(cursor,x);
        }    
    }
    for(auto &x:editor){
        cout << x;
    }
    return 0;     
}


출처: https://kih0902.tistory.com/28 [ㅇㅇ]

*/
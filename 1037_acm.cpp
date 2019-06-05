#include<bits/stdc++.h>
#include<memory.h>

using namespace std;

int arr[51];
bool check[51];

bool comp(int a, int b){

    return a>b;

}

int main(){

    memset(check,false,sizeof(check));
    int k;
    cin>>k;

    bool con = true;
    for(int i=1;i<=k;i++) cin>>arr[i];
    sort(arr+1,arr+1+k, comp);
    //cout<<arr[1]<<'\n';
    for(int i=arr[1]+1; i<=1000000;i++){
        for(int j=1;j<=k;j++){


            if(i%arr[j]!=0){

                con = false;
                break;

            } 

        }
        if(con){
            cout<<i<<'\n';
            return 0;
        }
        else{

            con = true;

        }
    }

    return 0;
}
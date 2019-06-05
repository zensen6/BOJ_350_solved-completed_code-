#include<bits/stdc++.h>
#include<memory.h>
#define INF 100000

using namespace std;

int arr[51];
bool check[51];

void find(int ori, int x, int target){

    if(x == target){

        check[ori] = true;
        return;

    }
    else if(x == -1) return;
    else{

        find(ori, arr[x], target);

    }

}

int main(){

    memset(check,false,sizeof(check));
    int cnt = 0;
    int n;
    int r;
    bool isleaf = true;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    cin>>r;

    check[r] = true;
    for(int i=0;i<n;i++) find(i,i,r);

    for(int i=0;i<n;i++){
        isleaf = true;
        if(!check[i]){

            for(int j=0;j<n;j++){

                if(!check[j] && arr[j]==i){

                    isleaf = false;
                    break;
                }

            }
            if(isleaf){

                cnt++;
			//	cout<<i<<' ';
            }
        }

    } 
    /*
    for(int i=0;i<n;i++){
        if(!check[i]) cout<<i<<' ';

    } 
    */
    //cout<<'\n';
    
    cout<<cnt<<'\n';

    return 0;
}

#include<bits/stdc++.h>
#include<memory.h>

using namespace std;

int d[101][101]; 
int per[101] = {0};

int main(){

    int n,m;
    cin>>n>>m;
    memset(d,0,sizeof(d));
    for(int i=1;i<=m;i++){

        int from, to;
        cin>>from>>to;
        d[from][to] = 1;
        d[to][from] = 1;

    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){

                if(i!=j){

                    if(d[i][k]>0 && d[k][j]>0 && (d[i][j] == 0 || d[i][j] > d[i][k] + d[k][j])){

                        d[i][j] = d[i][k] + d[k][j];

                    }

                }

            }

        }

    }
    ////

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            per[i] += d[i][j];
        }
    }
    int min = 1000000000;
    int index = 101;
    for(int i=n;i>=1;i--){

        if(per[i] <= min){

            min = per[i];
            index = i;

        }

    }
    cout<<index<<'\n';
    ////
    return 0;
}
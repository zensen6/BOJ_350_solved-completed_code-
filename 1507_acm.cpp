#include<bits/stdc++.h>

using namespace std;

int d[21][21];

int main(){


    
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){

            cin>>d[i][j];

        }
    }
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j && j!=k && k!=i && (d[i][j] > (d[i][k] + d[k][j])) && d[i][k]>0 && d[k][j]>0){

                    cout<<-1<<'\n';
                    return 0;

                }
                if(i!=j && j!=k && k!=i && (d[i][j] == (d[i][k] + d[k][j])) && d[i][k]>0 && d[k][j]>0){

                    d[i][j] = 0;
                    
                }
            }
        }
    }
   
    int sum= 0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){

            sum += d[i][j];
        }

    }
    cout<<sum<<'\n';
    return 0;
}
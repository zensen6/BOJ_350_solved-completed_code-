#include<bits/stdc++.h>
#include<memory.h>
#define MOD 9901
using namespace std;

int dp[100001][3];

int main(){

    memset(dp,0,sizeof(dp));
    int N;
    cin>>N;
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;
    for(int i=2;i<=N;i++){

        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2])%MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2])%MOD;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1])%MOD;

    }
    cout<<(dp[N][0] + dp[N][1] + dp[N][2])%MOD<<'\n';

    return 0;
}
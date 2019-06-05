#include<bits/stdc++.h>

using namespace std;

int arr[51];

int min0(int x, int y){

    return x<y? x:y; 

}

int main(){

    int count = 0;
    int sum = 0;
    queue<int> q;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) q.push(i);
    for(int i=1;i<=m;i++){

        cin>>arr[i];

    }
    int k=1;
    while(k<=m){

        while(q.front()!=arr[k]){

            int x = q.front();
            q.pop();
            q.push(x);
            count++;

        }
        q.pop();
        sum+=min0(count,q.size()+1-count);
        count = 0;
        k++;
    }

    cout<<sum<<'\n';
    return 0;
}
#include<bits/stdc++.h>
#include<memory.h>
#define IOS ios_base::sync_with_stdio(0)
#define CI cin.tie(0)

using namespace std;


int cost[1001] = {0};
int dist[1001] = {0};
int ind[1001] = {0};

int main(){

    IOS;
    CI;

    int T;    
    cin>>T;

    while(T--){
        int n, m;
        int fin;
        queue<int> q;
        vector<int> v[1001];
        memset(ind,0,sizeof(ind));
        memset(cost,0,sizeof(cost));
        memset(dist,0,sizeof(dist));
        cin>>n>>m;
        for(int i=1;i<=n;i++){

            cin>>cost[i];

        }
        
        for(int i=1;i<=m;i++){
            int from, to;
            cin>>from>>to;
            v[from].push_back(to);
            ind[to]++;

        }
        cin>>fin;
        for(int i=1;i<=n;i++){

            if(ind[i]==0) q.push(i); 

        }
        while(ind[fin]>0){

            int from = q.front();
            q.pop();
            for(int next:v[from]){

                dist[next] = max(dist[next],dist[from]+cost[from]);
                ind[next]--;
                if(ind[next]==0) q.push(next);
            }
            
        }
        cout<<dist[fin]+cost[fin]<<'\n';

    }

    return 0;
}
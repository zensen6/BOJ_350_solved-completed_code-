#include<bits/stdc++.h>
#include<memory.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define INF 10000000
#define PB push_back
#define MP make_pair
#define IOS ios_base::sync_with_stdio(false)
#define CI cin.tie(0)
#define CO cout.tie(0)

using namespace std;

int dist[1001];
bool check[1001];


bool comp(pair<int,int> &a, pair<int,int> &b){

    if(a.second < b.second) return true;
    else return false;

}

int dijkstra(int start,int target, int N, vector<pair<int,int>> v[801]){
    FOR(i,1,N){

        dist[i] = INF;

    }
    memset(check,false,sizeof(check));
    dist[start] = 0;
    priority_queue<pair<int,int>> q;
    q.push(MP(-dist[start],start));

    FOR(k,0,N-2){

        int x = -1;
        while(!q.empty()){

            auto p = q.top();
            int y = p.second;
            q.pop();
            if(!check[y]){

                x = y;
                check[y] = true;
                break;
            }

        }

        for(auto &p:v[x]){

            int y = p.first;
            if(dist[x] + p.second < dist[y]){

                dist[y] = dist[x] + p.second;
                q.push(MP(-dist[y],y));

            }

        }


    }

    return dist[target];
}

int main(){

    IOS;
    CI;
    CO;

    vector<pair<int,int>> v[1001];
    int N, E, X;
    cin>>N>>E>>X;
    FOR(i,1,E){

        int from, to, cost;
        cin>>from>>to>>cost;
        v[from].PB(MP(to,cost));

    }

    
    int max0 = 0;
   



   

    cout<<max0<<'\n';
    
    return 0;
}

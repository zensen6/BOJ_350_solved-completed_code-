#include<bits/stdc++.h>
#include<memory.h>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define INF 100000000
#define PB push_back
#define MP make_pair
#define IOS ios_base::sync_with_stdio(false)
#define CI cin.tie(0)
#define CO cout.tie(0)

using namespace std;

int dist[801];
bool check[801];

bool comp(pair<int,int> &a, pair<int,int> &b){

    if(a.second < b. second) return true;
    else return false;

}

int dijkstra(int start,int target, int N, vector<pair<int,int>> v[801]){
    FOR(i,1,N){

        dist[i] = INF;

    }
    memset(check,false,sizeof(check));
    dist[start] = 0;

    FOR(k,0,N-2){

        int x = -1;
        int m = INF + 1;
        FOR(i,1,N){

            if(!check[i]  && m>dist[i]){
                m = dist[i];
                x = i;
            }

        }
        check[x] = true;

        for(auto &p:v[x]){

            int y = p.first;
            if(dist[x] + p.second < dist[y]){

                dist[y] = dist[x] + p.second;

            }

        }


    }

    return dist[target];
}

int main(){

    IOS;
    CI;
    CO;

    vector<pair<int,int>> v[801];
    int N, E;
    cin>>N>>E;
    FOR(i,1,E){

        int from, to, cost;
        cin>>from>>to>>cost;
        v[from].PB(MP(to,cost));
        v[to].PB(MP(from,cost));

    }
    int V1,V2;
    int cost1_V1, cost1_V2, costV1_V2, costV1_n, costV2_n;
    cin>>V1>>V2;

    cost1_V1 = dijkstra(1,V1,N,v);
    cost1_V2 = dijkstra(1,V2,N,v);
    costV1_V2 = dijkstra(V1,V2,N,v);
    costV1_n = dijkstra(V1,N,N,v);
    costV2_n = dijkstra(V2,N,N,v);

    int min0 = min(cost1_V1 + costV2_n, cost1_V2 + costV1_n);
  
   	if(min0 >=INF) cout<<-1<<'\n';
	else cout<<min0+costV1_V2<<'\n';

    return 0;
}

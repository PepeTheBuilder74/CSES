#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "coding.h"
#else
#define dbg(x...)
#endif
#define nl "\n"
#define ll long long int

void __solve_testcase(int test_case);
void pre_process();
 
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pre_process();
 
    int no_of_testcase = 1;
    for(int testcase = 1; testcase <= no_of_testcase ; testcase++){
        __solve_testcase(testcase);
    }
    return 0;
}
 
void pre_process() {

}
const int nxn=1e5+5,mod=1e9+7;
vector<pair<ll,ll>> adj[nxn];
ll ways[nxn],dist[nxn],min_nodes[nxn],max_nodes[nxn],vis[nxn];
void __solve_testcase(int test_case) {
    int N,M; cin>>N>>M;
    for(int i=0;i<M;i++){
        int u,v,w; cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,1});
    ways[1]=1;
    for(int i=1;i<=N;i++)dist[i]=1e18,min_nodes[i]=1e18,max_nodes[i]=-1e18;
    min_nodes[1]=max_nodes[1]=0;
    dist[1]=0;
    while(!pq.empty()){
        auto [d,node]=pq.top();
        pq.pop();
        if(vis[node])continue;
        vis[node]=1;
        for(auto [child,w]:adj[node]){
            if(d+w<dist[child]){
                dist[child]=d+w;
                pq.push({dist[child],child});
                min_nodes[child]=min_nodes[node]+1;
                max_nodes[child]=max_nodes[node]+1;
                ways[child]=ways[node];
            }
            else if(d+w==dist[child]){
                ways[child]+=ways[node];
                min_nodes[child]=min(min_nodes[child],min_nodes[node]+1);
                max_nodes[child]=max(max_nodes[child],max_nodes[node]+1);
                if(ways[child]>=mod)ways[child]-=mod;
            }
        }
    }
    cout<<dist[N]<<' '<<ways[N]<<' '<<min_nodes[N]<<' '<<max_nodes[N]<<nl;
}
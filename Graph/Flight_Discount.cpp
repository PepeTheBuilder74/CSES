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
const int nxn=1e5+5;
vector<pair<ll,ll>> adj[nxn];
ll dist[nxn][2];
bool vis[nxn][2];
void __solve_testcase(int test_case) {
    int N,M; cin>>N>>M;
    for(int i=0;i<M;i++){
        int u,v; ll w; cin>>u>>v>>w;
        if(u==v)continue;
        adj[u].push_back({v,w});
    }
    for(int i=1;i<=N;i++)dist[i][0]=dist[i][1]=1e18;
    priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<pair<ll,pair<ll,ll>>>> pq;
    dist[1][0]=dist[1][1]=0;
    // dist,node,apply_discount
    pq.push({0,{1,0}});
    while(!pq.empty()){
        auto x=pq.top();
        pq.pop();
        ll d=x.first;
        ll node=x.second.first;
        ll apply_discount=x.second.second;
        if(vis[node][apply_discount])continue;
        vis[node][apply_discount]=1;
        dist[node][apply_discount]=d;
        for(auto&[child,w]:adj[node]){
            if(dist[child][apply_discount]>d+w){
                dist[child][apply_discount]=d+w;
                pq.push({dist[child][apply_discount],{child,apply_discount}});
            }
            if(apply_discount==0){
                if(dist[child][1]>d+w/2){
                    dist[child][1]=d+w/2;
                    pq.push({dist[child][1],{child,1}});
                }
            }
        }
    }
    cout<<dist[N][1]<<nl;
}
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
vector<ll> adj[nxn],rev[nxn];
ll ways[nxn],indegree[nxn];
void __solve_testcase(int test_case) {
    int N,M; cin>>N>>M;
    for(int i=0;i<M;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        rev[v].push_back(u);
        indegree[v]++;
    }
    queue<int> track;
    for(int i=1;i<=N;i++){
        if(indegree[i]==0)track.push(i);
    }
    ways[1]=1;
    while(!track.empty()){
        int node=track.front();
        track.pop();
        for(auto child:adj[node]){
            indegree[child]--;
            if(indegree[child]==0)track.push(child);
        }
        for(auto parent:rev[node]){
            ways[node]+=ways[parent];
            if(ways[node]>=mod)ways[node]-=mod;
        }
    }
    cout<<ways[N]<<'\n';
}
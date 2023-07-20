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
    // cin >> no_of_testcase;
    for(int testcase = 1; testcase <= no_of_testcase ; testcase++){
        // cout << "Case #" << testcase << ": ";
        __solve_testcase(testcase);
    }
    return 0;
}
 
void pre_process() {
     
}
const int nxn=1e5+5;
int vis[nxn],onStack[nxn],par[nxn];
vector<int> adj[nxn];
void dfs(int node,int parent=-1){
    vis[node]=1;
    onStack[node]=1;
    par[node]=parent;
    for(auto child:adj[node]){
        if(!vis[child]){
            dfs(child,node);
        }
        else if(onStack[child]){
            int u=node;
            vector<int> cycle;
            cycle.push_back(u);
            while(u!=child){
                u=par[u];
                cycle.push_back(u);
            }
            cycle.push_back(node);
            reverse(cycle.begin(),cycle.end());
            cout<<cycle.size()<<nl;
            for(auto x:cycle)cout<<x<<" ";
            exit(0);     
        }
    }
    onStack[node]=0;
}
void __solve_testcase(int test_case) {
    int  N,M; cin>>N>>M; 
    for(int i=0;i<M;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=1;i<=N;i++)if(!vis[i])dfs(i);
    cout<<"IMPOSSIBLE";
}
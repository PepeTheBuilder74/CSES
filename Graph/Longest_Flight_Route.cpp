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
   /*
      1.DAG DP 
      2.DFS
      3.TopoSort and treat indices as nodes
   */
}
const int nxn=1e5+5;
vector<vector<int>> adj(nxn),rev(nxn);
ll dp[nxn];
int par[nxn];
void __solve_testcase(int test_case) {
    int N,M; cin>>N>>M;
    vector<int>indegree(N,0);
    for(int i=0;i<M;i++){
        int u,v; cin>>u>>v;
        adj[u-1].push_back(v-1);
        rev[v-1].push_back(u-1);
        indegree[v-1]++;
    }
    queue<int>q;
    for(int i=0;i<N;i++){
        if(indegree[i]==0)q.push(i);
    }
    // we first want 1 as the first node
    for(int i=0;i<N;i++)dp[i]=-99999999;
    dp[0]=1;
    par[0]=-1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto child:adj[node]){
            indegree[child]--;
            if(indegree[child]==0)q.push(child);
        }
        ll mx=-999999999,p=-1;
        for(auto child:rev[node]){
            if(dp[child]+1>mx){
                mx=dp[child]+1;
                p=child;
            }
        }
        dp[node]=max(dp[node],mx);
        if(par[node]!=-1)par[node]=p;
    }
    if(dp[N-1]==0){
         cout<<"IMPOSSIBLE"<<nl;
         return;
    }
    vector<int>ans;
    int node=N-1;bool ok=0;
    while(node!=-1){
        if(node==0)ok=1;
        ans.push_back(node+1);
        node=par[node];
    }
    if(!ok){
        cout<<"IMPOSSIBLE"<<nl;
        return;
    }
    cout<<dp[N-1]<<nl;
    reverse(ans.begin(),ans.end());
    for(auto x:ans)cout<<x<<" ";
    cout<<nl;
}
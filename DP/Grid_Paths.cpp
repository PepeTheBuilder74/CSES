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
 
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int no_of_testcase = 1;
    // cin >> no_of_testcase;
    for(int testcase = 1; testcase <= no_of_testcase ; testcase++){
        __solve_testcase(testcase);
    }
    return 0;
}
void __solve_testcase(int test_case) {
    const int mod=1e9+7;
    int N;cin>>N;
    vector<vector<char>>grid(N+1,vector<char>(N+1));
    for(int i=1;i<=N;i++)for(int j=1;j<=N;j++) cin>>grid[i][j];
    vector<vector<ll>>dp(N+2,vector<ll>(N+2,0));
    for(int i=1;i<=N;i++){
      for(int j=1;j<=N;j++){
         if(grid[i][j]=='*'){
            dp[i][j]=0;
            continue;
         }
         if(i==1 && j==1)dp[i][j]=1;
         else if(i==1)dp[i][j]=dp[i][j-1];
         else if(j==1)dp[i][j]=dp[i-1][j];
         else {
            dp[i][j]+=dp[i-1][j];
            dp[i][j]+=dp[i][j-1];
         }
         if(dp[i][j]>=mod)dp[i][j]-=mod;
      }
    }
    cout<<dp[N][N]<<nl;

}
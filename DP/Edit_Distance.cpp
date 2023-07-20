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
const int INF=1e9+5;
void __solve_testcase(int test_case) {
    string s,t; cin>>s>>t;
    int n=s.size(),m=t.size();
    vector<vector<int>>dp(n+2,vector<int>(m+2,0));
    for(int i=0;i<=n;i++) dp[i][0]=i;
    for(int i=0;i<=m;i++) dp[0][i]=i;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=m;j++){
        if(s[i-1]==t[j-1]){
            dp[i][j]=dp[i-1][j-1];
        }else{
            dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
        }
      }
    }
    cout<<dp[n][m]<<nl;
}

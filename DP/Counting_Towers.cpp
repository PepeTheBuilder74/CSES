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
const int mod=1e9+7;
const int nxn=1e6+5;
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int no_of_testcase = 1;
    cin >> no_of_testcase;
    vector<vector<ll>>dp(nxn+1,vector<ll>(2,0));
    dp[1][0]=dp[1][1]=1;
    for(int i=2;i<=nxn;i++){
        dp[i][0]=(dp[i-1][0]*4+dp[i-1][1])%mod;
        dp[i][1]=(dp[i-1][0]+dp[i-1][1]*2)%mod;
    }
    for(int testcase = 1; testcase <= no_of_testcase ; testcase++){
        int N; cin>>N;
        cout<<(dp[N][0]+dp[N][1])%mod<<'\n';
    }
    return 0;
}
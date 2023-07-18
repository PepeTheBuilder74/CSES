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
    int N,X;cin>>N>>X;
    vector<int>coins(N); for(auto &x:coins)cin>>x;
    vector<ll>dp(X+1,0);
    dp[0]=1;
    for(int j=0;j<=X;j++){
        for(auto &coin:coins){
           if(j+coin<=X){
            dp[j+coin]+=dp[j];
            if(dp[j+coin]>=mod)dp[j+coin]-=mod;
           }
        }
    }
    cout<<dp[X]<<nl;
}
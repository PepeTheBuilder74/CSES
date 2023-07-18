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
    int N,X;cin>>N>>X;
    vector<int>coins(N);
    for(int i=0;i<N;i++)cin>>coins[i];
    vector<int>dp(X+1,1e9);
    dp[0]=0;
    for(int i=1;i<=X;i++){
        for(auto &coin:coins){
            if(i-coin>=0)dp[i]=min(dp[i],dp[i-coin]+1);
        }
    }
    if(dp[X]==1e9)cout<<-1<<nl;
    else cout<<dp[X]<<nl;
}
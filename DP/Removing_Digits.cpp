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
    int  N ; cin>>N;
    vector<int>dp(N+1,1e9);
    dp[0]=0;
    auto get=[&](int x){
        vector<int>digits;
        while(x){
            digits.push_back(x%10);
            x/=10;
        }
        return digits;
    };
    for(int i=1;i<=N;i++){
        vector<int>digits=get(i);
        for(auto &x:digits){
           if(i-x>=0){
            dp[i]=min(dp[i],dp[i-x]+1);
           }
        }
    }
    cout<<dp[N]<<nl;
}

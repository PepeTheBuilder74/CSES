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
        __solve_testcase(testcase);
    }
    return 0;
}
 
void pre_process() {

}
void __solve_testcase(int test_case) {
    const int mod=1e9+7;
    int N;cin>>N;
    vector<ll>dp(N+1,0);
    dp[0]=1;
    for(int i=0;i<=N;i++){
       for(int j=1;j<=6;j++){
         if(i+j<=N){
          dp[i+j]+=dp[i];
          if(dp[i+j]>=mod)dp[i+j]-=mod;
         }
       }
    }
    cout<<dp[N]<<nl;
}
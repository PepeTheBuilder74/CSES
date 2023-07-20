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
     int N,M;cin>>N>>M;
     vector<int>A(N); for(auto &x:A)cin>>x;
     vector<ll>dp(M+2,0);
     const int mod=1e9+7;
     for(int j=1;j<=M;j++)if(A[0]==0 || A[0]==j){
        dp[j]=1;
     }
     for(int i=1;i<N;i++){
       vector<ll>ndp(M+2,0);
       for(int j=1;j<=M;j++){
        if(A[i]==0 || A[i]==j){
          ndp[j]=dp[j]+dp[j-1]+dp[j+1];
        }
        if(ndp[j]>=mod)ndp[j]-=mod;
       }      
       swap(dp,ndp);    
     }
     ll ans =accumulate(begin(dp),end(dp),0LL);
     ans%=mod;
     cout<<ans<<'\n';
}

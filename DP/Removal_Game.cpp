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
const int N=5005;
ll a[N];
ll dp[N][N][2];
void __solve_testcase(int test_case) {
    int N;
    cin>>N;
    for(int i=1;i<=N;i++) cin>>a[i];
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            if(i>j)dp[i][j][0]=dp[i][j][1]=0;
            else dp[i][j][0]=dp[i][j][1]=-1e18;
        }
    }
    for(int i=N;i>=1;i--){
        for(int j=i;j<=N;j++){
            dp[i][j][0]=max(dp[i+1][j][1]+a[i],dp[i][j-1][1]+a[j]);
            dp[i][j][1]=min(dp[i+1][j][0],dp[i][j-1][0]);
        }
    }
    cout<<dp[1][N][0]<<nl;
}
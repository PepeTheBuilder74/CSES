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
    int N,X; cin>>N>>X;
    vector<int>price(N),pages(N); 
    for(auto &x:price)cin>>x; 
    for(auto &x:pages)cin>>x;
    vector<int>dp(X+1,0);
    for(int i=0;i<N;i++){
        for(int j=X;j>=0;j--){
           if(j-price[i]>=0){
             dp[j]=max(dp[j],dp[j-price[i]]+pages[i]);
           }
        }
    }
    cout<<dp[X]<<'\n';
}
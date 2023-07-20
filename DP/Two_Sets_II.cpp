#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long int

void __solve_testcase(int test_case);
void pre_process();
 
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int no_of_testcase = 1;
    for(int testcase = 1; testcase <= no_of_testcase ; testcase++){
        __solve_testcase(testcase);
    }
    return 0;
}
const int mod=1e9+7;
void __solve_testcase(int test_case) {
    int N;cin>>N;
    vector<ll>a(N); iota(a.begin(),a.end(),1);
    ll sum=accumulate(a.begin(),a.end(),0LL);
    if(sum&1){
        cout<<0<<nl;
        return;
    }
    sum/=2;
    vector<ll>dp(sum+1,0);
    dp[0]=1;
    for(int i=0;i<N;i++){
        for(int j=sum;j>=a[i];j--){
            dp[j]+=dp[j-a[i]];
            if(dp[j]>=mod) dp[j]-=mod;
        }
    }
    dp[sum]*=500000004;
    dp[sum]%=mod;
    cout<<dp[sum]<<nl;
}
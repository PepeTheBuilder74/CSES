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
void __solve_testcase(int test_case) {
    int a,b; cin>>a>>b;
    vector<vector<ll>>dp(a+1,vector<ll>(b+1,1e9));
    for(int i=0;i<=min(a,b);i++) dp[i][i]=0;
    for(int i=0;i<=a;i++) dp[i][0]=i;
    for(int i=0;i<=b;i++) dp[0][i]=i;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i==j) continue;
            for(int k=1;k<i;k++){
                dp[i][j]=min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
            }
            for(int k=1;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
            }
        }
    }
    cout<<dp[a][b]<<nl;
}
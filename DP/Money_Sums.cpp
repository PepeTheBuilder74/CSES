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
   int N; cin>>N;
   vector<ll> a(N);
   for(auto &x:a)cin>>x;
   ll SUM=accumulate(a.begin(),a.end(),0LL);
   vector<bool>dp(SUM+1,0);
   dp[0]=1;
   for(int i=0;i<N;i++){
       for(int j=SUM;j>=a[i];j--){
           dp[j]=dp[j]|dp[j-a[i]];
       }
   }
   vector<int>ans;
   for(int i=1;i<=SUM;i++){
       if(dp[i]) ans.push_back(i);
   }
   cout<<ans.size()<<nl;
   for(auto &x:ans)cout<<x<<" \n"[x==ans.back()];
}
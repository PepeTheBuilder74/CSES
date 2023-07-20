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
const ll INF=1e18+5;
void __solve_testcase(int test_case) {
   int N,X; cin>>N>>X;
   vector<ll> a(N);
   for(auto &x:a)cin>>x;
   vector<pair<ll,ll>>dp(1<<N,{INF,INF});
   dp[0]={0,0};
   for(int mask=1;mask<(1<<N);mask++){
     for(int i=0;i<N;i++) if(mask&(1<<i)){
          auto [x,y]=dp[mask^(1<<i)];
          if(x+a[i]<=X){
              x+=a[i];
          }else{
            x=a[i];
            y++;
          }
          dp[mask]=min(dp[mask],{x,y});
       }
   }
   cout<<dp[(1<<N)-1].second+1<<nl;
}
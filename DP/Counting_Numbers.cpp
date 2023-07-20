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

ll dp[20][2][12][2];
void __solve_testcase(int testcase){
    ll l,r; cin>>l>>r;
    string L=to_string(l-1),R=to_string(r);
    function<ll(int,int,int,int)>solve=[&](int pos,bool tight,int prev,bool zero)->ll{
        if(pos==R.size()) return 1;
        ll &ans=dp[pos][tight][prev][zero];
        if(ans!=-1) return ans;
        ans=0;
        int limit=tight?R[pos]-'0':9;
        for(int i=0;i<=limit;i++){
            if(i==prev) continue;
            int nzero=zero&(i==0);
            int new_i=i;
            if(nzero) new_i=10;
            ans+=solve(pos+1,tight&(i==limit),new_i,nzero);
        }
        return ans;
    };
    memset(dp,-1,sizeof(dp));
    ll ans=solve(0,1,10,1);
    if(l!=0){
        swap(L,R);
        memset(dp,-1,sizeof(dp));
        ans-=solve(0,1,10,1);
    }
    cout<<ans<<nl;
}
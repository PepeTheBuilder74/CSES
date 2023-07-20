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
   int N,X; cin>>N>>X;
   vector<ll> a(N);
   for(auto &x:a)cin>>x;
   vector<ll>dp(1<<N,1e9);
   dp[0]=0;
   
}
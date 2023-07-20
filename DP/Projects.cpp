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
template <typename T>
class segtree
{
public:
    // 0 based indexing
    // def= default value
    vector<T> t;
    int n;
    T def;
    function<T(T, T)> merge;
    void build(int _n, T _def, function<T(T, T)> _fx)
    {
        n = _n; 
        def = _def; 
        merge = _fx;
        t.assign(n * 2, def);
        for (int i = n - 1; i; i--)
            t[i] = merge(t[i * 2], t[i * 2 + 1]);
    }
    void build(vector<T> &a, T _def, function<T(T, T)> _fx)
    {
        n = a.size();
        def = _def;
        merge = _fx;
        t.assign(n * 2, def);
        for (int i = 0; i < n; i++)
            t[i + n] = T(a[i]);
        for (int i = n - 1; i; i--)
            t[i] = merge(t[i * 2], t[i * 2 + 1]);
    }
    void update(int i, T v)
    {
        for (t[i += n] = T(v); i > 1;)
        {
            i /= 2;
            t[i] = merge(t[i * 2], t[i * 2 + 1]);
        }
    }
    // this query is made on [l, r)
    T query(int l, int r)
    {
        T lans = def, rans = def;
        for (l += n, r += n; l < r; l /= 2, r /= 2)
        {
            if (l % 2)
                lans = merge(lans, t[l++]);
            if (r % 2)
                rans = merge(t[--r], rans);
        }
        return merge(lans, rans);
    }
};
struct node {
    ll val;
    node(ll x) {
        val = x;
    }
    // default value
    node() {
        val = 0;
    }
};
void __solve_testcase(int test_case) {
    map<ll,ll>comp;
    int n; cin>>n;
    vector<ll>a(n),b(n),p(n);
    for(int i=0;i<n;i++){
         cin>>a[i]>>b[i]>>p[i];
         comp[a[i]]=comp[b[i]]=0;
    }
    vector<int>order(n); iota(order.begin(),order.end(),0);
    sort(order.begin(),order.end(),[&](int i,int j){
        return a[i]<a[j];
    });
    ll cnt=0;
    for(auto &x:comp){
        x.second=++cnt;
    }
    segtree<node>st;
    auto merge=[](node a,node b){
       return node(max(a.val,b.val));
    };
    st.build(cnt+1,node(),merge);
    vector<ll>dp(n);
    for(int j=0;j<n;j++){
        int i=order[j];
        dp[i]=p[i]+st.query(0,comp[a[i]]).val;
        if(st.query(comp[b[i]],comp[b[i]]+1).val<dp[i]){
            st.update(comp[b[i]],dp[i]);
        }
    }
    cout<<st.query(0,cnt+1).val<<nl;
}
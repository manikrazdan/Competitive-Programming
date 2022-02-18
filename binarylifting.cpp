#include <bits/stdc++.h>
 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;

#define pyes cout << "YES" << "\n";
#define pno cout << "NO" << "\n";
#define br cout << "\n";
#define ff first
#define ss second
#define pb push_back
#define mod 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " -> "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
ll gcd(ll a, ll b){ if (a == 0ll) { return b;} return gcd(b % a, a);}

void dfs(ll node, ll par, vector<ll> adj[], vector<vector<ll>> &dp, vector<ll> &level, ll lev = 0){
    dp[node][0] = par;
    level[node] = lev;
    for(ll i = 1; i <= 20; i++){
        dp[node][i] = dp[dp[node][i-1]][i-1];
    }
    for(auto it : adj[node]){
        if(it != par){
            dfs(it, node, adj, dp, level, lev + 1);
        }
    }
}

ll binarylifting(ll x, ll k, vector<vector<ll>> &dp){
    ll par = x;
    ll cnt = 0;
    while(k){
        if(k & 1){
            par = dp[par][cnt];
        }
        k = k >> 1;
        cnt++;
    }
    return par;
}

ll lca(ll a, ll b, vector<ll> &level, vector<vector<ll>> &dp){
        if(level[a] < level[b]){
            swap(a, b);
        }
        ll k = level[a] - level[b];
        a = binarylifting(a, k, dp);
        if(a == b){
            return a;
        }
        for(ll i = 20; i >= 0; i--){
            if(dp[a][i] != dp[b][i]){
                a = dp[a][i];
                b = dp[b][i];
            }
        }
        return dp[a][0];
}

void solve(){
    ll n, q;
    cin >> n >> q;
    vector<ll> adj[n+1];
    for(ll i = 2; i <= n; i++){
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<vector<ll>> dp(n+1, vector<ll>(21, 0));
    vector<ll> level(n+1, 0);
    dfs(1, 0, adj, dp, level);
    while(q--){
        ll a, b;
        cin >> a >> b;
        ll k = lca(a, b, level, dp);
        cout << (level[a] + level[b] - 2*level[k]) << endl;
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    //code here
 
    int t;
    t = 1;
    for(int i = 1; i <= t; i++){
        // cout << "Case #" << i << ": ";
        solve();
    }

    //end
 
    return 0;
 
}

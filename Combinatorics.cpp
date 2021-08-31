#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll mod = 1e9 + 7;

ll fact[100004];
ll modinv[100004];

ll power(ll base, ll x){
    ll ans = 1;
    while(x > 0){
        if(x % 2 == 0){
            base = (base * base)%mod;
            x = x / 2;
        }else{
            ans = (ans * base) % mod;
            x--;
        }
    }
    return ans;
}

void precomp(){
    fact[0] = 1;
    for(int i = 1; i <= 100000; i++){
        fact[i] = (fact[i-1]*i)%mod;
        modinv[i] = power(fact[i], mod-2);
    }
}


ll ncr(int n, int r){
    ll numo = fact[n];
    ll ans = (((numo * modinv[r])%mod)*modinv[n-r]) % mod;
    return ans;
}



signed main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);  

    
    //code here
    int t;
    cin >> t;
    precomp();
    while(t--){
        int n, r;
        cin >> n >> r;
        cout << ncr(n, r) << endl;
    }
    

    //end
    return 0;

}


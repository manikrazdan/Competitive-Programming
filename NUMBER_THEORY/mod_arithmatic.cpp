ll mod = 1e9 + 7;

ll fact[1000004];
ll modinv[1000004];

ll power(ll base, ll x){
    ll ans = 1;
    while(x){
        if(x % 2 == 0){
            base = (base * base) % mod;
            x = x / 2;
        }else{
            ans = (ans * base) % mod;
            x--;
        }
    }
    return ans;
}

void precomp(){
    modinv[0] = 1;
    fact[0] = 1;
    for(int i = 1; i <= 1000000; i++){
        fact[i] = (fact[i-1]*i)%mod;
        modinv[i] = power(fact[i], mod-2);
    }
}

ll ncr(int n, int r){
    ll numo = fact[n];
    ll ans = (((numo * modinv[r])%mod)*modinv[n-r]) % mod;
    return ans;
}

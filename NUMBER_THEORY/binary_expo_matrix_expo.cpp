//binary Exponentiation
ll power(ll base, ll x){
    ll ans = 1;
    while(x){
        if(x % 2 == 0){
            base = base * base;
            x = x / 2;
        }else{
            ans = ans * base;
            x--;
        }
    }
    return ans;
}

//Matrix Exponentiation

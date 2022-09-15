//Euclid's Algorithm
ll gcd(ll a, ll b){
    if (a == 0ll){ 
        return b;
    }
    return gcd(b % a, a);
}

//Extended Euclid's Algorithm (ax +by = gcd(a, b))
ll gcd(ll a, ll b, ll& x, ll& y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b % a, a, x1, y1);
    y = x1;
    x = y1 - (b/a) * x1;
    return d;
}

//Linear Diophantine Equation one solution -> x = x0 * c / g and y = y0 * c / g
//many solutions -> x = x0 + k*b/g and y = y0 - k*a/g

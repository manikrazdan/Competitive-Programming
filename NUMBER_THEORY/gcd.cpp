//Euclid's Algorithm
ll gcd(ll a, ll b){
    if (a == 0ll){ 
        return b;
    }
    return gcd(b % a, a);
}

//Extended Euclid's Algorithm

//get factors of a number (check for prime) TC -> O(root(N))
vector<int> factors;
for(int i = 1; i * i <= n; i++){
    if(n % i == 0){
        factors.push_back(i);
        if(n/i != i){
            factors.push_back(n/i);
        }
    }
}

//sieve with optimizations ->
int sieve[1000004] = {0};
for(int i = 2; i <= 1000000; i++){
    sieve[i] = 1;
}
for(int i = 2; i * i <= 1000000; i++){
    if(sieve[i] == 0) continue;
    for(int j = i * i; j <= 1000000; j += i){
        sieve[j] = 0;
    }
}

//Prime factorization ->
vector<int> vec;
for(int i = 2; i * i <= n; i++){
    while(n % i == 0){
        vec.push_back(i);
        n = n / i;
    }
}
if(n > 1) vec.push_back(n);

//smallest prime factor sieve ->
int spf[1000004];
for(int i = 2; i <= 1000000; i++){
    spf[i] = i;
}
for(int i = 2; i * i <= 1000000; i++){
    if(spf[i] != i) continue;
    for(int j = i*i; j <= 1000000; j += i){
        if(spf[j] == j){
            spf[j] = i;
        }
    }
}

//segmented sieve ->

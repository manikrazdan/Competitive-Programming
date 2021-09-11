#include <bits/stdc++.h>
using namespace std;
#define ll long long

int sieve[100001];
int N = 100000;

void fillsieve(){
    sieve[0] = 0;
    sieve[1] = 0;
    for(int i = 2; i <= N; i++){
        sieve[i] = 1;
    }
    for(int i = 2; i*i <= N; i++){
        if(sieve[i] == 0){
            continue;
        }
        for(int j = i*i; j <= N; j+= i){
            sieve[j] = 0;
        }
    }
}


void solve(){
    int l, r;
    cin >> l >> r;
    int size = r-l+1;
    int ss[size];
    for(int i = 0; i < size; i++){
        ss[i] = 1;
    }
    vector<int> primes;
    for(int i = 2; i*i <= r; i++){
        if(sieve[i] == 1){
            primes.push_back(i);
        }
    }
    for(auto pr : primes){
        int initial = (l/pr)*pr;
        if(initial < l){
            initial += pr;
        }
        initial = max(pr*pr, initial);
        for(int i = initial-l; i < size; i += pr){
            ss[i] = 0;
        }
    }
    int cnt = 0;
    for(int i = 0; i < size; i++){
        if(ss[i] == 1){
            cnt++;
        }
    }
    cout << cnt << endl;
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
    fillsieve();
    while(t--){
        solve();
    }

    // solve();

    //end
    return 0;

}

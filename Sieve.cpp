#include <bits/stdc++.h>
using namespace std;
#define ll long long

int sieve[1000001];

void fillSieve(){
    sieve[0] = 0;
    sieve[1] = 0;
    int N = 1000000;
    for(int i = 2; i <= N; i++){
        sieve[i] = 1;
    }
    for(int i = 2; i*i <= N; i++){
        if(sieve[i] == 0){
            continue;
        }
        for(int j = i*i; j <= N; j+=i){
            sieve[j] = 0;
        }
    }
}

void solve(){
    int x;
    cin >> x;
    if(sieve[x] == 1){
        cout << "PRIME" << endl;
        return;
    }
    cout << "NOTPRIME" << endl;
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
    fillSieve();
    while(t--){
        solve();
    }

    // solve();

    //end
    return 0;

}

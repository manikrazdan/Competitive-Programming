#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N = 1000000;

int spf[1000001];


void fillSpf(){
    for(int i = 0; i < N; i++){
        spf[i] = i;
    }
    for(int i = 2; i*i < N; i++){
        if(spf[i] != i){
            continue;
        }
        for(int j = i*i; j < N; j+=i){
            if(spf[j] == j){
                spf[j] = i;
            }
        }
    }
}


void solve(){
    int n;
    cin >> n;
    while(n!= 1){
        cout << spf[n] << " ";
        n = n / spf[n];
    }
    cout << endl;
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
    fillSpf();
    while(t--){
        solve();
    }

    // solve();

    //end
    return 0;

}

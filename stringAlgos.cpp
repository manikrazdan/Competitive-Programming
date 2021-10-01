#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1e9 + 7;

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

ll blackbox(string s){
    int n = s.length();
    ll hash = 0;
    ll pr = 1;
    for(int i = 0; i < n; i++){
        hash = (hash + ((s[i]-'a'+1)*pr)%mod)%mod;
        pr = (pr*31)%mod;
    }
    return hash;
}



void rabinkarp(string s, string p){
    int plen = p.length();
    int slen = s.length();
    ll phash = blackbox(p);
    ll shash = blackbox(s.substr(0, plen));
    int cnt = 0;
    vector<pair<int, int>> pos;
    if(phash == shash){
        cnt++;
        pos.push_back({0, plen-1});
    }
    ll prL = 1;
    ll prR = power(31, plen);
    
    for(int i = plen; i < slen; i++){
        shash = (shash - ((s[i-plen] - 'a' + 1)*prL)%mod + mod)%mod;
        shash = (shash + ((s[i]-'a'+1)*prR)%mod)%mod;
        phash = (phash*31)%mod;
        if(shash == phash){
            cnt++;
            pos.push_back({i-plen+1, i});
        }
        prL = (prL*31)%mod;
        prR = (prR*31)%mod;
    }
    cout << cnt << endl;
    for(int i = 0; i < pos.size(); i++){
        cout << pos[i].first+1 << " " << pos[i].second+1 << endl;
    }
}

void solve(){
    
}
 
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
 
    //code here



    // int t;
    // cin >> t;
    // while(t--){
    //     solve();
    // }

    


    //end
    return 0;
 
}

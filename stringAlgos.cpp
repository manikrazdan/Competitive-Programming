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


vector<int> longestprefixsuffix(string s){
    int n = s.length();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;
    while(i < n){
        if(s[i] == s[len]){
            lps[i] = len + 1;
            i++;
            len++;
        }else{
            if(len != 0){
                len = lps[len-1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}


void kmp(string s, string p){
    int plen = p.length();
    int slen = s.length();
    vector<int> pattern_lps = longestprefixsuffix(p);
    int len = 0;
    int i = 0;
    int cnt = 0;
    while(i < slen){
        if(s[i] == p[len]){
            i++;
            len++;
        }else{
            if(len != 0){
                len = pattern_lps[len-1];
            }else{
                i++;
            }
        }
        if(len >= plen){
            cnt++;
            len = pattern_lps[len-1];
        }
    }
    cout << cnt << endl;
}


vector<int> zalgo(string s){
    int n = s.length();
    int i = 1;
    int l = 0, r = 0;
    vector<int> z(n, 0);
    while(i < n){
        if(i <= r){
            z[i] = min(z[i-l], r-i+1);
        }
        while(i + z[i] < n && s[i+z[i]] == s[z[i]]){
            z[i]++;
        }
        if(i+z[i] -1 > r){
            l = i;
            r = i+z[i]-1;
        }
        i++;
    }
    return z;
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

//Blackbox function ->
ll blackbox(string &s){
    ll ans = 0;
    ll pr = 1;
    for(int i = 0; i < s.size(); i++){
        ans = (ans + ((s[i] - 'a'+ 1ll) * pr) % mod) % mod;
        pr = (pr * 31ll) % mod;
    }
    return ans;
}

//power function ->
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

//rabin Karp algorithm
void rabinkarp(){
    string s, p;
    cin >> s >> p;
    int plen = p.length();
    int slen = s.length();
    ll phash = blackbox(p);
    string temp = s.substr(0, plen);
    ll shash = blackbox(temp);
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

//lps ->
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

//kmp (optimized) ->
void kmp(){
    string s, p;
    cin >> s >> p;
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

//z function ->
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

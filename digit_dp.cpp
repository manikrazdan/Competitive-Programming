//question -> given l and r, find count of number such that digit d appears exactly k times.
// 1 <= l <= r <= 1e18 and 0 <= d <= 9 (ignore leading zeros) and 1 <= k <= 18

ll dp[20][20][2][2];

ll digit_dp(string s, ll ind, ll cnt, ll d, ll k, bool flag, bool start){
    if(ind == s.size()){
        return cnt == k;
    }
    if(dp[ind][cnt][flag][start] != -1){
        return dp[ind][cnt][flag][start];
    }
    ll limit = s[ind] - '0';
    if(flag){
        limit = 9;
    }
    ll ans = 0;
    for(ll digit = 0; digit <= limit; digit++){
        if(digit < s[ind] - '0'){
            // true block
            if(start || (!start && digit != 0)){
                if(digit == d){
                    ans += digit_dp(s, ind + 1, cnt + 1, d, k, true, true);
                }else{
                    ans += digit_dp(s, ind + 1, cnt, d, k, true, true);
                }
            }else{
                ans += digit_dp(s, ind + 1, cnt, d, k, true, false);
            }
        }else{
            // flag block
            if(start || (!start && digit != 0)){
                if(digit == d){
                    ans += digit_dp(s, ind + 1, cnt + 1, d, k, flag, true);
                }else{
                    ans += digit_dp(s, ind + 1, cnt, d, k, flag, true);
                }
            }else{
                ans += digit_dp(s, ind + 1, cnt, d, k, flag, false);
            }
        }
    }
    return dp[ind][cnt][flag][start] = ans;
}

void solve(){
    ll l, r;
    cin >> l >> r;
    ll d, k;
    cin >> d >> k;
    memset(dp, -1, sizeof dp);
    ll ans = digit_dp(to_string(r), 0, 0, d, k, false, false);
    if(l != 1){
        memset(dp, -1, sizeof dp);
        ans -= digit_dp(to_string(l-1), 0, 0, d, k, false, false);
    }
    cout << ans << endl;
}

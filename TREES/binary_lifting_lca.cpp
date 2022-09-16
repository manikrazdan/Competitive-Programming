//binary lifting ->
int par[1000000][30];
 
void dfs(int root, int parent, vector<int> adj[]){
    par[root][0] = parent;
    for(int i = 1; i <= 29; i++){
        par[root][i] = par[par[root][i-1]][i-1];
    }
 
    for(auto it : adj[root]){
        if(it != parent){
            dfs(it, root, adj);
        }
    }
}

//printing kth ancestor of x ->
void kth(){
    int x, k;
    cin >> x >> k;
    int cnt = 0;
    while(k){
        if(k&1){
            x = par[x][cnt];
        }
        cnt++;
        k = k >> 1;
    }
    if(x == 0){
        cout << -1 << endl;
    }else{
        cout << x << endl;
    }
}

//finding lca of a and b ->
void lca(){
        ll a, b;
        cin >> a >> b;
        if(level[a] < level[b]){
            swap(a, b);
        }
        ll k = level[a] - level[b];
        a = kth(a, k, dp);
        if(a == b){
            cout << a << endl;
            continue;
        }
        for(ll i = 20; i >= 0; i--){
            if(dp[a][i] != dp[b][i]){
                a = dp[a][i];
                b = dp[b][i];
            }
        }
        cout << dp[a][0] << endl;
}

int in[200005];
int out[200005];

void indfs(int node, int par, vector<int> adj[]){
    in[node] = 0;
    for(auto it : adj[node]){
        if(it != par){
            indfs(it, node, adj);
            in[node] = max(in[node], 1 + in[it]);
        }
    }
}

void outdfs(int node, int par, vector<int> adj[]){
    int mx1 = -1, mx2 = -1;
    int child = -1;
    for(auto it : adj[node]){
        if(it != par){
            if(in[it] + 1> mx1){
                mx2 = mx1;
                mx1 = in[it] + 1;
                child = it;
            }else if(in[it] + 1> mx2){
                mx2 = in[it] + 1;
            }
        }
    }
    for(auto it : adj[node]){
        if(it != par){
            int longest = mx1;
            if(child == it){
                longest = mx2;
            }
            out[it] = 1 + max(out[node], longest);
            outdfs(it, node, adj);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    vector<int> adj[n+1];
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    indfs(1, 0, adj);
    outdfs(1, 0, adj);
    for(int i = 1; i <= n; i++){
        cout << max(in[i], out[i]) << " ";
    }
}

stack<int> st;
int vis[100005];
vector<vector<int>> scc;
vector<int> temp;

void finishdfs(int node, vector<int> adj[]){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(vis[it] == 0){
            finishdfs(it, adj);
        }
    }
    st.push(node);
}

void dfs(int node, vector<int> adj[]){
    vis[node] = 1;
    temp.pb(node);
    for(auto it : adj[node]){
        if(vis[it] == 0){
            dfs(it, adj);
        }
    }
}

void kosaraju(){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1], tadj[n+1];
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        tadj[v].pb(u);
    }
    memset(vis, 0, sizeof vis);
    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            finishdfs(i, adj);
        }
    }
    memset(vis, 0, sizeof vis);
    while(st.empty() == false){
        int node = st.top();
        st.pop();
        if(vis[node] == 0){
            dfs(node, tadj);
            scc.pb(temp);
            temp.clear();
        }
    }
    for(auto arr : scc){
        for(auto x : arr){
            cout << x << " ";
        }   
        br
    }
}

//flat tree ->
ll cnt = 0;
vector<ll> flatTree;
 
void dfs(ll node, ll par, vector<ll> adj[], vector<pair<ll, ll>> &index){
    index[node].ff = cnt;
    flatTree.pb(node);
    cnt++;
    for(auto it : adj[node]){
        if(it != par){
            dfs(it, node, adj, index);
        }
    }
    index[node].ss = cnt;
    flatTree.pb(node);
    cnt++;
}

//calculation of in dp vector ->
void indfs(int node, int par, vector<int> adj[], vector<int> &indp){
    for(auto it : adj[node]){
        if(it != par){
            indfs(it, node, adj, indp);
            indp[node] = max(indp[node], 1 + indp[it]);
        }
    }
}

//calculation for out dp vector ->
void outdfs(int node, int par, vector<int> &indp, vector<int> &outdp, vector<int> adj[]){
    int mx1 = -1, mx2 = -1, child = -1;
    for(auto it : adj[node]){
        if(it != par){
            if(indp[it] + 1 > mx1){
                child = it;
                mx2 = mx1;
                mx1 = indp[it] + 1;
            }else if(indp[it] + 1 > mx2){
                mx2 = indp[it] + 1;
            }
        }
    }
    for(auto it : adj[node]){
        if(it == par) continue;
        int longest = mx1;
        if(it == child){
            longest = mx2;
        }
        outdp[it] = 1 + max(outdp[node], longest);
        outdfs(it, node, indp, outdp, adj);
    }
}

vector<int> dijkstra(int n, vector<pair<int, int>> adj[], int s){
    vector<int> distance(n, INT_MAX);
    distance[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    vector<int> vis(n, 0);
    while(pq.empty() == false){
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if(vis[node]){
            continue;
        }
        vis[node] = 1;
        for(auto it : adj[node]){
            if(d + it.second < distance[it.first]){
                distance[it.first] = d + it.second;
                pq.push({distance[it.first], it.first});
            }
        }
    }
    return distance;
}

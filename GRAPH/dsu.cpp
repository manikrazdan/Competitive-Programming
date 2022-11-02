class dsu{
    vector<int> parent, size, rank;

public:
    dsu(int n){
        for(int i = 0; i <= n; i++){
            size.push_back(1);
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    int findpar(int node){
        if(parent[node] == node){
            return node;
        }

        return parent[node] = findpar(parent[node]);
    }

    void unionsize(int u, int v){
        int pu = findpar(u);
        int pv = findpar(v);

        if(pu == pv){
            return;
        }

        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    void unionrank(int u, int v){
        int pu = findpar(u);
        int pv = findpar(v);

        if(pu == pv){
            return;
        }
        if(rank[pu] == rank[pv]){
            parent[pv] = pu;
            rank[pu]++;
        }else if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }else{
            parent[pv] = pu;
        }
    }
};

class SegTree{
    vector<ll> seg;
public:
    SegTree(int n){
        seg.resize(4*n + 1);
    }

public:
    void build(int ind, int low, int high, ll arr[]){
        if(low == high){
            seg[ind] = arr[low];
            return;
        }

        int mid = (low + high) >> 1;

        build(2*ind + 1, low, mid, arr);
        build(2*ind + 2, mid + 1, high, arr);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

public:
    ll answerquery(int ind, int low, int high, int l, int r){
        if(low >= l && high <= r){
            return seg[ind];
        }
        if(r < low || high < l){
            return 0;
        }
        int mid = (high + low) >> 1;

        return answerquery(2*ind + 1, low, mid, l, r) + 
        answerquery(2*ind + 2, mid + 1, high, l, r);
    }

public:
    void update(int ind, int low, int high, int i, ll val, ll arr[]){
        if(low == high){
            seg[ind] = val;
            arr[i] = val;
            return;
        }

        int mid = (low + high) >> 1;
        
        if(i <= mid){
            update(2*ind + 1, low, mid, i, val, arr);
        }else{
            update(2*ind + 2, mid + 1, high, i, val, arr);
        }
        seg[ind] = seg[ind*2 + 1] + seg[2*ind + 2];
    }
};

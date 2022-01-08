class lazysegmenttree{
    vector<int> seg, lazy;
public:
    lazysegmenttree(int n){
        seg.resize(4*n + 1);
        lazy.resize(4*n + 1);
    }

public:
    void build(int ind, int low, int high, int arr[]){
        if(high == low){
            seg[ind] = arr[low];
            return;
        }

        int mid = (low + high) >> 1;

        build(2*ind + 1, low, mid, arr);
        build(2*ind + 2, mid + 1, high, arr);

        seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];
    }

public:
    void update(int ind, int low, int high, int l, int r, int val){
        if(lazy[ind] != 0){
            seg[ind] += (high - low + 1)*lazy[ind];
            if(high != low){
                lazy[2*ind + 1] += lazy[ind];
                lazy[2*ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        if(low >= l and high <= r){
            seg[ind] += (high - low + 1)*val;
            if(high != low){
                lazy[2*ind + 1] += val;
                lazy[2*ind + 2] += val;
            }
            return;
        }
        if(low > r || high < l){
            return;
        }
        int mid = (high + low) >> 1;
        update(2*ind + 1, low, mid, l, r, val);
        update(2*ind + 2, mid + 1, high, l, r, val);

        seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];
    }

public:
    int answerquery(int ind, int low, int high, int l, int r){
        if(lazy[ind] != 0){
            seg[ind] += (high - low + 1)*lazy[ind];
            if(high != low){
                lazy[2*ind + 1] += lazy[ind];
                lazy[2*ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        if(low >= l and high <= r){
            return seg[ind];
        }
        if(low > r || high < l){
            return 0;
        }
        int mid = (high + low) >> 1;
        int left = answerquery(2*ind + 1, low, mid, l, r);
        int right = answerquery(2*ind + 2, mid + 1, high, l, r);

        return left + right;
    }
};

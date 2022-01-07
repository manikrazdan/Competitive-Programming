class ST{
    vector<int> seg;
public:
    ST(int n){
        seg.resize(4*n + 1);
    }

public:
    void build(int ind, int low, int high, int arr[]){
        if(low == high){
            seg[ind] = arr[low];
            return;
        }

        int mid = (low + high) >> 1;

        build(2*ind + 1, low, mid, arr);
        build(2*ind + 2, mid + 1, high, arr);
        seg[ind] = max(seg[2*ind+1] , seg[2*ind+2]);
    }

public:
    int answerquery(int ind, int low, int high, int l, int r, int arr[]){
        if(low >= l && high <= r){
            return seg[ind];
        }
        if(r < low || high < l){
            return INT_MIN;
        }
        int mid = (high + low) >> 1;

        return max(answerquery(2*ind + 1, low, mid, l, r, arr), 
            answerquery(2*ind + 2, mid + 1, high, l, r, arr));
    }

public:
    void update(int ind, int low, int high, int i, int val, int arr[]){
        if(low == high){
            seg[i] = val;
            arr[i] = val;
            return;
        }

        int mid = (low + high) >> 1;
        
        if(i <= mid){
            update(2*ind + 1, low, mid, i, val, arr);
        }else{
            update(2*ind + 2, mid + 1, high, i, val, arr);
        }
        seg[ind] = max(seg[ind*2 + 1], seg[2*ind + 2]);
    }

};

class sparsetable{
    vector<vector<int>> sparse;
    int lg;
public:
    sparsetable(int n){
        lg = log2(n);
        for(int i = 0; i < n; i++){
            vector<int> vec(lg+1);
            sparse.push_back(vec);
        }
    }
public:
    void print(){
        for(int i = 0; i < sparse.size(); i++){
            for(int j = 0; j < sparse[0].size(); j++){
                cout << sparse[i][j] << " ";
            }
            br
        }
    }

public:
    void build(int arr[], int n){
        for(int j = 0; j <= lg; j++){
            for(int i = 0; i < n; i++){
                if(i + (1 << j) - 1 >= n){
                    break;
                }
                if(j == 0){
                    sparse[i][j] = arr[i];
                }else{
                    sparse[i][j] = min(sparse[i][j-1], sparse[i + (1 << (j-1))][j-1]);
                }
            }
        }
    }
public:
    int ansquery(int l, int r){
        int cnt = r - l + 1;
        int templg = log2(cnt);
        int ans = min(sparse[l][templg], sparse[r - (1 << templg) + 1][templg]);
        return ans;
    }
};

void solve(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sparsetable st(n);
    st.build(arr, n);

    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;

        cout << st.ansquery(l, r) << endl;
    }
}

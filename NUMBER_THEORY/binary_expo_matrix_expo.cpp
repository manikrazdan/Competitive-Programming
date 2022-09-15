//binary Exponentiation
ll power(ll base, ll x){
    ll ans = 1;
    while(x){
        if(x % 2 == 0){
            base = base * base;
            x = x / 2;
        }else{
            ans = ans * base;
            x--;
        }
    }
    return ans;
}

//Matrix Exponentiation -> time complexity of multi function will be -> n1 * n2 * n3
vector<vector<int>> multi(vector<vector<int>> &a, vector<vector<int>> &b){
    int n1 = a.size();
    int n2 = b.size();
    int n3 = b[0].size();
    vector<vector<int>> ans(n1, vector<int>(n3));
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n3; j++){
            for(int k = 0; k < n2; k++){
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return ans;
}

int matrixexpo(int x){
    int n = x - 1;
    vector<vector<int>> mat = {{1, 1}, {1, 0}};
    vector<vector<int>> base = {{1, 0}, {0, 1}};
    while(n > 0){
        if(n % 2 == 0){
            mat = multi(mat, mat);
            n = n / 2;
        }else{
            base = multi(base, mat);
            n--;
        }
    }
    return base[0][0];
}

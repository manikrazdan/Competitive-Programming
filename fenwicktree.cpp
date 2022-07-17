class fenwickTree{
    vector<ll> ft;
    int n;
public:
    fenwickTree(int x){
        n = x;
        ft.resize(x + 1);
        fill(all(ft), 0);
    }
public:
    void update(int i, ll val){
        while(i <= n){
            ft[i] += val;
            i += i & (-i);
        }
    }
private:
    ll answerUtil(int i){
        ll sum = 0;
        while(i >= 1){
            sum += ft[i];
            i -= i & (-i);
        }
        return sum;
    }
public:
    ll getanswer(int l, int r){
        return answerUtil(r) - answerUtil(l - 1);
    }
};

//how does ft is better than st? -> watch the space complexity.

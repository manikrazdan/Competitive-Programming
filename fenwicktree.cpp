class fenwicktree{
    vector<int> fen;
    int n;
public:
    fenwicktree(int x){
        fen.resize(x+1);
        n = x;
    }

public:
    void update(int ind, int val){
        while(ind <= n){
            fen[ind] += val;
            ind += ind & (-ind);
        }
    }
public:
    int sum(int ind){
        int s = 0;
        while(ind >= 1){
            s += fen[ind];
            ind -= ind & (-ind);
        }
        return s;
    }
public:
    int answerquery(int l, int r){
        return sum(r) - sum(l - 1);
    }
};

//how does ft is better than st? -> watch the space complexity.

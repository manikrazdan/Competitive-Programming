#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pyes cout << "YES" << "\n";
#define pno cout << "NO" << "\n";
#define br cout << "\n";

void multi(int a[2][2], int b[2][2]){
    int aa[2][2];
    aa[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    aa[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    aa[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    aa[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            a[i][j] = aa[i][j];
        }
    }
}

int matrixexpo(int x){
    int n = x - 1;
    int mat[2][2] = {{1, 1}, {1, 0}};
    int base[2][2] = {{1, 0}, {0, 1}};
    while(n > 0){
        if(n % 2 == 0){
            multi(mat, mat);
            n = n / 2;
        }else{
            multi(base, mat);
            n--;
        }
    }
    return base[0][0];
}

void solve(){
    int n;
    cin >> n;
    cout << matrixexpo(n) << endl;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    //code here
    // ll t;
    // cin >> t;
    // while(t--){
    //     solve();
    // }
    solve();

    //end
 
    return 0;
 
}

#include <bits/stdc++.h>

#define int long long
using namespace std;


signed main(){
    int n,q;
    cin >> n >> q;
    int forest[n+1][n+1];
    memset(forest, 0, sizeof(forest));
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            char ch;
            cin >> ch;
            forest[i][j] = (ch == '*')? 1:0;
        }
    }

   /* int pref[n+1][n+1];
    memset(pref, 0,sizeof(pref));
    */
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            forest[i+1][j+1] += forest[i][j];
            forest[i+1][j]+=(j-1 >=0)?forest[i][j] - forest[i][j-1]:forest[i][j];
            forest[i][j+1]+= (i-1 >=0)?forest[i][j] -forest[i-1][j]:forest[i][j];
//            cout << forest[i][j] << " ";
        }
  //      cout << endl;

    }

    while(q--){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;
        r1--; c1--;
         
        int ans = forest[r2][c2];
    //    cout << ans << '\n';
//        cout << ans << '\n';
        if(c1 >= 0) ans -= forest[r2][c1];
        if(r1 >= 0) ans -= forest[r1][c2];
        if(r1 >= 0 && c1 >=0) ans += forest[r1][c1];
        cout << ans << '\n';
    }

}

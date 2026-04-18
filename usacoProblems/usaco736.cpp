#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n, m;
    cin >> n >> m;
    char arr1[n][m], arr2[n][m];

    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr1[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr2[i][j];
        }
    }
    int ans=0;
    for(int i = 0;i<m;i++){
        int t = 1;
        for(int j=0;j<n;j++){
            int p = 0;
            for(int k=0;k<n;k++){
                if(arr1[j][i] == arr2[k][i]){
                   p =1;
                   break;
                }
            }
            if(p){t=0;break;}
        }
        if(t) ans++;
    }
    cout << ans;
}

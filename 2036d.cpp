#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            cin >> a[i][j];
        }
    }
    int num[4] = {1,5,4,3};
    int i=0, j=0;

    while(i<n/2 && j < m/2){
        int c[4];
        int cur = 0;
        int t = j;
        for(int k =j;k<m-j;k++){
            if(a[k]
            t++;
        }
        int p = i;
        for(int k = i;k<n-i;k++){
            p++;
        }

        for(int k = t;k>=j;k--){

        }
        for(int k = p;k>=i;k--){
            
        }

        i++; j++;
    }


}
int main(){
    int tc;
    cin >> tc;

    while(tc--){
        solve();
    }
}

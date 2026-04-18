#include <bits/stdc++.h>

using namespace std;
int s[101];
int main(){
    int n, m;

    cin >> n >> m;
    int a[3][n], b[4][m];
    for(int i =0;i<n;i++) cin >> a[0][i] >> a[1][i] >> a[2][i];
    for(int i =0;i<m;i++) cin >> b[0][i] >> b[1][i] >> b[2][i] >> b[3][i];
    
    for(int i =0;i<n;i++){
        for(int j = a[0][i]; j <=a[1][i]; j++){
            s[j]=a[2][i];
        }
    }
    int ans = INT_MAX;
    int t[101];
    copy(s, s+101, t); 
    for(int i =0;i<(1<<m);i++){
        int c = 0;
        for(int j = 0;j<m;j++){
            if((i>>j) & 1){
                c+=b[3][j];
                for(int k =b[0][j]; k<=b[1][j];k++){
                    t[k] -= b[2][j];
                }
            }

        }
        //cout << c << '\n';
        int p = 1;
        for(int j =0;j<101;j++){
            if(t[j] > 0){
                p=0;
                break;
            }
        }
        //cout << p << '\n';
        if(p) ans = min(ans,c);
        copy(s, s+101, t);
    }

    cout << ans << '\n';
}

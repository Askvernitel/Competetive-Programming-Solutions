#include <bits/stdc++.h>

using namespace std;

int main(){
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    int m = n1+n2;
    int f[n1+1][n2+1], a[n1+1][n2+1], b[n1+1][n2+1];
    memset(f, 0, sizeof(f)); memset(a, 0, sizeof(a)); memset(b,0,sizeof(b));
    f[0][0] = 1;
    a[0][0] = 0;
    b[0][0] = 0;
    for(int i =0;i<=n1;i++){
        for(int j =0;j<=n2;j++){
            if(i+1<=n1 && b[i][j] < k1)f[i+1][j] += f[i][j];
            a[i+1][j] = 0; b[i+1][j] = b[i][j] + 1;
            if(j+1<=n2 && a[i][j] < k2)f[i][j+1] += f[i][j];
            b[i][j+1] = 0; a[i][j+1] = a[i][j] + 1;
        }
    }
/*    for(int i =0;i<=n1;i++){
        for(int j =0;j<=n2;j++){
            cout << f[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << f[n1][n2];
}

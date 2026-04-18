#include <bits/stdc++.h>
#define int long long
using namespace std;
int diff[100005], diffk[100005];
signed main(){
    int n, m,k;

    cin >> n >> m >> k;

    int b[n];
    for(int i =0;i<n;i++){
        cin >> b[i];
    }
    int a[3][m];
    int t = 0, op=m;
    while(op--){ 
        int l, r, d;
        cin >> l >> r >> d;
        l--;r--;
        a[0][t] = l;
        a[1][t] = r;
        a[2][t] = d;
        t++;
    }
    while(k--){
        int x, y;
        cin >> x >> y;
        x--;y--;
        diffk[x] += 1;
        diffk[y+1] -=1;
    }
    int f = 0;
    for(int i =0;i<m;i++){
        f+=diffk[i];
        diffk[i] = f;
    }

    for(int i = 0;i<m;i++){
        a[2][i] *= diffk[i];
    }
    int z=0;
    while(z < m){ 

        diff[a[0][z]] += a[2][z];
        diff[a[1][z]+1] -= a[2][z];
        z++;
    }
    int g = 0;
    for(int i = 0;i<n;i++){
        g += diff[i];
        cout << b[i] + g << " ";
    }




}

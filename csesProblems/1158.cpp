#include <bits/stdc++.h>

using namespace std;
int f[100001][1001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, x;
    scanf("%d%d", &n, &x);
    int c[n], p[n];
    for(int i =0;i<n;i++) scanf("%d", &c[i]);
    for(int i =0;i<n;i++) scanf("%d", &p[i]);



    int ans = 0;
    for(int i =0;i<=x;i++){
        for(int j=0;j<n;j++){
            f[i][j+1] = max(f[i][j+1], f[i][j]);
            if(i+c[j] <= x) f[i+c[j]][j+1] = f[i][j] + p[j];
        }
        ans = max(ans, f[i][n]);
    }
    /*for(int i =0;i<=x;i++){
        ans = max(ans, f[i][n]);
    }*/
    printf("%d",ans);
}

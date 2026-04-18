#include <bits/stdc++.h>

using namespace std;


int main(){
freopen("diamond.in", "r", stdin);
freopen("diamond.out", "w", stdout);
    int n, k;
    cin >> n>> k;

    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    int ans = 0;
    for(int i =0;i<n;i++){
        int p = 0;
        for(int j = 0;j<n;j++){
           // if(j == i) continue;
            if(a[i] <= a[j] && a[j]-a[i] <= k){
                p++;
            }
        }
        ans = max(ans,p);
    }
    cout << ans;
}

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;

    cin >> n >> k;
    
    int a[n], b[n];

    for(int i =0;i<n;i++) cin>>a[i];
    for(int i =0;i<n;i++) cin>>b[i];
    int c[n], t[n];
    for(int i =0;i<n;i++){
        c[i] = b[i]/a[i];
        t[i] = b[i]%a[i];
    }
    for(int i=0;i<k;i++){
        int v[n];
        memset(v, 0, sizeof(v));
        int x = INT_MAX;
        for(int j =0;j<n;j++) x = min(x, c[j]);
        for(int j =0;j<n;j++) if(x==c[j]) v[j] = 1;
        int y = INT_MAX, p = 0;
        for(int j =0;j<n;j++){
            if(v[j] && a[j]-t[j] < y){
                p = j;
                y = a[j]-t[j];
            }
        }
        t[p]++;
        c[p]+=(t[p]/a[p]);
        t[p]%=a[p];
    }

    int ans = INT_MAX;

    for(int i =0;i<n;i++){
        ans = min(ans,c[i]);
    }

    cout << ans;
    

}

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int a[n+1];
    a[n] = k;
    for(int i =0;i<n;i++) cin >> a[i];

    int l = 0, r =0, cur = k;
    int ans = 0;
    while(r < n){
        if(cur - a[r] >= 0){
            cur-=a[r];
            r++;
            ans = max(r-l,ans);
        }else{
            if(l != r){
                cur+=a[l];
                l++;
            }else{
                l++;
                r++;
            }
        }

    }

    cout << ans << '\n';
}

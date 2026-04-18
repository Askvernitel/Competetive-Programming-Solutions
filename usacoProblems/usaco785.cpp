#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i =0;i<n;i++) cin >> a[i];
    copy(a, a+n, b);
    sort(a,a+n);
    int cnt = 0;
    for(int i =0;i<n;i++){
        if(a[i] != b[i]) cnt++;
    }

    cout << cnt-1;
}

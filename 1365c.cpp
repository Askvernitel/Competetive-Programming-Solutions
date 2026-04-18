#include <bits/stdc++.h>

using namespace std;
int arr[200001];
int main(){
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0;i<n;i++) cin >> a[i];

    for(int i = 0;i<n;i++) cin >> b[i];

    for(int i =0;i<n;i++) arr[a[i]] = i;

    int d[n];
    memset(d, 0, sizeof(d));
    for(int i =0;i<n;i++){
        int j = arr[b[i]];
        if(i < j) d[i + n-j]++;
        else d[i-j]++;
    }
    int ans = 0;
    for(int i =0;i<n;i++) ans = max(d[i], ans);

    cout << ans;
}

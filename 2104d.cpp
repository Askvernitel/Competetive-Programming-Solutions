#include <bits/stdc++.h>
#define int long long
using namespace std;
int arr[6000000];
int pref[420000];
void eratos(){
    memset(arr,0,sizeof(arr));
    memset(pref,0,sizeof(pref));
    int t = 1;
    for(int i=2;i<6000000;i++){
        if(arr[i] ==1){
            continue;
        }
        int cur = i;
        pref[t]=pref[t-1]+cur;
        for(int j =cur+cur;j<6000000;j+=cur){
            arr[j] = 1;
        }
        t++;
    }
}
void solve(){
    int n;
    cin >> n;

    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    sort(a, a+n, greater<int>());
    int csum = 0;

    int tt = n;
    for(int i =0;i<n;i++){
        csum+=a[i];
        if(pref[i+1] > csum){ 
            tt = i;
            break;
        }
    }
    cout << n - tt << '\n';
}

signed main(){
    ios_base::sync_with_stdio(true);
    eratos();
    int tc;
    cin >> tc;
    while(tc--) solve();
}

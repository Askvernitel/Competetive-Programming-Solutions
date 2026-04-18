#include <bits/stdc++.h>
#define int long long

using namespace std;
void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    int f = n;
    for(int i =0;i<n;i++){
        if(s[i] == '0'){
            f=min(i,f);
            a[i]=-1e13;
        }
    }
    int suf[n+1];
    suf[n] =0;
    int maxv=0;
    int cursum = 0;
    for(int i=n-1;i>=0;i--){
        cursum+=a[i];
        if(cursum < 0){
            cursum=0;
        }
        maxv = max(maxv, cursum);
        suf[i]=maxv;
    }
    if(maxv == k){ 
        cout << "YES\n";
        for(int i =0;i<n;i++){
            cout << a[i] << " ";
        }
        cout << '\n';
        return;
    }
    bool pos = 0;
    int ind = 0;
    for(int i =f+1;i<=n;i++){
        if(s[i-1] == '0') ind = i;
        if(suf[i] <= k){ 
            pos=1;
            break;
        }
    }
    if(!pos){ 
        cout << "NO\n";
        return;
    }
    int msum=0;
    int sum = 0;
    int j = ind-2;
    int maxv1 = 0;
    for(int i = j;i>=0;i--){
        sum += a[i];
        maxv1 = max(sum, maxv1);
    }
    msum+=maxv1;
    sum = 0;
    int maxv2 = 0;
    j = ind;
    for(int i = j;i<n;i++){
        sum+=a[i];
        maxv2 = max(sum, maxv2);
    }
    msum+=maxv2;
    a[ind-1]=k-msum;
    int cc = 0;
    int mm = 0;
    for(int i =0;i<n;i++){
        cc += a[i];
        if(cc < 0){ 
            cc = 0;
        }
        mm = max(cc, mm);
    }
    if(mm != k){ 
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(int i =0;i<n;i++){
        cout << a[i] << ' ';
    }
    cout << '\n';
}
signed main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}

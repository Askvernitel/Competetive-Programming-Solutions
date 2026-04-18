#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){

    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    set<int> ans = {0};
    int idx=0;
    for(int i=0;i<n;i++){
        if(a[i] != -1 && a[i] != 1){
            idx = i;
        }
        ans.insert(a[i]);
    }
    int sum =0;
    int minv1 = 0, minv2=0, maxv1=0,maxv2=0;
    for(int i=idx-1;i>=0;i--){
        sum+=a[i];
        ans.insert(sum);
        minv1 = min(minv1, sum);
        maxv1 = max(maxv1, sum);
    }
    sum =0;
    for(int i =idx+1;i<n;i++){
        sum+=a[i];
        ans.insert(sum);
        minv2= min(minv2,sum);
        maxv2= max(maxv2,sum);
    }
    sum = 0;
    int maxv3 =0, minv3=0;
    for(int i = 0;i<n;i++){
        if(i == idx && a[i] !=-1 && a[i]!=1){
            maxv3 = max(maxv3, sum);
            minv3 = min(minv3,sum); 
            sum =0; 
            continue;
        }
        if((sum > 0 && a[i] < 0) || (sum <0 && a[i] > 0)){ 
            maxv3 = max(maxv3, sum);
            minv3 = min(minv3,sum);
            sum=0;
        }
        sum+=a[i];
    }
    maxv3 = max(maxv3, sum);
    minv3 = min(minv3,sum);
     
    for(int i =minv3;i<=maxv3;i++) ans.insert(i);
    for(int i =a[idx]+minv1+minv2;i<=a[idx]+maxv1+maxv2;i++){
        ans.insert(i);
    }

    cout << ans.size() << '\n';
    for(int x:ans){
        cout << x << " "; 
    }
    cout << '\n';
}
signed main(){
//    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;

    while(tc--){ 
        solve();
    }
}

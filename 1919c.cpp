#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1);
    a[0] =INT_MAX; b[0]=INT_MAX;
    int arr[n];
    for(int i =0;i<n;i++){
        cin >> arr[i];
    }
    int ia=0, ib = 0;
    int ans = 0;
    for(int i =0;i<n;i++){
        if(a[ia] < arr[i] && b[ib] < arr[i]){
            if(a[ia] < b[ib]){ 
                a[++ia] = arr[i];
            }else{
                b[++ib] = arr[i];
            }
            ans++;
        }else if(a[ia] >= arr[i] && b[ib] >= arr[i]){
            if(a[ia] < b[ib]){ 
                a[++ia] = arr[i];
            }else{
                b[++ib] = arr[i];
            }
        }else{
            if(a[ia] < b[ib]){ 
                b[++ib] = arr[i];
            }else{
                a[++ia] = arr[i];
            }
        }
    }
    cout << ans << '\n';
}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}

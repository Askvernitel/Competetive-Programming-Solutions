#include <bits/stdc++.h>



using namespace std;

int n;
int get_max(int* a, int r){
    int maxv = 0;
    for(int i =0;i<=r;i++){
        maxv = max(maxv,a[i]);
    }
    return maxv;
}
void solve(){
    cin >> n;
    int a[n];


    for(int i = 0;i<n;i++){
        cin >> a[i];
    }

    int ans = 0;
    for(int i = n-1;i>=0;i--){
        int maxv = get_max(a, i);

        if(a[i] == maxv){
            ans++;
        }
    }
    cout << n-ans << '\n';

}
int main(){
    int tc;
    cin >> tc;
    while(tc--) solve();
}

#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    int cnt1 = 0, maxv1 = 0;
    int cnt2 = 0, maxv2 = 0;
    for(int i =0;i<n;i+=2){
        cnt1++;
        maxv1 = max(maxv1, a[i]);
    }

    for(int i =1;i<n;i+=2){
        cnt2++;
        maxv2 = max(maxv2, a[i]);
    }
//    cout << << " ";
    cout << max(cnt1+maxv1, cnt2+maxv2) <<'\n';
}


int main(){
    int tc;
    cin >> tc;
    while(tc--) solve();

}

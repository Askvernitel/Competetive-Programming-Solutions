#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    pair<int,int> a[n];
    for(int i =0;i<n;i++){
        cin >> a[i].second >> a[i].first;
    }

    sort(a, a+n);
    int cur = 0, ans = 0;
    for(int i =0;i<n;i++){
        if(a[i].second >= cur){
//            cout << cur << " ";
            cur = a[i].first;
            ans++;
        }
    }

    cout << ans;

}

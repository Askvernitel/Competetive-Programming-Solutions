#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;
    int a[n];

    map<int, int> u;
    map<int, vector<int>> m;
    for(int i =0;i<n;i++){
        cin >> a[i];
        m[a[i]].push_back(i);
        u[a[i]]++;
    }
    int lo = -1;
    int r = INT_MAX;
    int ans[n];
    int p = 0;
    for(auto &[num, vec]:m){
        
        auto it = lower_bound(vec.begin(), vec.end(),lo);
        int dist = vec.end() - it;
//        cout << num << " " << dist << " " << lo << " " << vec.back()  << '\n';
        if(num > r){
            r = min(num+1, r);
            continue;
        }
        u[num]-=dist;
        for(int i = 0;i<dist;i++)
            ans[p++] = num;
        if(dist > 0)
            lo = vec.back();
        if(vec.size()-dist != 0)
            r = min(num+1, r);

    }

    for(int i = 0;i<p;i++){
        cout << ans[i] << " ";
    }

    for(auto &[num,cnt]:u){ 
        for(int i = 0;i<cnt;i++){
            cout << num+1 << " ";
        }
    }
    cout << '\n';



}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}

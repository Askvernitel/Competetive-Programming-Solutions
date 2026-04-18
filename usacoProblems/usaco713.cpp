#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);
    int n;
    cin >> n;
    pair<int,int> a[n];
    for(int i =0;i<n;i++){
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a+n);
    
    int p = a[0].first;
    for(int i = 0;i<n;i++){
        p = max(p, a[i].first) + a[i].second;
    }
    cout << p << '\n';
}

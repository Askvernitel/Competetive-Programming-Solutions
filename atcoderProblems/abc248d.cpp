#include <bits/stdc++.h>

using namespace std;


int main(){
    vector<int> c = {1, 2, 3, 4 ,5 ,6};
  

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    map<int, vector<int>> m;
    cin >> n;

    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        m[num].push_back(i);
    }
    int q;
    cin >> q;
    vector<int> t;
    while(q--){
        int l, r, x;

        cin >> l >> r >> x;
        t=m[x];
        l--; r--;
        int ans = upper_bound(t.begin(), t.end(), r) - lower_bound(t.begin(), t.end(), l);
        
        cout << ans << '\n';
        
    }
}

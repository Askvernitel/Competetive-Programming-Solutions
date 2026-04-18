#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n>> m;

    vector<int> a(n), b(m);

    for(int i =0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];

    int ans = 0;
    for(int i =0;i<n;i++){
        auto it = lower_bound(b.begin(), b.end(), a[i]);

        if(it != b.end() && it != b.begin()){
            ans = max(ans, min(abs(a[i]-*it), abs(a[i]-*prev(it))));
        }else if(it == b.begin()){
            ans = max(ans, abs(a[i]-*it));

        }
        else{
            ans = max(ans, abs(a[i]-*prev(it)));
        }
    }

    cout << ans << '\n';

}

#include <bits/stdc++.h>
//#define F first;
//#define S second;
using namespace std;
int main(){
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    int n, b;
    cin >> n >> b;

    vector<pair<int, int>> v(n);
    for(int i =0;i < n;i++){
        int x, y;
        cin >> x >> y;
        v[i] = {x, y};
    }

    int ans = n;
    for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++){
            int x = (v[i].first + 1), y=(v[j].second + 1);
            int o =0 , s=0, t =0, f =0;
            for(int k = 0;k<n;k++){
                int x1 = v[k].first, y1= v[k].second; 
                if(x1 > x && y1 > y) o++;
                if(x1 > x && y1 < y) f++;
                if(x1 < x && y1 > y) s++;
                if(x1 < x && y1 < y) t++;
            }
            int curMax = max({o,s,t,f});
            ans = min(ans, curMax);
        }

    }

    cout << ans << '\n';    
}

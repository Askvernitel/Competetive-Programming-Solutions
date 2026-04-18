#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n,m,p,q,d;

    cin >> n >> m >> p >> q >> d;

    int k = n+m;

    map<int,int> cnt;
    int a[n], b[m];
    for(int i =0;i<n;i++){
        cin >> a[i];
        cnt[a[i]]++;
    }

    for(int i =0;i<m;i++){
        cin >> b[i];
        cnt[b[i]]++;
    }
    int ans =0;
    int c = cnt.size();
    int dp[c+1];
    for(auto it =cnt.begin();it!=cnt.end();it++){
        if(it->second >0){
            int t = 0;
            auto it1=it;
            while(it1 != cnt.end() && it1->first < it->first+d){
                if(it1->second > 0) t++;
                it1++;
            }

        }
    }
    cout << ans << '\n';

}

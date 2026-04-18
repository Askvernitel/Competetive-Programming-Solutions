#include <bits/stdc++.h>

using namespace std;
void solve()  {
        int n, m;
        cin >> n >> m;

        int a[n], b[m], c[m];
        
        multiset<int> ms;

        for(int i =0;i<n;i++){
                cin >> a[i];
                ms.insert(a[i]);
        }

        for(int i =0;i<m;i++){
                cin >> b[i];
        }

        for(int i =0;i<m;i++){
                cin >> c[i];
        }
        int ans = 0;
        map<int,pair<int, map<int,int>>> pos_b;

        for(int i =0;i<m;i++){
                if(b[i] < c[i]){
                        pos_b[b[i]].second[c[i]]++;
                        pos_b[b[i]].first++;
                }
        }
        for(auto [b1, kk]:pos_b){ 
                map<int,int> a2 = kk.second;
                int sz = kk.first;
                for(int i = 0;i<sz;i++){
                        auto t = ms.lower_bound(b1);
                        if(t != ms.end()){ 
                                int dd = *t;
                                ms.erase(t);
                                auto d = a2.rbegin();
                                int val = d->first;

                                d->second--;
                                ms.insert(max(val,dd));
                                if(d->second == 0){ 
                                        a2.erase(val);
                                }
                                ans++;
                        }
                }
        }
        
        int largest = *ms.rbegin();
        for(int i =0;i<m;i++){
                if(b[i] >= c[i] && c[i] != 0 && largest >= b[i]){ 
                        ans++;
                }
        }

        vector<int> vec;
        for(int i=0;i<m;i++){
                if(c[i] == 0){
                        vec.push_back(b[i]);
                }
        }

        sort(vec.begin(), vec.end());
        
        for(int v:vec){ 
                auto found = ms.lower_bound(v);
                if(found != ms.end()){ 
                        ms.erase(found);
                        ans++;
                }
        }
        cout << ans << '\n';
}
int main(){ 
        int tc;
        cin >> tc;

        while(tc--) solve(); 
}

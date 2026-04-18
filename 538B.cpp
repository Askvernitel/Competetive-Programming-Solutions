#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int c[7] = {1,10,100,1000,10000,100000, 1000000};

    int f[n+1], p[n+1];
    for(int i =0;i<n+1;i++) f[i] = INT_MAX;
    f[0] = 0;
    for(int i =0;i<n;i++){
        for(int j = 0;j<7;j++){
            if(i+c[j] <= n && f[i + c[j]] > f[i] + 1){
                f[i+c[j]] = f[i] + 1;
                p[i+c[j]] = j;
            }
        }
    }
    map<int, int> m;
    int cur = n;
    while(cur > 0){
        m[c[p[cur]]]++;
        if(cur-c[p[cur]] >= 0) cur = cur-c[p[cur]];
        else break;
    }
    vector<int> ans;
    for(int i =0;i<f[n];i++){
        int a = 0, pos = 0;
        for(auto &x:m){
            if(x.second != 0){
                pos = 1;
                a+=x.first;
                m[x.first]--;
            }
        }
        if(!pos) break;
        ans.push_back(a);
    }
    cout << ans.size() << '\n';
    for(int i =0;i<ans.size();i++){
        cout << ans[i] << " ";
    }

}

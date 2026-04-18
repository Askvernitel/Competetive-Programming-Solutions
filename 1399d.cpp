#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;
    int p[n];
    memset(p, 0, sizeof(p));
    string s;
    cin >> s;
    map<int, set<int>> m;
    for(int i =0;i<n;i++){
        int num = s[i]-48;
        m[num].insert(i);
    }
    int am = 0;
    int t = 0;
    int mark = 1;
    int k = 0;
    while(t != n){ 
        if(p[t]){t++; continue;}
        int x = s[t]-48;
        auto it = m[!x].lower_bound(t);
        p[t] = mark;
        while(it != m[!x].end()){
            int v = *it;
            p[v] = mark;
            m[!x].erase(it);
            x=!x; 
            it = m[!x].lower_bound(v);
        }

        mark++;
        t++;
    }
    cout << mark-1 << '\n';
    for(int i = 0;i<n;i++){
        cout << p[i] << " ";
    }
    cout << endl;
}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}

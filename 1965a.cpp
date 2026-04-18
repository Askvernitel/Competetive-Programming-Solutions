#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;
    set<int> s;
    int a[n];
    for(int i=0;i<n;i++) {cin >> a[i]; s.insert(a[i]);}
    int cur = 1;
    if(*s.begin() != 1){
        cout << "Alice" << '\n';
        return;
    }
    auto it = s.begin();
    int cnt = 1;
    while(it != prev(s.end())){
        if(*next(it)-1 != *it ){
            break;
        }
        cnt++;
        it++;
    }
    if((it == prev(s.end()) && !(cnt%2)) || (it != prev(s.end()) &&(cnt%2))){
        cout << "Bob\n";
        return;
    }
    cout << "Alice\n";
}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}

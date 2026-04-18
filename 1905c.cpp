#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;
    char p = 'a';
    int d = 0, l=0;
    for(int i = 0;i<n;i++){
        if(s[i] > p){
            p=s[i];
            d=i;
        }
    }
    int cnt =0;
    for(int i =0;i<n;i++) if(p==s[i]) cnt++;
    int t = 1;
    /*for(int i = 0;i<d-1;i++){
        if(s[i] >= s[i+1]){
            t=0;
            break;
        }
    }*/

    //if(!t){cout << -1 << '\n'; break;}
    vector<int> st, inds;
    st.push_back(s[d]);
    inds.push_back(d);
    for(int i = d+1;i<n;i++){
        while(st.back() < s[i]){
            st.pop_back();
            inds.pop_back();
        }
        st.push_back(s[i]);
        inds.push_back(i);
    }
    int k = st.size();
    for(int i = 0;i<k;i++) s[inds[i]] = st[k-i-1];
    int ans =0;

    for(int i =0;i<k;i++) if(s[inds[i]] != st[i]){ans=INT_MAX; break;}
    for(int i =0;i<n-1;i++){
        if(s[i] > s[i+1]){
            t=0;
            break;
        }
    }
    if(t) cout << min(ans, k-cnt) << '\n';
    else cout << -1 << '\n';

}


int main(){
    int tc;

    cin >> tc;

    while(tc--) solve();
}

#include <bits/stdc++.h>

using namespace std;
int f1[200001][26], f2[200001][26];
void solve(){
    int n, q;

    cin >> n >> q;
    
    string s1, s2;

    cin >> s1 >> s2;
    for(int i =0;i<s1.size();i++){
        copy(f1[i], f1[i]+26, f1[i+1]);
        f1[i+1][s1[i] - 'a']++;
        copy(f2[i], f2[i]+26, f2[i+1]);
        f2[i+1][s2[i] - 'a']++; 
    }
    
    while(q--){
        int l, r;
        cin >> l >> r;
        l--;
        int c1[26], c2[26];
       
        for(int i =0;i<26;i++){
            c1[i] = f1[r][i] - f1[l][i];
            c2[i] = f2[r][i] - f2[l][i];
        }
        int ans = 0;
        for(int i =0;i<26;i++) ans+=abs(c1[i] - c2[i]);
        cout << abs(ans/2) << '\n';
    }

}

int main(){
    int tc;

    cin >> tc;

    while(tc--) solve();
}

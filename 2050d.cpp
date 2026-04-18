#include <bits/stdc++.h>

using namespace std;
void solve(){
    string s;
    cin >> s;

    int n = s.size();
    for(int i =0;i<n;i++){
        int idx = i;
        int maxv = s[i]-'0';
        for(int j=i+1; j<min(n, i+10);j++){
            if(s[j]-'0'-(j-i) > maxv){ 
                idx = j;
                maxv = s[j]-'0'-(j-i);
            }
        }
        for(int j=idx;j>i;j--){
            swap(s[j],s[j-1]);
        }
        s[i]=maxv+'0';
    }
    cout << s << '\n';
}

int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int const M = 1e9 + 7;
int const N = 100001;
ll f[N];
void fill(){
    f[0] = 1; f[1] = 1;

    for(int i=2;i<N;i++){
        f[i] = (f[i-1]%M + f[i-2]%M)%M;
    }
}
int main(){
    string s;
    cin >> s;
    int n = s.size();
    fill();
    for(char c:s){
        if(c == 'm' || c == 'w'){cout << 0; return 0;} 
    }
    char t = '1';
    ll ans = 1, p =0;
    for(int i =0;i<n;i++){
        if((s[i] != 'n' && s[i] != 'u')){ans=(ans * ((f[p])%M))%M; p =0; continue;}
        if(s[i] != t && t != '1'){ans=(ans*((f[p])%M))%M; p = 0;}
        t = s[i];
        p++;
    }
    ans = (ans*(f[p]%M))%M;
    cout << ans;
}

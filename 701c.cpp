#include <bits/stdc++.h>

using namespace std;

map<char,int> p, s;
char a[100001];
int n;
void add(char k){
    p[k]--;
}
void remove(char k){
    p[k]++;
}

bool good(){
    for(auto &x:s){
        if(p[x.first] == s[x.first]) return false;
    }
    return true;
}
int main(){
    cin >> n;
    for(int i =0;i<n;i++){
        cin >> a[i];
        s[a[i]]++; p[a[i]]++;
    }
    int l = 0, ans=INT_MAX;
    for(int r = 0;r<n;r++){
        add(a[r]);
        while(good()){
            ans = min(r-l+1,ans);
            remove(a[l++]);
        }
    }

    cout << ans << '\n';
}

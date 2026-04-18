#include <bits/stdc++.h>
using namespace std;

int n, k;
int cnt[2];
void add(char ch){ 
    cnt[ch-'a']++;
}

void remove(char ch){
    cnt[ch-'a']--;
}
bool good(){ 
    return (cnt[0] <= k) || (cnt[1] <=k);
}

int main(){
    string s;
    cin >> n >> k;
    cin >> s;
    int l =0, ans=0; 
    for(int r=0;r<n;r++){
        add(s[r]);
        while(!good()){ 
            remove(s[l++]);
        }
        ans = max(ans, r-l+1);
    }
    cout << ans;

}

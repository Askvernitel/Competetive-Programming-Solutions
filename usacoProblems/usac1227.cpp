#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    string s;
    cin >> s;


    int ans = 0;
    for(int i=n-2;i >= 0;i-=2){
        string str=s.substr(i, 2);
        if(s[i] == s[i+1]) continue;
        else if(str == "GH" && ans%2==0) ans++;
        else if(str == "HG" && ans%2==1) ans++;

    }

    cout << ans;
}

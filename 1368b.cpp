#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int k;
    cin >> k;
    string str = "codeforces";
    int s[10];
    memset(s, 0, sizeof(s));
    int x = 1;

    int p = 0;
    int prev = 1;
    int cof = 2;
    while(x < k){
        if(p == 10){ 
            p = 0;
            prev++;
            cof++;
            continue;
        }
        s[p]++;
        x/=prev;
        x*=cof;
        p++;
    }
    for(int i =0;i<10;i++){
        for(int j=0;j<=s[i];j++){
            cout << str[i];
        }
    }
}

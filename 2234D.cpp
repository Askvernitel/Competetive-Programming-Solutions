#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
        int n, k;
        cin >> n >> k;

        string s1, s2;
        cin >> s1 >> s2;
        string s3;


        for(int i =0;i<n;i++){
                if(s1[i] == s2[i]) s3.push_back('0');
                else s3.push_back('1');
        }
        
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;

        for(int i = 0;i<n;i++){
               if(s1[i] == '1') cnt1++;
               if(s2[i] == '1') cnt2++;
               if(s3[i] == '1') cnt3++;
        }

        int cof1 = cnt1*(n-cnt1), cof2 = cnt2*(n-cnt2), cof3 = cnt3*(n-cnt3);

        int sz = pow(2, k)+1;

        int t1,t2,t3;
        if(sz%3 == 0) {
                t1 = sz/3;
                t2 = sz/3;
                t3 = sz/3;
        }
        else {
                t1 = sz/3 + 1;
                t2 = sz/3 + 1;
                t3 = sz/3 ;
        }


        cout << cof1*t1 + cof2*t2 + cof3*t3 << '\n';
}
signed main(){
        int tc;
        cin >> tc;

        while(tc--) solve();
}

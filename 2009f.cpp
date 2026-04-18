#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;

    int a[n];
    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    

    int pref[n+1], suf[n+1];
    pref[0] = 0;
    suf[n] = 0;
    for(int i =1;i<=n;i++){
        pref[i] = pref[i-1] + a[i-1];
    }

    for(int i =n-1;i>=0;i--){
        suf[i] = suf[i+1] + a[i];
    }

    int sum = pref[n];
    while(q--){
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int shift_l = l/n;
        int shift_r = r/n;
        int ml = l%n;
        int mr = r%n;


        int dist = ((r-(mr))-(l + (n-ml)) + 1)/n;
        //cout << "DIST: " <<  ((r-(mr))-(l + (n-ml)) + 1) << '\n';
        //cout << "RDIST: " << dist << '\n';
        int cut_l1 = shift_l;
        int cut_r1 = (shift_l+ml);
        
        int cut_l2 = shift_r;
        int cut_r2 = (shift_r+mr);
        int sum_1 = 0, sum_2 = 0;

        if(cut_r1 >= n){
            sum_1 += pref[n] - pref[cut_l1];
            sum_1 += pref[cut_r1%n];
          //  cout  << "sum_1 n:" << sum_1 << '\n';
        }else { 
            sum_1 += pref[cut_r1] - pref[cut_l1];
         //   cout << "sum_1;" << sum_1 << '\n';
        }

        if(cut_r2 >= n) { 
            sum_2 += pref[cut_l2] - pref[(cut_r2+1)%n];
        //    cout << "sum_2 n:" << sum_2 << '\n';
        }else{
            sum_2 += suf[cut_r2+1] + pref[shift_r];
       //     cout << "sum_2:" << sum_2 << '\n';
        }

        int cut_sum = sum_1 + sum_2;
     //   cout << "DIST: " << dist << '\n';
        //cout << dist*sum;
        int cof = 2;
        if(shift_l == shift_r){ 
            cof = 1;
        }
        dist = max((int)0, dist);
//        cout << "SUM:" << sum << '\n';
 //       cout << "SUM*DIST:" << sum*dist << '\n';
  //      cout << "SECOND: " << (cof*sum - cut_sum)  << '\n';
        cout << (dist)*sum + (cof*sum - cut_sum) << '\n';
    }
}
signed main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}

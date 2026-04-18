#include <bits/stdc++.h>

#define int long long
using namespace std;
int n, l, r;

/*
int choice[200000];
void rec(int* a, int i){ 
    if(i == n){ 
        int result = INT_MAX;
        for(int p =l;p<=r;p++){
            int cur = 0;
            for(int j =0;j<n;j++){
                if(choice[j] == 1 && a[j] < p){ 
                    cur += (p-a[j]);
                }else if(choice[j] == 1 && a[j] >= p){ 
                    cur -= (a[j] - p);
                }else if(choice[j] == 2 && a[j] < p){ 
                    cur -= (p - a[j]);
                } else if(choice[j] == 2 && a[j] >= p){
                    cur += (a[j] - p);
                }
            }
            result = min(result, cur);
        }
        if(result == 13){
            for(int i =0;i<n;i++){
                cout << choice[i] << " ";
            }
            cout << result << ' ';
        }
        return;
    }
    choice[i] = 1;
    rec(a, i+1);
    choice[i] = 2;
    rec(a, i+1);
    choice[i] = 0;
    rec(a, i+1);
}*/
int dp[200000];
int rec(int* a, int i, int last, int sum_l, int sum_r){ 
    if(i < 0){
        return min(sum_l, sum_r);
    }
/*    if(dp[i] != 0){
        cout << "dp[i]:" << dp[i] << '\n';
        return dp[i];
    }*/
    //cout << "sum_l: " << sum_l << " " << "sum_r: " << sum_r << '\n'; 
  //  cout << "R: " << r << '\n';
   // cout << "L: " << l << '\n';
    //cout << "a[i]: " << a[i] << '\n';
    int cur = max({
    rec(a, i-1, last, sum_l + (a[i] - l), sum_r - (r-a[i])),
    rec(a, i-1, last, sum_l - (a[i] - l), sum_r + (r-a[i])),
    rec(a, i-1, last, sum_l, sum_r)
    });
    //cout << "i " << i << '\n';
    //cout << "cur: " << cur << '\n';
    dp[i] = cur;
    return cur;
}
void solve(){
    cin >> n >> l >> r;
    int a[n];
    memset(dp, 0, sizeof(dp));

    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    sort(a, a+n);

    int lt = n, rt = -1;

    int sum_l = 0, sum_r=0;
    for(int i =0;i<n;i++){
        if(a[i] > l){ 
            lt = i;
            break;
        }
        sum_r += r - a[i];
        sum_l += l - a[i];
    }
    for(int i =n-1;i>=0;i--){ 
        if(a[i] < r){ 
            rt = i;
            break;
        }
        sum_l+=a[i]-l;
        sum_r+=a[i]-r;
    }

    //cout << "sum_l: " << sum_l << " " << "sum_r: " << sum_r << '\n'; 
    //cout << "LT: " << lt << '\n';
    //cout << "RT: " << rt << '\n';
    //cout << "ANS: " << rec(a, lt, rt, sum_l, sum_r) << '\n';

    int m = rt-lt+1;
    vector<int> prefl, prefr, sufr, sufl;
    if(m >= 0){
        prefl.resize(m+1);
        prefr.resize(m+1);
        sufr.resize(m+1);
        sufl.resize(m+1);
        prefl[0] = 0;
        prefr[0] = 0;
        sufr[m] = 0;
        sufl[m] = 0;
    }
    for(int i =1;i<=m;i++){
        prefl[i] = prefl[i-1] + (a[i-1+lt]-l);
        prefr[i] = prefr[i-1] + (r-a[i-1+lt]);
    }
    for(int i =m-1;i>=0;i--){
        sufr[i] = sufr[i+1] + (r-a[i+lt]);
        sufl[i] = sufl[i+1] + (a[i+lt]-l);
    }
    //cout << "PREFIXES, L, R:" << '\n';
    //cout << "M:" << m << endl;
    /*
    for(int i =0;i<=m;i++){
        cout << prefl[i] << " ";
    }
    cout << endl;
    for(int i =0;i<=m;i++){
        cout << prefr[i] << " ";
    }
    cout << endl;
    cout << "SUFFIXES, L, R:" << '\n';
    for(int i=0;i<=m;i++){
        cout << sufl[i] << " ";
    }
    cout << endl;
    for(int i=0;i<=m;i++){
        cout << sufr[i] << " ";
    }
    cout << endl;*/
    int ans =min(sum_l, sum_r);
    for(int dist = 0;dist<2;dist++){
        for(int i =0;i<=m-dist;i++){
            //cout << "prefl[i]: " << prefl[i] << "prefr[i]: " << prefr[i] << '\n';
            //cout << "sufl[i]: " << sufl[i] << "sufr[i]: " << sufr[i] << '\n';
            
            int sum_l_1 = sufl[i+dist] - prefl[i] + sum_l;
            int sum_r_1 = prefr[i] - sufr[i+dist] + sum_r;
            //cout << "i: " << i << '\n';
            //cout << "sum_l: " << sum_l << " " << "sum_r: " << sum_r << '\n'; 
            //int sum =sufl[i]-prefl[i]-sufr[i]+prefr[i];
            ans = max(min(sum_l_1, sum_r_1), ans);
        }
    }
    cout << ans << '\n';
    /*int save_sum_l = sum_l, save_sum_r = sum_r;
    //cout << "sum_l: " << sum_l << " " << "sum_r: " << sum_r << '\n'; 
    int m = rt-lt+1;
    int ans = max(min(sum_l, sum_r), (int)0);
    vector<int> cl, cr;
    if(m > 0){
        cl.resize(m);
        cr.resize(m);
    }
    ans = max(ans, min(sum_l, sum_r));
    for(int i=0;i<m;i++){
        cl[i] = l-a[i+lt];
        cr[i] = r-a[i+lt];
        sum_l += cl[i];
        sum_r += cr[i];
    }
    
   // cout << "ANS: " << ans << '\n';
    //cout << "sum_l: " << sum_l << " " << "sum_r: " << sum_r << '\n'; 
    for(int i=m-1;i>=0;i--){
        cl[i] *= -1;
        cr[i] *= -1;
     //   cout << "cl[i] " << cl[i] << " cr[i] " << cr[i] << '\n';
        ans = max(ans, min(sum_l, sum_r));
        ans = max(ans, min(sum_l+(2*cl[i]), sum_r+(2*cr[i])));
     //   cout << "sum_l: " << sum_l << " " << "sum_r: " << sum_r << '\n'; 
        if(sum_l + (2*cl[i]) >= sum_r + (2*cr[i])){ 
            sum_r += cr[i];
            sum_l += cl[i];
          //  cout << "New Sum_l: " << (sum_l + (2*cl[i])) << "New Sum_r: " <<  sum_r + (2*cr[i]) << '\n';
        }else{
            sum_l += 2*cl[i];
            sum_r += 2*cr[i];
        }
    }
    sum_l = save_sum_l;
    sum_r = save_sum_r;
    for(int i=0;i<m;i++){
        cl[i] = a[i+lt]-l;
        cr[i] = a[i+lt]-r;

        sum_l += cl[i];
        sum_r += cr[i];
    }
    for(int i=m-1;i>=0;i--){
        cl[i] *= -1;
        cr[i] *= -1;
        ans = max(ans, min(sum_l+(2*cl[i]), sum_r+(2*cr[i])));
        if(sum_l + (2*cl[i]) <= sum_r + (2*cr[i])){ 
            sum_r += cr[i];
            sum_l += cl[i];
        }else{
            sum_l += 2*cl[i];
            sum_r += 2*cr[i];
        }
    }*/
//    cout << ans << '\n';
}
signed main(){ 
    int tc;
    cin >> tc;

    while(tc--) solve();
}

#include <bits/stdc++.h>

using namespace std;

bool is_pal(vector<int>& a, int l, int r){ 
    while(a[l] == a[r] && l <= r){ 
        l++;
        r--;
    }
    return l > r;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a;
    for(int i =0;i<n;i++){
        int p;
        cin >> p;
        a.push_back(p);
    }


    for(int i =0;i<min(k, 3);i++){
        int sz = a.size();
        map<int, int> s;
        s[a[sz-1]]++;
        for(int j = sz-1;j>=0;j--){
            if(is_pal(a, j, sz-1) && j-1 >= 0){
                s[a[j-1]]++;
            }
        }
 
        int cur_min = INT_MAX; 
        int cur_ans = 0;
        for(int j =1;j<=n;j++){
            if(cur_min > s[j]){ 
                cur_ans = j;
                cur_min =s[j];
            }
        }
        cout << cur_ans << ' ';
        a.push_back(cur_ans);
    }
    for(int i =0;i<k-3;i++){
        cout << a[n + i%3] << ' ';
    }
    cout << endl;
}
int main(){ 
    int tc;
    cin >> tc;

    while(tc--) solve();
}

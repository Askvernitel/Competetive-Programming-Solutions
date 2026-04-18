#include <bits/stdc++.h>

using namespace std;
int n;
int arr[103];
int x[103];
int f(vector<int> a, int k){
    for(int i =0;i<n;i++){
        if(a[i] == k){return i;} 
    }
    return -1;
}

void solve(){
    int m;
    cin >> n >> m;
    vector<int> a(n), p(m);
    for(int i =0;i<n;i++) cin >> a[i];
    for(int i =0;i<m;i++) cin >> p[i];

    vector<int> v(n);
    for(int i =0;i<n;i++) v[i] = a[i];
    memset(arr, 0, sizeof(arr));
    memset(x, 0, sizeof(x));
    for(int i =0;i<m;i++){
        int k = p[i];
        k--;
//        cout << k << '\n';
//        cout << arr[0] << '\n';
        arr[k]=1;
        //arr[k+1]=1;
    }
    int c = 1;
    string ans = "YES";
/*    for(int i = 0;i<n-1;i++){
        if(a[i] > a[i+1]) c = 0;
    }
    if(c){cout << ans << '\n'; return;}
*/  
    int q = n-1;
    sort(v.begin(), v.end());
    for(int i =0;i<n;i++){
        int t = f(a, v[q-i]);
        //cout << a[t] << '\n';
        //cout << p << '\n';
        for(int j = t;j<n-i-1;j++){
            //cout << arr[j] << '\n';
            if(arr[j]) swap(a[j], a[j+1]);
            else break;
        }
    }
    for(int i =0;i<n-1;i++){
       //cout << a[i] << '\n';
       if(a[i] > a[i+1]) ans = "NO";
    }
    cout << ans << '\n';
}


int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}

#include <bits/stdc++.h>


using namespace std;

int n,k;
int a[200001];

int arr[200001];
bool check(int x){ 
    int p = 0;
    unordered_set<int> s;
    int mex = 0;
    for(int i =0;i<n;i++){
        if(a[i] > n/k + 3) continue;
        s.insert(a[i]);
        while(s.find(mex) != s.end()){
            mex++;
        }
        if(mex >= x){
            p++;
            mex=0;
            s={};
        }
    }

    return p >= k;

}
void solve(){
    cin >> n >> k;

    for(int i =0;i<n;i++){
        cin >> a[i];
    }



    int l=0, r=n+1;
    while(r-l>1){ 
        int m = (r+l)/2;
        if(check(m)){
            l=m;
        }else{
            r=m;
        }
    }
    cout << l << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;

    while(tc--) solve();
}

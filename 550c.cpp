#include <bits/stdc++.h>

using namespace std;
int const N = 100;
int M = 8;
int arr[N][N];
int ans[N];    
int x = 0, p = 0;
void b(int i, int k, int c, string s, vector<char>& v){
    int n = s.size();
    if(k == c && x%M == 0){
        int o = 0;
        for(int z =N-1;z>=N-int(v.size());z--){
            ans[z] = int(v[o]-'0');
            o++;
        }
        p=1;
    }
    if(k == c) return;
    if(i == n){
        return;
    }
    x+=arr[i][k-c-1];
    v.push_back(s[i]);
    b(i+1, k, c+1, s, v);
    v.pop_back();
    x-=arr[i][k-c-1];
    b(i+1, k, c, s, v );
}


int main(){
    string s;

    cin >> s;
    
    int n = s.size(), h=0;
    for(int i =0;i<n;i++){
        if(!(int(s[i]-'0')%2)) h=1;
    }
    if(!h){cout << "NO"; return 0;}
    //int arr[n][n];
    int m = n;
    for(int i =0;i<n;i++){
        int r = 1;
        for(int j=0;j<m;j++){
            arr[i][j] = ((int(s[i]-'0')%M) * (r%M))%M;
            r=((r%M)*(10%M))%M;
        }
        m--;
    }
    vector<char> v;
    for(int i =1;i<=3;i++){
        b(0, i, 0, s, v);
        if(p) break;
    }
    if(!p){cout << "NO"; return 0;}

    cout << "YES\n";
    int a = 0;
    while(ans[a]==0 && a < N) a++;
    for(int i=N-1;i>=a;i--){
        cout << ans[i];

    }
    //cout << a;
    if(N==a) cout << 0;
}

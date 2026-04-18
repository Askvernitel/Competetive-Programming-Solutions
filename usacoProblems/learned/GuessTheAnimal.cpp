#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("guess.in","r",stdin);
    freopen("guess.out", "w", stdout);
    int n;
    cin >> n;
    vector<string> a[n];
    for(int i =0;i<n;i++){
        string s;
        cin >> s;
        int k;
        cin >> k;
        for(int j =0;j<k;j++){
            string ch;
            cin >> ch;
            a[i].push_back(ch);
        }
    }
    int ans = 1;
    for(int i =0;i<n;i++){
        int arr[n];
        memset(arr, 0, sizeof(arr));
        int t = a[i].size();
        for(int j=0;j<t;j++){
            string s = a[i][j];
            for(int k =0;k<n;k++){
                int p = a[k].size();
                for(int v = 0;v<p;v++){
                    if(a[k][v] == s){
                        arr[k]++;
                    }
                }
            }
        }
        int res = 1;
        for(int j =0;j<n;j++){
            if(i != j){
                res = max(arr[j]+1, res);
            }
        }
        ans = max(ans, res);
    }
    cout << ans << "";
}

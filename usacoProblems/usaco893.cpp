#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    set<string> a[n];
    for(int i =0;i<n;i++){
        string animal;
        int k;
        cin >> animal;
        cin >> k;

        for(int j=0;j<k;j++){
            string ch;
            cin >> ch;
            a[i].insert(ch);
        }
    }
    int ans = 0; 
    for(int i =0;i<n;i++){
        int arr[n];
        memset(arr, 1, sizeof(arr));
        int t = a[i].size();
        int cnt = 0;
        for(string ch:a[i]){
            int p = 0;
            for(int k=0;k<n;k++){
                if(arr[k] && a[k].find(ch) != a[k].end()){
                    p++;
                    continue;
                }
                arr[k] = 0;
            }

            cnt++;
            if(p == 1){
                ans = max(cnt, ans);
                cnt=0;
                memset(arr, 1, sizeof(arr));
                continue;
            }

        }


    }

    cout << ans << '\n';
}

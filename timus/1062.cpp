#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n][3];
    for(int i =0;i<n;i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2]; 
    }
    int ans = 0;
    for(int i =0;i<n;i++){
        int arr[n];
        memset(arr, 0,sizeof(arr));
        for(int j = 0;j<3;j++){
            int p = a[i][j];
            for(int k=0;k<n;k++){
                if(i == k) continue;

                if(a[k][j] <p) arr[k] = 1;
            }
        }
        int cnt = 0;
        for(int i =0;i<n;i++){
            if(arr[i] == 0) cnt++;
        }

        if(cnt > 1) cout << "No\n";
        else cout << "Yes\n";
    }
}

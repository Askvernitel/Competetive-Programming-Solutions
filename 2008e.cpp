#include <bits/stdc++.h>

using namespace std;
int calc(int arr[26]){
    int maxv = 0;

    for(int i =0;i<26;i++){
        maxv = max(arr[i], maxv);
    }
    return maxv;
}
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int even[n+1][26], odd[n+1][26];
    memset(even, 0, sizeof(even));
    memset(odd, 0, sizeof(odd));
    for(int i =1;i<=n;i++){
        if(!(i%2)){
            even[i][s[i-1]-'a']++;
        }else{
            odd[i][s[i-1]-'a']++;
        }
        
        for(int j=0;j<26;j++){
            if(i > 0) even[i][j] += even[i-1][j];
            if(i > 0) odd[i][j] += odd[i-1][j];
        }
    }
    if(!(n%2)){
        int t1 = calc(even[n]), t2 = calc(odd[n]);
//        cout << t1 << " " << t2 << " ";
        cout << ((n/2)-t1) + ((n/2)-t2) << '\n';
        return;
    }
    int even1[n+1][26], odd1[n+1][26];
    memset(even1, 0, sizeof(even1)); memset(odd1, 0,sizeof(odd1));
    for(int i =n-1;i>=0;i--){
        if(i%2){
            even1[i][s[i] -'a']++;
        }else{
            odd1[i][s[i] -'a']++;
        }

        for(int j = 0;j<26;j++){
            even1[i][j] += even1[i+1][j];
            odd1[i][j] += odd1[i+1][j];
        }
    }
    int ans = n+1;
    for(int i =0;i<n;i++){
        int arr1[26], arr2[26];
        copy(even[i],even[i]+26,arr1);
        copy(odd[i],odd[i]+26,arr2);
        for(int j=0;j<26;j++){
            arr1[j]+=odd1[i+1][j];
            arr2[j]+=even1[i+1][j];
//            arr1[j]+=even[i][j];
  //          arr2[j]+=odd[i][j];
        }
        int p1 = calc(arr1), p2=calc(arr2);

        int p = (p1)+(p2);
        ans = min(n-p, ans);
    }
    cout << ans << '\n';

}
int main(){
    int tc;

    cin >> tc;

    while(tc--) solve();
}

#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i =0;i<n;i++) cin >> a[i];

    sort(a,a+n);
    int first = a[0];
    int second = -1;
    int found = 0;
    int pos = 1;
    for(int i =1;i<n;i++){
        if(a[i]%first && !found){ 
            second = a[i]; 
            found=1;
        }else if(a[i]%first && a[i]%second){ 
            pos=0;
            break;
        }
    }
    cout << ((pos)?"YES":"NO") << '\n';
}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}

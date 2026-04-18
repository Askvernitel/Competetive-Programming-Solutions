#include <bits/stdc++.h>

using namespace std;

int log(int n, int b){
    int res = 0;
    while(n!=0){
        res++;
        n/=b;
    }
    return res;
}
int main(){
    int n;
    cin >> n;
    int x=2;
    int ans = 0;
    while(log(n, x) > 1){
        ans+=log(n,x);
        x++;
    }
    cout << ans;
}

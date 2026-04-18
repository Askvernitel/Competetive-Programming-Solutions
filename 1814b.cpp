#include <bits/stdc++.h>

using namespace std;
void solve(){
    int a, b;

    cin >> a >> b;
    
    int sqrt_a = (int)sqrt(a), sqrt_b = (int)sqrt(b);

    set<int> div_a, div_b;

    int amount_a = INT_MAX;
    int amount_b = INT_MAX;
    int sub_l_a = INT_MAX;;
    int sub_l_b = INT_MAX;;
    for(int i =1;i<=a;i++){
        int r = a/i;
        int l = a%i ;
        int p = i-l;
        int t = i-1;
        if(amount_a >= r + t){
            sub_l_a =(l==0)?i-1:l; 
        }
        amount_a = min(amount_a, r + t);
    }
    cout << amount_a << '\n';
    for(int i =1;i<=b;i++){
        int r = b/i;
        int l = b%i;
        int p = i-l;
        int t = i-1;
        if(amount_b >= r + t){
            sub_l_b =(l==0)?i-1:l; 
        }
        amount_b = min(amount_b, r + t);
    }
//    cout << amount_b << '\n';
    
    int ans = amount_a + amount_b - min(sub_l_a, sub_l_b);
    
    cout << ans << '\n';
}
int main(){
    int tc;
    cin >> tc;

    while(tc--) solve();
}

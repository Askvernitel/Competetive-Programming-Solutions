#include <bits/stdc++.h>


using namespace std;
void solve(){ 
    int n;
    cin >> n;
    

    int mod_3 = n%3;
    int mod_2 = n%2;

    int div_3 = n/3;
    int div_2 = n/2;
    if(n <= 3){
        cout << n << '\n';
        return;
    }
    if(div_3%2 == 0 && mod_3 == 0){
        cout << 0 << '\n';
    }else{ 
        cout << mod_2 << '\n';
    }
}

int main(){ 
    int tc;
    cin >> tc;

    while(tc--) solve();
}

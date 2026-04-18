#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;
    
    if(n <= 3){ 
        cout << -1 << '\n';
        return;
    }else if(n == 4){
        cout << "3 1 4 2\n";
        return;
    }
    int start = 1;

    while(start <= n){
        cout << start << " ";
        start +=2;

    }
    
    int end = n;
    if(end%2){
        end--;
        cout << end - 2 << " ";
        cout << end << " ";
        end -= 4;
        while(end > 0) {
            cout << end << " ";
            end-=2;
        }
    }else{ 
        cout << end - 4 << " ";
        cout << end << " ";
        cout << end-2 << " ";

        end -=6;
        while(end > 0){
            cout << end << " ";
            end-=2;
        }
    }

    cout << endl ;

    
}

int main(){
    int tc;
    cin >> tc;
    while(tc--) solve();
}

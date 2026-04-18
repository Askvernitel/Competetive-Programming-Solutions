#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, t, k;
    cin >> n >> t;

    cin >> k;
    int l = 1,r = n;
    while(l < r){
        int m = l + (r-l)/2;
        int out;
        cout << "? " << l << " " << m << endl;
        cin >> out;
        int t =m-l+1;
        int z =t-out;
//        cout << z << '\n';
        if(z >= k){
            r = m;
        }else{
            k-=z;
            l = m + 1;
        }

    }
    cout <<"! " << l << endl;
    cout.flush();

}

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];

    for(int i =0;i<n;i++){
        cin >> a[i];
    }
    int ans = 0;
    for(int i =0;i<n;i++){
        for(int j=i;j<n;j++){
            double avg = 0;
            for(int k=i;k<=j;k++){
                avg += a[k];
            }
            avg/=double(j-i+1);
            for(int k=i;k<=j;k++){
                if(avg == a[k]){ans++; break;}
            }
        }

    }

    cout << ans;

}

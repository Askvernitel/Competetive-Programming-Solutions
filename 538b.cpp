#include <bits/stdc++.h>
using namespace std;

int const N=7;
int arr[N];
int main(){
    int n;
    cin >> n;
    int r = 1;
    for(int i =0;i<N;i++){
        arr[i] = r;
        r*=10;
    }
    vector<int> ans;
    while(n != 0){
        int s = 0;
        for(int i=N-1;i>=0;i--){
            if(s+arr[i]<=n){
                s +=arr[i];
            }
        }
        ans.push_back(s);
        n-=s;
    }
    cout << ans.size() << '\n';
    for(int i =0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    
}   

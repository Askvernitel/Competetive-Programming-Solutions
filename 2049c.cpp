#include <bits/stdc++.h>

using namespace std;
int mex(int a, int b, int c){
    int res = 0;
    if(a== 0 || b== 0 || c == 0){ 
        res++;
        if(a==1 || b==1 || c == 1){ 
            res++;
            if(a==2 || b==2 || c==2){
                res++;
            }
        }
    }
    return res;
}
void solve(){ 
    int n, x, y;
    cin >> n >> x >> y;

    int a[n];

    x--;
    y--;
    
    for(int i =0;i<n;i++){
        a[i]=i%2;
    }

    if(a[0] == a[n-1]){
        a[n-1] =2;
    }
    for(int i =0;i<n;i++){
        int p1 = a[(n+i-1)%n];
        int p2 = a[(i+1)%n];
        int p3 = INT_MAX;
        if(i == x) p3 = a[y];
        else if(i==y) p3=a[x];
        a[i] =mex(p1,p2,p3);
    }
    int same = 0;
    for(int i =0;i<n;i++){
        int p1 = a[(n+i-1)%n];
        int p2 = a[(i+1)%n];
        int p3 = INT_MAX;
        if(i == x) p3 = a[y];
        else if(i==y) p3=a[x];
        if(a[i] != mex(p1,p2,p3)){same = 1; break;}
    }
    if(same){ 
        for(int i =0;i<n;i++){
            a[i]=(i%2);
        }
        if(a[0] == a[n-1]){
            a[0] =2;
        }
        for(int i =0;i<n;i++){
            int p1 = a[(n+i-1)%n];
            int p2 = a[(i+1)%n];
            int p3 = INT_MAX;
            if(i == x) p3 = a[y];
            else if(i==y) p3=a[x];
            a[i] =mex(p1,p2,p3);
        }    
    }

    for(int i =0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << '\n';
}
int main(){ 
    int tc;
    cin >> tc;

    while(tc--) solve();
}

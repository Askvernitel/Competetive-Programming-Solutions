#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x[n], v[n];
    cout << setprecision(6)<< fixed;
    for(int i =0;i<n;i++){
        cin >> x[i];
    }

    for(int i= 0;i<n;i++){
        cin >> v[i];
    }

    auto f = [&](double coord){ 
        double max_time = 0;
        for(int i = 0;i<n;i++){
            max_time = max(max_time, (double)abs(x[i]-coord)/(double)v[i]);
        }
        return max_time;
    };

    double l=0,r= 1000000000;
    double eps = 1/(1e7);
    while(r-l > eps){ 
        double m = l + (r-l)/2;
        if(f(m)>f(m-eps)){
            r = m;
        }else{
            l = m;
        }
    }
    cout << f(r) << '\n';
}

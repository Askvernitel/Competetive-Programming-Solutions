#include <bits/stdc++.h>

using namespace std;
int f(int& num){ 
    int res = num%10;
    num /=10;
    return res;
}
int conv(int num, int base) {
    int arr[3];
    int ans =0;
    int cur = 0;
    while(num != 0){
        arr[cur] = f(num);
        cur++;
    }

    for(int i = 0;i<3;i++){
        ans+=arr[i]*pow(base,i);
    }


    return ans;
}

double dis(double a, double b, double c){ 
    return sqrt((b*b)-4*(a*c));
}
double xroot(double a, double b, double d, int type){
    
    return (type)?(d-b)/(2.0*a):(-d-b)/(2.0*a);
}
int calc(int num, int c){ 
    int arr[3];
    int i =0; 
    while(num != 0){ 
        arr[i] = f(num);
        i++;
    }
    
    arr[0] -= c;

    double d = dis(arr[2], arr[1], arr[0]);
    
    if( d < 0){
        return -1;
    }
    double x = xroot(arr[2], arr[1], d,1);

    if(x == int(x) && x >= 10){ 
        return x;
    }
    x= xroot(arr[2],arr[1],d,0);
    if(x == int(x) && x >= 10){ 
        return x;
    }
    return -1;


}
void solve(){
    int n1, n2;
    cin >> n1 >> n2;
    
    for(int i = 10;i<=15000;i++){
        int t = conv(n1, i);
        if(calc(n2, t) != -1) {
            cout << i << " " << calc(n2, t) << '\n';
            break;
        }

    
    }
}
int main(){
    freopen("whatbase.in", "r", stdin);
    freopen("whatbase.out", "w" ,stdout);
    int tc;
    cin >> tc;

    while(tc--) solve();

}

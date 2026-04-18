#include <bits/stdc++.h>

using namespace std;
int const N = 4;
int f[10000001][N];
int M = 1000000007;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;

    scanf("%d", &n);
    //int f[n+1][N];
    //f(3,2) = f(3,2)+f(2,2)
    //f(2) = f(1)
    //f(0,x) = 1; f(1,x)=0; f(2,x)=3, f(3,x)=

    //for(int i =0;i<4;i++) f[1][i]=0;
    f[0][0]=1;
    for(int i =0;i<n;i++){
        for(int j =0;j<N;j++){
            //f[i+1][j] = f[i][j];
            if(f[i][j] == 0) continue;
            for(int k=1;k<N;k++){
                f[i+1][(j+k)%N] = (f[i+1][(j+k)%N]+f[i][j])%M;
            }
        }
    }
/*    for(int i = 0;i<n;i++){
        for(int j=0;j<4;j++){
            cout << f[i][j] << " ";
        }
        cout << endl;
    }*/
    printf("%d", f[n][0]);

}

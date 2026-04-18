#include <bits/stdc++.h>

using namespace std;
int p[50][500];
int main(){

    int n, m;

    cin >> n >> m;
    char arr1[n][m], arr2[n][m];

    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            cin >> arr1[i][j];
        }
    }

    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            cin >> arr2[i][j];
        }
    }

    for(int i = 0;i <n;i++){
        for(int j = 0;j<m;j++){
            for(int k = 0;k<n;k++){
                if(arr1[i][j] != arr2[k][j]){
                    p[j][k]=1;
                }
            }
        }
    }
   
    int ans = 0;
    for(int i = 0;i<m;i++){
        for(int j = i+1;j<m;j++){
            for(int k=j+1;k<m;k++){
                int t = 1;
                for(int v=0;v<n;v++){
                    if(!(p[j][v] || p[k][v] || p[i][v])){
                        t=0;
                        break;
                    }
                }
                if(t) ans++;
                
            }
        }

    }
    cout << ans;

}


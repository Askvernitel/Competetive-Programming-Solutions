#include <bits/stdc++.h>
#define int long long 
using namespace std;
int const N = 100004;
int arr[N];


signed main(){
    int n;

    scanf("%lld", &n);
    
    for(int i =0;i<n;i++){
        int num;
        scanf("%lld", &num);
        arr[num]+=num;
        
    }
    int ans = 0, s1=0, s2=0;
    for(int i=2;i<N;i++){
        arr[i] = max(arr[i-1], arr[i-2] + arr[i]);
    }
    

    printf("%lld", arr[N-1]);

}

#include <bits/stdc++.h> 
#define int long long
using namespace std;

int M = 1e9+7;

int f1[200001], f2[200001];

int powM(int x, int n){ 
    
    int p = 1;
    int exp = 0;
    int res = 1;
    while(p <= n){
	if(p & n){
	    res = (res * (x))%M;
	}
	x= (x*(x%M))%M;
	p*=2;
    }
    return res;
}


void fact(int n){
    f1[0]=1;
    for(int i =1;i<=n;i++){
	f1[i]=(f1[i-1]*i)%M;
    }
    f2[n]=powM(f1[n], M-2);
    
    for(int i =n-1;i>=0;i--){
	f2[i] = ((f2[i+1]%M)*(i+1))%M;
    }
}

int C(int n, int r) {
    if (r < 0 || r > n) return 0;
//    cout <<"C:"<<(f1[n])/(f1[r]*(f1[n-r]))<<'\n';
    return (((f1[n]) * (f2[r]%M))%M * (f2[n - r] % M))%M;
}
int P(int n, int r){
    if(r > n) return 0;
    return n-r+1;
}
void solve(){
	int n ,k;
	cin >> n >> k;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	
	int cnt[2]{0,0};
	for(int i =0;i<n;i++){
		cnt[a[i]]++;
	}
	if(k==1){
	cout << cnt[1] << '\n';
	return;
	}
	int fixed= (k+1)/2 ;
	int freeAmount = n - fixed;
	fact(n);		
	int choose = k/2;
    
	int nf = cnt[0];
	int mf = cnt[1]-fixed;
	int ans = 0;	
	int p = cnt[1];//(C(freeAmount,choose)-(C(cnt[0], choose) + C(cnt[1]-fixed,choose))%M)%M);
    //cout << p << '\n';
    //
	    
	while(mf>=0){ 
	    ans = (ans%M + (C(nf,choose)*C(p-1,fixed-1)%M)%M)%M;
	    nf++;
	    p--;
	    mf--;
	}
	cout << ans << '\n';
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}

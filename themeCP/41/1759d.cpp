#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n, m;
	cin >> n >> m;

	int cnt1=0,cnt2=0, cnt3=0, cnt4=0;
	int p =n;
	while(p!=0 && p%2 == 0){
		cnt1++;
		p/=2;
	}
	while(p!=0 && p%5 == 0){
		cnt2++;
		p/=5;
	}
	int k = 1;
	while(2*k <= m && cnt1 < cnt2){ 
		k*=2;
		cnt1++;
		cnt3++;
	}
	while(5*k <= m && cnt2 < cnt1){
		k*=5;
		cnt2++;
		cnt4++;
	}
	while(10*k <= m){
		k*=10;
	}
	int u = m/k;
	
	
	cout << k*u * n << '\n';

}
signed main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}

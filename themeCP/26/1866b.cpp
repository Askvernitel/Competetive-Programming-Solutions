#include <bits/stdc++.h>
#define int long long
using namespace std;
int mod = 998244353;
int mb[2000001], md[2000001];

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n],b[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	} for(int i=0;i<n;i++) { cin >> b[i];
		mb[a[i]]=b[i];
	}
	int m;
	cin >> m;
	int c[m], d[m];
	for(int i=0;i<m;i++){
		cin >> c[i];
	}
	for(int i=0;i<m;i++){
		cin >> d[i];
		md[c[i]]=d[i];
	}
	int ans = 1;
	int pos = 1;
	for(int i =0;i<m;i++){
		if(mb[c[i]] < md[c[i]]){ 
			pos = 0;
		}
	}
	if(!pos){ 
		cout << 0 << '\n';
		return 0;
	}
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(mb[a[i]] >md[a[i]]){
			ans=((ans%mod) *2)%mod;
		}
	}
	//for(int i =0;i<cnt;i++){
	//	ans=((ans%mod) *2)%mod;
	//}
	
	cout << ans << '\n';
	
}

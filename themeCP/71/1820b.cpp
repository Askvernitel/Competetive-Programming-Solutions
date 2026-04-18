#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	string s;
	cin >> s;
	
	int ans=0;
	int n = s.size();
	s=s+s;
	for(int i =0;i<n;i++){
		int cur =i;
		int t = i;
		int p = 0;
		while(s[cur]=='1'){
			cur++;
			p++;
			if(cur%n == i) break;
		}
		ans=max(p,ans);
		i=cur;
	}

	if(ans == n){
		cout << n *n<<'\n';
		return;
	}else{
		int tt = 0;
		for(int i =0;i<ans;i++){
			tt = max(tt, (i+1)*(ans-i));
		}
		cout << tt << '\n';
	}
}

signed main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}

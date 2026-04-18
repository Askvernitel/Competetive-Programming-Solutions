#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
	string s;
	cin >> s;

	int n = s.size();

	int j = n-1;
	
	vector<int> v, tmp;

	int cnt = 0;
	int ans = 0;
	int lidx = -1;
	for(int i =0;i<n;i++){
		if(s[i] == '0' && cnt > 0){
			ans += (cnt+1)*(i-lidx);
			lidx = i;
		}else if(s[i] == '1'){
			lidx=i;
			cnt++;
		}
	}
	cout << ans << '\n';


	
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}

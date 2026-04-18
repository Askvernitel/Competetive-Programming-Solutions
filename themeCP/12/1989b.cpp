#include <bits/stdc++.h>

using namespace std;
/*void solve(){
	string a, b;
	cin >> a >> b;

	int n = a.size(), m = b.size();
	int dp[n+1][m+1];
	memset(dp, 0,sizeof(dp));
	int maxv = 0;
	for(int i = 0;i<=n;i++){ 
		for(int j = 0;j<=m;j++){
			int cof = 0;
			if(i <n && j < m) cof = (a[i] == b[j]);
			if(i+1 <= n && j+1 <= m) dp[i+1][j+1] = max(dp[i][j]+cof,dp[i+1][j+1]);
			if(j+1 <=m)dp[i][j+1] = max(dp[i][j], dp[i][j+1]);
			if(i+1 <=n ) dp[i+1][j] = max(dp[i][j], dp[i+1][j]);
		}
		maxv = max(maxv, dp[i][m]);
	}
	maxv = max(dp[n][m], maxv);
	//m -= maxv;

	cout<< m+max(0,n-maxv)<< '\n';
}*/

void solve(){
	string a, b;
	cin >> a >> b;
	int n =a.size(), m = b.size();	
	map<char,set<int>> ms;
	for(int i =0;i<n;i++){
		ms[a[i]].insert(i);
	}
	int ans =n+m;
	for(int i =0;i<m;i++){
		int am = 0;
		int cur_idx = -1;
		for(int j = i;j<m;j++){
			
			auto it1 = ms.find(b[j]);
			if(it1 == ms.end()) break;
			auto it =(it1->second).upper_bound(cur_idx);
			if (it == (it1->second).end()) break;
			am++;
			cur_idx = *it;
		}
		ans =min(ans, n+m-am);	
	}
	cout << ans << '\n';

}
int main(){
	ios_base::sync_with_stdio(true);
	int tc;
	cin >> tc;
	while(tc--) solve();
}

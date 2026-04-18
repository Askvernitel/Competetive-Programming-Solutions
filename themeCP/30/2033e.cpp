#include <bits/stdc++.h>

using namespace std;
int p[1000001];
int dfs(int* vis, int cur, int d){ 
	if(vis[cur]) return d;
	vis[cur]=1;
	return dfs(vis,p[cur],d+1);
}

void solve(){
	int n;
	cin >> n;
	for(int i =1;i<=n;i++){
		cin >> p[i];
	}
	int vis[n+1];
	memset(vis,0,sizeof(vis));
	int ans =0;
	for(int i =1;i<=n;i++){
		int d = dfs(vis,i,0);
		ans+=(d-1)/2;
		/*while(d > 2){
			d=(d+1)/2;
			ans++;
		}*/
	}
	cout << ans << '\n';
}

int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}

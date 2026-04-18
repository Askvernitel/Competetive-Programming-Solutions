#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n], b[n];
	set<int> elems;
	for(int i =0;i<n;i++){cin >> a[i]; elems.insert(a[i]);}
	for(int i =0;i<n;i++){cin >> b[i]; elems.insert(b[i]);}
	int m1[2*n+1], m2[2*n+1];
	memset(m1,0,sizeof(m1));
	memset(m2,0,sizeof(m2));
	int cnt=1;
	for(int i = 0;i<n;i++){
		if(i+1<n && a[i] == a[i+1]) cnt++;
		else {
			m1[a[i]]=max(cnt, m1[a[i]]);
			cnt = 1;
		}
	}
	for(int i = 0;i<n;i++){
		if(i+1<n && b[i] == b[i+1]) cnt++;
		else {
			m2[b[i]]=max(cnt, m2[b[i]]);
			cnt = 1;
		}
	}
	int ans =0;
	for(int x:elems){
		ans = max(ans, m1[x]+m2[x]);
	}
	cout << ans << '\n';
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}

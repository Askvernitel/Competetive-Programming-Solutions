#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >>n;
	
	string s;
	cin >> s;
	int pref[n+1];
	pref[0] = 0;
	for(int i=1;i<=n;i++){
		pref[i] = pref[i-1] + (s[i-1]-48);
	}
	int suf[n+1];
	suf[n] = 0;
	for(int i=n-1;i>=0;i--){
		suf[i]=suf[i+1] + (s[i]-48);
	}
	int ans = 0;	
	int dist = n;
	map<int,set<int>> m;
	for(int i =0;i<=n;i++){
		int left = pref[i];
		int right = suf[i];
//		cout << i << " " << pref[i] << " ";
		if(i-left >= (i+1)/2 && right >= (n-i+1)/2 && min(abs(((n+1)/2)-i), abs((n)/2 -i)) <dist){
			ans = i;
			dist =min(abs(((n+1)/2)-i), abs((n)/2 -i)) ;
			//m[dist].insert(ans);
		}
	}
	cout << ans << '\n';
	//cout << *(m.begin()->second.begin()) << '\n';

}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
